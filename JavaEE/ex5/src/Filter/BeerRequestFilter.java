package Filter;

import java.io.IOException;
import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class BeerRequestFilter implements Filter {

	private static int nCount = 0;
	FilterConfig config = null;

	public void init(FilterConfig config) throws ServletException {
		this.config = config;
	}

	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain filterChain) throws IOException, ServletException {
		HttpServletRequest httpServletRequest = (HttpServletRequest) request;
		String model = httpServletRequest.getMethod();
		String serverpath = httpServletRequest.getServletPath();
		if(model.equals("GET") && !serverpath.equals("/SelectBeer.jsp")){
			HttpServletResponse response1 = (HttpServletResponse) response;
			response1.sendRedirect("/ex5/SelectBeer.jsp");
		}
		filterChain.doFilter(request,response);

	}

	public void destroy() {
		this.config = null;
	}

}
