import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
/** 
 * 
 * @author Ethan
        * @date 2021/11/6 3:51 下午
        * @param null 

        */

public class ShowDarkBeer extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        PrintWriter out = resp.getWriter();
        String colorParam = "black";
        out.println("<html> " + "<body>"
                + "<h1 align=center>Beer Color</h1>" + "<br>"
                + "My selected beer color is: " + colorParam + "</body>" + "</html>");
    }
}
