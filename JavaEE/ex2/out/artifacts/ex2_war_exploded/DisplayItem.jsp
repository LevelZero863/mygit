<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Beer List</title>
</head>
<body>
<!-- Get the value of the variable "color"  -->
<%--&lt;%&ndash;%>

<%--${color}--%>
<%--<%=request.getAttribute(color)%>--%>
<%
//  String colorParam =(String) request.getAttribute(color);
    String colorParam = request.getParameter("color");
    if (colorParam == null) {
%>
    <jsp:include page="Header_act.jsp">
      <jsp:param name="subTitle" value="Welcome to the Brown Beer World!"/>
    </jsp:include>
<%
    } else if (colorParam.equals("dark")) {
%>

    <jsp:include page="Header_act.jsp">
      <jsp:param name="subTitle" value="Welcome to the Dark Beer World!"/>
    </jsp:include>
<%
    }
%>

<h1 align="center">A Beer List of the color you selected</h1>
<hr>
<b>
<%
	out.println("You hava selected the "+colorParam+" Beer");
%>
</b>
<p><b>Choose following information:</b></p>
<form method="post" action="ShoppingCart.do">
  <table width="500" border="0" cellspacing="0" cellpadding="0">
    <tr> 
      <td width="69"> 
        <input type="checkbox" name="item" value="The light beer of China">
      </td>
      <td width="431">Item1: The light beer of China</td>
    </tr>
    <tr> 
      <td width="69">
        <input type="checkbox" name="item" value="The amber beer of China">
      </td>
      <td width="431">Item2: The amber beer of China</td>
    </tr>
    <tr> 
      <td width="69">
        <input type="checkbox" name="item" value="The beer of American">
      </td>
      <td width="431">Item3: The beer of American</td>
    </tr>
  </table>
  <hr>
  <p>
  <div style="text-align: center;">
    <input type="submit" name="btn_submit" value="Buy Now">
  </div>
</form>
</body>
</html>