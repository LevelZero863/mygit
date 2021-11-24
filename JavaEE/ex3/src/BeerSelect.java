import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.SQLException;
import java.util.*;

public class BeerSelect extends HttpServlet {
	public void doPost(HttpServletRequest request, HttpServletResponse response)
		throws IOException, ServletException {
		String c = request.getParameter("color");
		BeerExpert be = new BeerExpert();
		List result = null;
		try {
			result = be.getBrands(c);
			System.out.println(result.get(0));
		} catch (SQLException e) {
			e.printStackTrace();
		}
		request.setAttribute("styles", result);
		request.setAttribute("color",request.getParameter("color"));
		RequestDispatcher view =
			request.getRequestDispatcher("result.jsp");
		view.forward(request, response);
	}
}