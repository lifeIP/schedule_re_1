#pragma once
class SelectArea: public sf::Drawable, private sf::Transformable
{
	TextureTile* tile;
	sf::Vector2f position;//point B
	sf::Vector2f pos;//point A
	sf::Vector2f tileSize;
	sf::Vector2f difference;
	sf::Vector2f stsa;//temporary variable for intermediate size storage

	void load() {
		object.setOutlineThickness(-1);
		object.setOutlineColor(sf::Color::Red);
		object.setSize(tileSize);
		object.setFillColor(sf::Color::Color(0, 0, 0, 0));
	}
public:

	//getters and setters+
	std::vector<sf::Vector2f>& get_DATA_S_A() {
		std::vector<sf::Vector2f> data = { pos, position, tileSize};
	}
	//getters and setters-


	//constructors and destructors+
	SelectArea(TextureTile* tile) {
		this->tile = tile;
		tileSize = tile->get_tileSize();
		load();
	}
	~SelectArea() {}

	//constructors and destructors-


	void update_selected_area() {
		stsa = tileSize;
		pos = tile->get_position();
		object.setPosition(int(pos.x / tileSize.x) * tileSize.x, int(pos.y / tileSize.y) * tileSize.y);
		position = sf::Vector2f(sf::Mouse::getPosition());
		difference.x = int((position.x - pos.x) / tileSize.x) * tileSize.x;
		difference.y = int((position.y - pos.y) / tileSize.y) * tileSize.y;

		if (difference.x == 0) {
			object.setSize(stsa);
		}
		else {
			object.setSize(sf::Vector2f(difference.x, stsa.y));
			stsa.x = difference.x;
		}

		if (difference.y == 0) {
			object.setSize(stsa);
		}
		else {
			object.setSize(sf::Vector2f(stsa.x, difference.y));
			stsa.y = difference.y;
		}
	}

private:
	sf::RectangleShape object;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}
};

