package kratoffelverwaltungssystem;

public enum Command {
    ADD_POTATO("Kartoffeln einlagern"),
    MOVE_POTATO("Kartoffeln umlagern"),
    INFO("Bestandsübersicht anzeigen"),
    REMOVE("Für Produktion entnehmen"),
    EXIT("Beenden");

    public final String description;

    Command(String description){
        this.description = description;
    }
}
