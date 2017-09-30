package kz.news.dto;

import kz.news.util.ArticleHelper;

public class ArticleDTO {

	private Long id;
	private String title;
	private String content;
	private String subURL;
	
	
	public ArticleDTO(Long id, String title, String content) {
		this.id = id;
		this.title = title;
		this.content = content;
		
		setSubURL(ArticleHelper.slugify(title) + "-" + id);
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public String getSubURL() {
		return subURL;
	}

	public void setSubURL(String subURL) {
		this.subURL = subURL;
	}
	
}
