"""Make a forge worktree buildable: its git-ignored inputs (tools, extract/, ROM-derived
files) live only in the main checkout, so symlink them in and generate build.ninja."""
import os, pathlib, subprocess

SHARED = ["dsd", "objdiff-cli", "tools/wibo", "tools/mwccarm", "extract"]


def ensure():
    common = subprocess.run(["git", "rev-parse", "--path-format=absolute", "--git-common-dir"],
                            capture_output=True, text=True).stdout.strip()
    main = pathlib.Path(common).parent if common else None
    here = pathlib.Path.cwd().resolve()
    if main and main.resolve() != here:
        for rel in SHARED:
            src, dst = main / rel, here / rel
            if src.exists() and not os.path.lexists(dst):
                dst.parent.mkdir(parents=True, exist_ok=True)
                dst.symlink_to(src)
    if not pathlib.Path("build.ninja").exists():
        subprocess.run(["python3", "configure.py"], check=True, capture_output=True)
