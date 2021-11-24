<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="java.util.*"%>
<%@ taglib prefix="myTag" tagdir="/WEB-INF/tags" %>
<html>
<body>
<h1 align="center">Beer Recommendations <myTag:Header subTitle="${color}"></myTag:Header> beers
</h1>
<p>
<%--<%--%>
<%--	List styles = (List) request.getAttribute("styles");--%>
<%--	Iterator it = styles.iterator();--%>
<%--	while (it.hasNext()) {--%>
<%--		out.print("<br>try: " + it.next());--%>
<%--	}--%>
<%--%>--%>
<c:forEach var="style" items="${requestScope.styles}">
    <br>try:
    <c:out value="${style}"></c:out>
    </c:forEach>
</body>
</html>