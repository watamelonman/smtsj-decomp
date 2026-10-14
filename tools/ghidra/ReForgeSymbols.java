// Headless PRE-script: apply dsd's symbols.txt (names + ARM/Thumb mode via the TMode context
// register) before auto-analysis, so Ghidra's functions agree with the delinker.
// @category re-forge
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.math.BigInteger;
import java.nio.file.*;
import java.util.regex.*;

public class ReForgeSymbols extends GhidraScript {
    void importSymbols(String path) throws Exception {
        Pattern p = Pattern.compile("^(\\S+) kind:function\\((arm|thumb),size=(0x[0-9a-f]+)[^)]*\\) addr:(0x[0-9a-f]+)");
        Register tmode = currentProgram.getRegister("TMode");
        int n = 0;
        for (String line : Files.readAllLines(Paths.get(path))) {
            Matcher m = p.matcher(line);
            if (!m.find()) continue;
            Address a = toAddr(Long.decode(m.group(4)));
            if (!currentProgram.getMemory().contains(a)) continue;
            boolean thumb = m.group(2).equals("thumb");
            long size = Long.decode(m.group(3));
            if (tmode != null) {
                Address e = a.add(Math.max(size, 2) - 1);
                try {
                    currentProgram.getProgramContext().setValue(tmode, a, e, BigInteger.valueOf(thumb ? 1 : 0));
                } catch (ghidra.program.model.listing.ContextChangeException ex) {
                    clearListing(a, e);
                    currentProgram.getProgramContext().setValue(tmode, a, e, BigInteger.valueOf(thumb ? 1 : 0));
                }
            }
            disassemble(a);
            Function f = getFunctionAt(a);
            if (f == null) f = createFunction(a, m.group(1));
            else f.setName(m.group(1), SourceType.IMPORTED);
            n++;
        }
        println("re-forge: applied " + n + " dsd function symbols");
    }

    @Override
    public void run() throws Exception {
        String syms = System.getenv("REFORGE_SYMBOLS");
        if (syms == null || syms.isEmpty()) { println("re-forge: REFORGE_SYMBOLS unset, skipping"); return; }
        importSymbols(syms);
    }
}
