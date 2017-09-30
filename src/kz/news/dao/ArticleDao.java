package kz.news.dao;

import java.util.ArrayList;
import java.util.List;

import kz.news.dto.ArticleDTO;

public class ArticleDao {

	private ArticleDao() {}
	
	static ArticleDao instance;
	
	public static ArticleDao getInstance() {
		if (instance == null) {
			instance = new ArticleDao();
		}
		return instance;
	}
	
	public List<ArticleDTO> getTop10News() {
		List<ArticleDTO> resultList = new ArrayList<>();
	
		resultList.add(new ArticleDTO(1L, 
				"\"Отправили здоровых детей, а вышло так\". Пережившие аварию в Турции казахстанцы вернулись домой\r\n", 
				"Рейсом Turkish Airlines из Антальи через Стамбул четверо граждан РК, пострадавших в ДТП, в сопровождении медиков и трех родственников приземлились в аэропорту в 5.25. Прямо с самолета их забрали несколько карет скорой помощи и увезли в алматинскую областную клиническую больницу. Все четверо казахстанцев - лежачие.\r\n"
				));

		
		resultList.add(new ArticleDTO(2L, 
				"\"Тур Алматы\". В южной столице стартует зрелищное спортивное мероприятие\r\n",
				"В этом году велогонка впервые состоится в два дня - 30 сентября и 1 октября. До этого она проводилась в формате \"однодневки\" с категорией 1.1. Теперь в календаре Международного союза велосипедистов (UCI) \"Тур Алматы\" имеет маркировку 2.1.\r\n"));
		
		return resultList;
	}
	
}
