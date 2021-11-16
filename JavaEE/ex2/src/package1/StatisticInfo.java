package package1;

import javax.servlet.http.HttpServlet;
/** 
 * 
 * @author Ethan
        * @date 2021/11/13 10:50 上午
        * @param null 

        */

public class StatisticInfo extends HttpServlet {
    private static int count = 1;
    public static synchronized int getCount(){
        return count++;
    }
}
