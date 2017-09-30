package kz.news;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kz.news.exceptions.ArticleNotFoundException;
import kz.news.util.ArticleHelper;

@WebServlet("/article/*")
public class ArticleServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public ArticleServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			Long articleId = getArticleIdFromURL(request.getRequestURL().toString());
			
			
			
			
			request.getRequestDispatcher("WEB-INF/article.jsp").forward(request, response);
			
			
			System.out.println("Article id is " + articleId);
		} catch (ArticleNotFoundException e) {
			ArticleHelper.respond404(response);
		}
		
		
	}

	private Long getArticleIdFromURL(String url) throws ArticleNotFoundException {
		int _index = url.lastIndexOf("-");
		
		if (_index > -1) {
			String idStr = url.substring(_index + 1);
			
			try {
				return Long.parseLong(idStr);
			} catch (NumberFormatException e) {
				throw new ArticleNotFoundException(idStr);
			}
	
		} 
		
		throw new ArticleNotFoundException(url);

	}
	
}
