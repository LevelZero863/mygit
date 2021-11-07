import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
/** 
 * 
 * @author Ethan
        * @date 2021/11/6 3:51 下午
        * @param null 

        */

public class SelectBeerServlet extends HttpServlet {
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {
        String colorParam = request.getParameter("color");
        if (colorParam.equals("brown")) {
            response.sendRedirect("http://localhost:8080/ex1/showbrown.do");
        } else if (colorParam.equals("dark")) {
            RequestDispatcher view = request.getRequestDispatcher("/showdark.do");
            view.forward(request,response);
        }
        PrintWriter out = response.getWriter();
        out.println("<html> " + "<body>"
                + "<h1 align=center>Beer Color</h1>" + "<br>"
                + "My selected beer color is: " + colorParam + "</body>" + "</html>");
    }
}
