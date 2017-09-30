package kz.news.exceptions;

public class ArticleNotFoundException extends Exception {

	
	public ArticleNotFoundException(String id) {
		super("Article not found with id " + id);
	}
	
	public ArticleNotFoundException(Long id) {
		super("Article not found with id " + id);
	}
	
}
