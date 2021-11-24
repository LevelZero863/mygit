package javaEE.ex3.model;
import java.sql.*;

public class AccessJDBCUtil {
    public static Connection getAccessDBConnection() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver"); //mysql可以省
            String url = "jdbc:mysql://localhost:3306/test";
            String user = "root";
            String password = "gaoyinghao2021";

            Connection conn = DriverManager.getConnection(url,user,password);
            return conn;
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }  
}