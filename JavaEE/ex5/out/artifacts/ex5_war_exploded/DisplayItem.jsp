<%@ page import="java.util.List" %>
<%@ page contentType="text/html; charset=ISO-8859-1"
         pageEncoding="ISO-8859-1"%>
<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<%@ page isELIgnored="false" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Beer List</title>
</head>
<body>
<c:set var="sessionList" scope="session" value="${sessionList}, ${param.color} " />
<h1 align="center">The beer corlor that you selected is ${param.color}.</h1>
<b><a href="SelectedBeerColor.jsp">(View the selected beer colors).</a></b>
<p><b>Choose following information:</b></p>
<form method="post" action="ShoppingCart.do">
  <table width="500" border="0" cellspacing="0" cellpadding="0">
    <% String[] itemList = {"The light beer of China","The amber beer of China","The beer of American"} ;%>
    <c:forEach var="item" items= "<%=itemList%>" varStatus="beerCount">
      <tr>
        <td width="69">
          <label>
            <input type="checkbox" name="item" value="${item}">
          </label>
        </td>
        <td width="431">Item${beerCount.count}: "${item}" </td>
      </tr>
    </c:forEach>
  </table>
  <hr>
  <p>
  <div style="text-align: center;">
    <input type="submit" name="btn_submit" value="Buy Now">
  </div>
</form>
</body>
</html>