package show;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class ShoppingCart extends HttpServlet {
	public void doPost(HttpServletRequest req,HttpServletResponse res) throws ServletException ,IOException{

		//取得Session对象
		//如果Session不存在，为本次会话创建此对象
		HttpSession session =req.getSession(true);
		Integer itemCount=(Integer)session.getAttribute("itemCount");
		//如果session是新的
		if (itemCount==null)
			itemCount=new Integer(0);

		PrintWriter out=res.getWriter();
		res.setContentType("text/html");

		//接收传来的参数
		String[] itemsSelected;
		String itemName;
		itemsSelected=req.getParameterValues("item");
		session.setAttribute("ItemList",itemsSelected);
		if(itemsSelected !=null){
			for(int i=0;i<itemsSelected.length;i++){
				itemName=itemsSelected[i];
				System.out.println(itemName);
				itemCount=new Integer(itemCount.intValue()+1);
				//购买的条目
				session.setAttribute("item"+itemCount,itemName);
				//总条目
				session.setAttribute("itemCount",itemCount);
			}
			res.sendRedirect("/ex5/ShowCart.jsp");
		}
	}
}