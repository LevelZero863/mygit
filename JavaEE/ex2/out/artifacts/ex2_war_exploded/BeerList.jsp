<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<% 
	String color = request.getParameter("color");
	Integer colorCount = (Integer) session.getAttribute("colorCount");
	if (colorCount == null) colorCount = 0;

	String[] colorSelected;
	String color1;
	colorSelected = request.getParameterValues("color");
	if (colorSelected != null) {
		for (int i = 0; i < colorSelected.length; i++) {
			color1 = colorSelected[i];
			colorCount = colorCount.intValue()+1;
			session.setAttribute("color"+colorCount,color1);
			session.setAttribute("colorCount",colorCount);
		}
	}
%>
<jsp:useBean id="beer1" class="package2.Beer" scope="session">
	<jsp:setProperty name="beer1" property="color" value="amber"/>
</jsp:useBean>
<jsp:useBean id="beer2" class="package2.Beer" scope="session">
	<jsp:setProperty name="beer2" property="color" value="brown"/>
</jsp:useBean>
<jsp:useBean id="beer3" class="package2.Beer" scope="session">
	<jsp:setProperty name="beer3" property="color" value="dark"/>
</jsp:useBean>
<%
	if(color.equals(beer1.getColor())){
%>
	<!--if use this statement:response.sendRedirect("ShowAmberBeer.jsp") the result is? -->;
	<jsp:forward page="ShowAmberBeer.jsp" />
<%	}
	if(color.equals(beer2.getColor())){
		response.sendRedirect("ShowBrownBeer");
	}
	if(color.equals(beer3.getColor())){
	    RequestDispatcher view = request.getRequestDispatcher("ShowDarkBeer");
	    view.forward(request, response);
	}
%>
<jsp:include page="Header_act.jsp">
	<jsp:param name="subTitle" value="Welcome to the Light Beer World!"/>
</jsp:include>
<%@ include file="DisplayItem.jsp" %>