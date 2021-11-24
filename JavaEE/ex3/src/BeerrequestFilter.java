import javax.servlet.*;
import java.io.IOException;

public class BeerrequestFilter implements Filter {
    private FilterConfig fc;
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        fc = filterConfig;
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        String color = servletRequest.getParameter("color");
        if (color.equals("light")||color.equals("amber")||color.equals("brown")||color.equals("dark")) {
            filterChain.doFilter(servletRequest,servletResponse);
        } else {
            servletRequest.getRequestDispatcher("/msg.jsp").forward(servletRequest,servletResponse);
        }
    }

    @Override
    public void destroy() {
       // Filter.super.destroy();
    }
}
