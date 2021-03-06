import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
/** 
 * 
 * @author Ethan
        * @date 2021/11/6 3:51 下午
        * @param null 

        */

public class CodeReturn extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("application/jar");
        ServletContext ctx = getServletContext();
        InputStream is = ctx.getResourceAsStream("/bookCode.jar");
        int read =0;
        byte[] bytes = new byte[1024];
        OutputStream os = resp.getOutputStream();
        while ((read = is.read(bytes)) != -1) {
            os.write(bytes,0,read);
            os.flush();
        }
        os.close();
    }
}
