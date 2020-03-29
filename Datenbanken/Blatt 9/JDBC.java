import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBC {
	public static void main(String[] args) {

		try {
			DriverManager.registerDriver(new oracle.jdbc.OracleDriver());
			Connection con = DriverManager.getConnection(
					"jdbc:oracle:thin:@oracle-srv.edvsz.hs-osnabrueck.de:1521/"
					+ "oraclestud", "htapken", "htapken");
			con.setAutoCommit(false);
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery("Select * from abteilung");
		//	ResultSet rs = stmt.executeQuery("drop table angestellter cascade constraints");
			while (rs.next()){
				
				System.out.println(rs.getString(1));
			}
			rs.close();
			stmt.close();
			con.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}
}
