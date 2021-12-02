package Filter;

import javax.servlet.*;
import java.io.*;
/**
 * ������ı�ת���ɴ�д�Ĺ�����
 */
public class UpperCaseFilter
        implements Filter
{
    public void init(FilterConfig config)
        throws ServletException
    {
    }
    public void destroy()
    {
    }
    public void doFilter(ServletRequest request,
                         ServletResponse response,
                         FilterChain chain)
        throws ServletException, IOException
    {
        request.setAttribute("alert","This is an included section!");
        chain.doFilter(request, response);
    }
}
