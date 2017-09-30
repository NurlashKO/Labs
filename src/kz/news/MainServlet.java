package kz.news;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kz.news.dao.ArticleDao;
import kz.news.dto.ArticleDTO;

@WebServlet("/")
public class MainServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public MainServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		List<ArticleDTO> top10NewsList = ArticleDao.getInstance().getTop10News(); 
		
		request.setAttribute("top10NewsList", top10NewsList);
		
		
		request.getRequestDispatcher("WEB-INF/index.jsp").forward(request, response);
	}

}
