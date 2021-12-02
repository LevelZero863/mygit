package tags;

import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class CreateSelectTag extends TagSupport{

	public int doStartTag() throws JspException{
		try{
		    JspWriter out = pageContext.getOut();
		    StringBuilder outPrint = new StringBuilder();
		    String[] color = {"light","amber","brown","dark"};
		    outPrint.append("<select name='color' size='1'>");
			for (String s : color) {
				outPrint.append("<option>");
				outPrint.append(s);
				outPrint.append("</option>");
			}
		    outPrint.append("</select>");
		    out.print(outPrint.toString());
		} catch (java.io.IOException e) {
		    throw new JspTagException(e.getMessage());
		}
		return SKIP_BODY;
	}
}
