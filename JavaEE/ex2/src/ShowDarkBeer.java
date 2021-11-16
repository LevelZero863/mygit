import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ShowDarkBeer extends HttpServlet {

	/**
	 * The doPost method implements the request and response between browser and 
	 * server
	 * 
	 * @param request the browser request
	 * @param response the server response
	 * 
	 * @throws IOException if there are errors from the input
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		request.getRequestDispatcher("displayitem").forward(request,response);
	}
}
