import javaEE.ex3.model.AccessJDBCUtil;
import java.util.*;
import java.sql.*;

public class BeerExpert {
	public List getBrands(String color) throws SQLException {
		Connection conn = AccessJDBCUtil.getAccessDBConnection();
		System.out.println(conn);
		List brands = new ArrayList();
		String sql = "select name from test.beer where color = ?";
		PreparedStatement ps = conn.prepareStatement(sql);
		if (color.equals("light")) {
			ps.setString(1,"light");
			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				brands.add(rs.getString(1));
			}
		} else if (color.equals("amber")) {
			ps.setString(1,"amber");
			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				brands.add(rs.getString(1));
			}
		} else if (color.equals("brown")) {
			ps.setString(1,"brown");
			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				brands.add(rs.getString(1));
			}
		} else {
			ps.setString(1,"dark");
			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				brands.add(rs.getString(1));
			}
		}
		return brands;
	}
}
