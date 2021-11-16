import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ShowBrownBeer extends HttpServlet {

	/**
	 * The doGet method implements the request and response between browser and
	 * server
	 * 
	 * @param request
	 *            the browser request
	 * @param response
	 *            the server response
	 * 
	 * @throws IOException
	 *             if there are errors from the input
	 * 
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		response.setContentType("text/html");
		request.setCharacterEncoding("utf-8");
		request.setAttribute("color","brown");
		request.getRequestDispatcher("displayitem").forward(request,response);
	}
}
