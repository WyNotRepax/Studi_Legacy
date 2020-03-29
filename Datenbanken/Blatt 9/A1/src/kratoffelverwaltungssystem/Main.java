package kratoffelverwaltungssystem;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {

    public static final String URL = "jdbc:oracle:thin:@oracle-srv.edvsz.hs-osnabrueck.de:1521/oraclestud";

    public static void main(String[] args) {
        registerDriver();
        IO.printWelcome();
        String username, password;
        do {
            username = IO.getUserName();
            password = IO.getPassword();
        } while (!connect(username, password));
    }

    public static void registerDriver() {
        try {
            DriverManager.registerDriver(new oracle.jdbc.OracleDriver());
        } catch (SQLException e) {
            throw new RuntimeException(String.format("Could not Register Driver: %s", e.getMessage()));
        }
    }

    public static boolean connect(String username, String password) {
        try (Connection con = DriverManager.getConnection(URL, username, password)) {
            Command cmd;
            do {
                cmd = IO.selectCommand();
            }
            while (Control.execCommand(cmd,con));
        } catch (SQLException e) {
            if (e.getErrorCode() == 1017) {
                System.err.printf("Invalid username/password!\n");
                return false;
            }
            System.err.printf("Connection to database failed:%s\n", e.getMessage());
        }
        return true;
    }

}
