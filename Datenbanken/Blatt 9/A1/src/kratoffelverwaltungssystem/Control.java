package kratoffelverwaltungssystem;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class Control {

    private static final String ADDPOTATOQUERY = "INSERT INTO Gebinde (ID,Sorte,Groesse,Gewicht,Staerkegehalt,Fleckigkeit,Ort_ID) VALUES (%d,%s,%f,%f,%f,%d)";

    public static boolean execCommand(Command cmd, Connection con) {
        switch (cmd) {
            case ADD_POTATO:
                addPotato(con);
                return true;
            case MOVE_POTATO:

                return true;
            case INFO:

                return true;
            case REMOVE:

                return true;
            case EXIT:
            default:
                return false;
        }
    }



    public static void addPotato(Connection con) {

        int id = IO.getID();
        String sorte = IO.getSorte();
        Float size = IO.getSize();
        Float weight = IO.getWeight();
        float starch = IO.getStarch();
        float spottiness = IO.getSpottiness();
        int ortId = IO.getOrtID();

        try(Statement statement = con.createStatement()) {
            String sql = String.format(ADDPOTATOQUERY,id,sorte,size,weight,starch,spottiness,ortId);
            statement.execute(sql);
        }catch (SQLException e){
            System.err.printf("Could not create Statement: %s\n",e.getMessage());
        }

    }
}

