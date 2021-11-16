
import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
/** 
 * 
 * @author Ethan
        * @date 2021/11/13 10:50 上午
        * @param null 

        */

public class BeerAddedListener implements HttpSessionAttributeListener {
    @Override
    public void attributeAdded(HttpSessionBindingEvent se) {
        String name = se.getName();
        Pattern pattern = Pattern.compile("^item[1-9]$");
        Matcher matcher = pattern.matcher(name);
        if (matcher.find()) {
            Object value = se.getValue();
            int count = (Integer) se.getSession().getAttribute("itemCount")+1;
            System.out.println("Attribute added " +name+ ":"+value+"     itemCount:"+count);
        }

    }
}
