package tags;

import java.io.IOException;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class CreateSelectTag extends SimpleTagSupport {

	public void doTag() throws JspException, IOException {
		JspWriter out = getJspContext().getOut();
		StringBuilder outPrint = new StringBuilder();
		String[] color = { "light", "amber", "brown", "dark" };
		outPrint.append("<select name='color' size='1'>");
		for (String s : color) {
			outPrint.append("<option>");
			outPrint.append(s);
			outPrint.append("</option>");
		}
		outPrint.append("</select>");
		out.print(outPrint.toString());
	}
}
