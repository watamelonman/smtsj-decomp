// Headless post-script (Java, so it works on Ghidra 11 and 12 without Jython/PyGhidra).
// @category re-forge
// Exports $REFORGE_OUT/functions.json: name, addr, size, thumb, suggested name (from
//    referenced debug strings like "BattleTask.c"), strings, callers, callees, decompiled C.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.StringDataInstance;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class ReForgeExport extends GhidraScript {
    static String esc(String s) {
        StringBuilder b = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '"' || c == '\\') b.append('\\').append(c);
            else if (c < 0x20) b.append(String.format("\\u%04x", (int) c));
            else b.append(c);
        }
        return b.toString();
    }

    String readCString(Address a) throws Exception {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < 96; i++) {
            int c = getByte(a.add(i)) & 0xff;
            if (c == 0) return b.length() >= 4 ? b.toString() : null;
            if (c < 0x20 || c > 0x7e) return null;
            b.append((char) c);
        }
        return null;
    }

    @Override
    public void run() throws Exception {
        String out = Optional.ofNullable(System.getenv("REFORGE_OUT")).orElse("build/ghidra");
        new File(out).mkdirs();
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        Register tmode = currentProgram.getRegister("TMode");
        Pattern file = Pattern.compile("([A-Za-z_][A-Za-z0-9_]{2,})\\.(c|cpp)\\b");
        try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(out + "/functions.json")))) {
            w.println("[");
            boolean first = true;
            int n = 0;
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (monitor.isCancelled()) break;
                List<String> strs = new ArrayList<>();
                for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                    for (Reference r : ins.getReferencesFrom()) {
                        Data d = getDataAt(r.getToAddress());
                        // ARM loads strings through literal pools: follow one pointer level
                        if (d != null && d.isPointer() && d.getValue() instanceof Address)
                            d = getDataAt((Address) d.getValue());
                        if (d == null) {   // undefined bytes: try reading a C string directly
                            Address t = r.getToAddress();
                            try { long v = getInt(t) & 0xffffffffL; Address pa = toAddr(v);
                                  if (currentProgram.getMemory().contains(pa)) {
                                      String cs = readCString(pa);
                                      if (cs != null) { strs.add(cs); continue; } } } catch (Exception e) { }
                        }
                        if (d != null && d.hasStringValue()) strs.add(String.valueOf(d.getValue()));
                    }
                }
                String sug = "";
                for (String s : strs) { Matcher m = file.matcher(s); if (m.find()) { sug = m.group(0); break; } }
                StringBuilder callers = new StringBuilder(), callees = new StringBuilder();
                for (Function c : f.getCallingFunctions(monitor)) callers.append(callers.length() > 0 ? "\",\"" : "").append(esc(c.getName()));
                for (Function c : f.getCalledFunctions(monitor)) callees.append(callees.length() > 0 ? "\",\"" : "").append(esc(c.getName()));
                DecompileResults res = ifc.decompileFunction(f, 30, monitor);
                String c = (res != null && res.decompileCompleted()) ? res.getDecompiledFunction().getC() : "";
                if (c.length() > 6000) c = c.substring(0, 6000);
                boolean thumb = tmode != null && BigInteger.ONE.equals(
                        currentProgram.getProgramContext().getValue(tmode, f.getEntryPoint(), false));
                StringBuilder sj = new StringBuilder();
                for (int i = 0; i < Math.min(strs.size(), 8); i++) sj.append(i > 0 ? "," : "").append('"').append(esc(strs.get(i))).append('"');
                w.print((first ? "" : ",\n") + String.format(
                        "{\"name\":\"%s\",\"addr\":\"0x%08x\",\"size\":%d,\"thumb\":%b,\"source_file_hint\":\"%s\",\"suggested\":\"\",\"strings\":[%s],\"callers\":[%s],\"callees\":[%s],\"ghidra_c\":\"%s\"}",
                        esc(f.getName()), f.getEntryPoint().getOffset(), f.getBody().getNumAddresses(), thumb, esc(sug), sj,
                        callers.length() > 0 ? "\"" + callers + "\"" : "", callees.length() > 0 ? "\"" + callees + "\"" : "", esc(c)));
                first = false;
                if (++n % 500 == 0) println("re-forge: " + n + " functions exported");
            }
            w.println("\n]");
            println("re-forge: exported " + n + " functions");
        }
    }
}
