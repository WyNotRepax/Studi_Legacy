package kratoffelverwaltungssystem;

public enum OrtT {
    PRODUKTIONSLAGER(0, "Produktionslager"),
    GROSSRAUMLAGER(1, "Großraumlager");

    public final int type;
    public final String name;

    OrtT(int type, String name) {
        this.type = type;
        this.name = name;
    }
}