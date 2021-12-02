package tags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.tagext.SimpleTagSupport;
import java.io.IOException;

public class CountColor extends SimpleTagSupport {
    private  int lightCounter = 0;
    private  int amberCounter = 0;
    private  int brownCounter = 0;
    private  int darkCounter = 0;
    private String sessionList;

    public void setSessionList(String sessionList) {
        this.sessionList = sessionList;
    }
    @Override
    public void doTag() throws JspException, IOException {
        String[] colorList = sessionList.split(",");
        for (int i = 0; i < colorList.length; i++) {
            if (colorList[i].equals(" light ")) lightCounter++;
            if (colorList[i].equals(" amber ")) amberCounter++;
            if (colorList[i].equals(" brown ")) brownCounter++;
            if (colorList[i].equals(" dark ")) darkCounter++;
        }
        if (lightCounter != 0) getJspContext().getOut().println("light " +lightCounter+"<br>");
        if (brownCounter != 0) getJspContext().getOut().println("brown "+brownCounter+"<br>");
        if (amberCounter != 0) getJspContext().getOut().println("amber "+amberCounter+"<br>");
        if (darkCounter != 0) getJspContext().getOut().println("dark "+darkCounter+"<br>");
    }
}
