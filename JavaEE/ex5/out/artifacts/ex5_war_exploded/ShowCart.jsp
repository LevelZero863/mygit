<%--
  Created by IntelliJ IDEA.
  User: gaoyinghao
  Date: 2021/11/26
  Time: 4:08 下午
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>item list</title>
</head>
<body>
<h4>Session List:</h4><hr><br><br>
<c:forEach var = "item" items="${sessionScope.ItemList}">
    ${item}
    <hr>
</c:forEach>
</body>
</html>