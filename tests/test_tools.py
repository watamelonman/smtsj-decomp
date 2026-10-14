"""Self-tests for the decomp gate tools (run by the `test` gate; no game data needed)."""
import json, os, pathlib, subprocess, sys, tempfile, unittest

ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import anticheat, decompme  # noqa: E402


def scan(text, path="src/a.c"):
    return anticheat.scan((path, i + 1, l) for i, l in enumerate(text.splitlines()))


class AntiCheat(unittest.TestCase):
    def test_real_c_passes(self):
        self.assertEqual(scan("s32 addOne(s32 x) {\n    return x + 1;\n}\n"), [])

    def test_inline_asm_rejected(self):
        self.assertTrue(any(f.startswith("ASM") for f in scan('void f(void) { __asm__("nop"); }')))
        self.assertTrue(any(f.startswith("ASM") for f in scan("asm void f(void) {\n nop\n}")))

    def test_include_asm_rejected(self):
        self.assertTrue(any(f.startswith("INCASM") for f in scan('INCLUDE_ASM("asm/nonmatchings/x", f);')))

    def test_byte_blob_rejected(self):
        blob = "static const u8 code[] = {\n" + "0x27, 0xbd, 0xff, 0xf0, 0xff, 0xbf, 0x00, 0x00,\n" * 3 + "};"
        self.assertTrue(any(f.startswith("BLOB") for f in scan(blob)))

    def test_reviewed_table_allowed(self):
        t = "static const s16 kExpTable[] = { // forge:data-ok level-up table\n" + "1, 2, 3, 4, 5, 6, 7, 8,\n" * 3 + "};"
        self.assertEqual(scan(t), [])

    def test_non_source_ignored(self):
        self.assertEqual(scan('__asm__("nop")', "docs/notes.md"), [])


class DecompMe(unittest.TestCase):
    def test_payload_fields(self):
        with tempfile.TemporaryDirectory() as d:
            asm = pathlib.Path(d, "f.s"); asm.write_text("glabel f\njr $ra\nnop\n")
            p = decompme.payload("f", asm, c={"platform": "ps2", "compiler": "ee-gcc2.96",
                                              "compiler_flags": "-O2"})
        self.assertEqual(p["platform"], "ps2")
        self.assertEqual(p["diff_label"], "f")
        self.assertIn("jr $ra", p["target_asm"])

    def test_upload_needs_opt_in(self):
        env = {k: v for k, v in os.environ.items() if k != "FORGE_DECOMPME_OK"}
        with tempfile.TemporaryDirectory() as d:
            pathlib.Path(d, "config").mkdir()
            pathlib.Path(d, "config/decompme.toml").write_text('platform="ps2"\ncompiler="ee-gcc2.96"\n')
            pathlib.Path(d, "f.s").write_text("nop\n")
            r = subprocess.run([sys.executable, str(ROOT / "tools/decompme.py"), "create",
                                "--func", "f", "--asm", "f.s"], cwd=d, env=env,
                               capture_output=True, text=True)
        self.assertNotEqual(r.returncode, 0)
        self.assertIn("FORGE_DECOMPME_OK", r.stderr)


class Cards(unittest.TestCase):
    def test_cards_from_report(self):
        rep = {"units": [{"name": "src/battle/btlUnit", "measures": {"total_code": 64},
                          "functions": [{"name": "func_00195850", "size": 32, "fuzzy_match_percent": 40.0},
                                        {"name": "func_001958a0", "size": 16, "fuzzy_match_percent": 100.0}]}]}
        with tempfile.TemporaryDirectory() as d:
            pathlib.Path(d, "r.json").write_text(json.dumps(rep))
            subprocess.run([sys.executable, str(ROOT / "tools/make_cards.py"), "--report", "r.json"],
                           cwd=d, check=True, capture_output=True)
            cards = list(pathlib.Path(d, "tasks").glob("*.md"))
            self.assertEqual(len(cards), 1)
            body = cards[0].read_text()
        self.assertIn("func_00195850", body)
        self.assertNotIn("func_001958a0", body)
        self.assertIn('owns = ["src/battle/btlUnit.c"', body)


if __name__ == "__main__":
    unittest.main()
