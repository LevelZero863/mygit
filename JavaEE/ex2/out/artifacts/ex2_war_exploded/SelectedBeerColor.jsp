<%@ page import="java.nio.file.FileStore" %><%--
  Created by IntelliJ IDEA.
  User: gaoyinghao
  Date: 2021/11/11
  Time: 9:49 下午
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<jsp:useBean id="beer1" class="package2.Beer" scope="session">
    <jsp:setProperty name="beer1" property="color" value=""/>
</jsp:useBean>
<%

    Integer colorCount = (Integer) session.getAttribute("colorCount");
    if (colorCount == null) colorCount = 0;

    for (int i = 1; i <= colorCount.intValue(); i++) {
        out.println(session.getAttribute("color"+i)+"<hr>");
    }
%>
</body>
</html>
