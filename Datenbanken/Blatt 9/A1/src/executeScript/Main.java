package executeScript;


import java.io.*;
import java.net.URL;
import java.sql.*;

public class Main {
    public static final String USERNAME = "obsteinka";
    public static final String PASSWORD = "oraclesqldeveloper";
    public static final String URL = "jdbc:oracle:thin:@oracle-srv.edvsz.hs-osnabrueck.de:1521/oraclestud";
    public static final String FILEPATH = "Z:\\Studi\\Datenbanken\\Blatt 9\\skript.sql";

    public static void main(String[] args) {
        try {
            DriverManager.registerDriver(new oracle.jdbc.OracleDriver());
            try (
                    Connection con = DriverManager.getConnection(URL, USERNAME, PASSWORD);
                    FileReader fr = new FileReader(FILEPATH);
            ) {
                con.setAutoCommit(false);
                String[] commands = parseFile(fr);
                try (Statement stmt = con.createStatement()) {
                    for (String command : commands) {
                        try{
                            boolean success = stmt.execute(command);
                            System.out.printf("Command \"%s\" successfully executed:%b\n",command,success);
                        } catch (SQLException e){
                            System.err.printf("Command \"%s\" failed: %s\n",command,e.getMessage());
                        }
                    }
                } catch (SQLException e) {
                    System.err.printf("Could not create Statement: %s", e.getMessage());
                }
                try {
                    con.commit();
                } catch (SQLException e) {
                    System.err.printf("Commit Failed: %s", e.getMessage());
                }
            } catch (SQLException e) {
                System.err.printf("Connection with Database failed: %s", e.getMessage());
            } catch (FileNotFoundException e) {
                System.err.printf("File \"%s\" was not found!", FILEPATH);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static String[] parseFile(FileReader f) throws IOException {
        String s = "";
        int c;
        while ((c = f.read()) != -1) {
            s += (char) c;
        }
        return s.replaceAll("[\n\r]","").split(";");
    }
}
