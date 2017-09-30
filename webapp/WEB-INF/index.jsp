<%@page import="java.util.List"%>
<%@page import="kz.news.dto.ArticleDTO" %>    

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib prefix = "c" uri="http://java.sun.com/jsp/jstl/core"%>    
    
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
<link type="text/css" rel="stylesheet" href="public/css/main.css"></link>
</head>
<body>
	
	<%@include file="header.jsp" %>

	<div class="body">
		<table>
			<c:forEach items="${top10NewsList}" var="a">
				<tr>
					<td>
						<a target="blank" href='article/<c:out value="${a.subURL}" />'>
							<c:out value="${a.title}" />
						</a>
					</td>
				</tr>
			</c:forEach>
		</table>
	</div>

	<%@include file="footer.jsp" %>

</body>
</html>