
#pragma once

class TextureTile: public sf::Drawable, private sf::Transformable
{
private:
	sf::Vector2f position;
	sf::Vector2f tileSize;
	std::vector <sf::VideoMode> fullscreen_mode;
	sf::Vector2i xy;


	void load() {

		object.setPosition(0, 0);
		object.setOutlineThickness(-1);
		object.setOutlineColor(sf::Color::Green);
		object.setSize(tileSize);
		object.setFillColor(sf::Color::Color(0, 0, 0, 0));
	}

public:
	//getters and setters+
	std::vector<sf::Vector2f>& get_DATA_T_T() {
		std::vector<sf::Vector2f> data = {position, tileSize};
	}


	sf::Vector2f& get_position() {
		return position;
	}


	sf::Vector2i& get_field_size() {
		return xy;
	}


	void set_tileSize(sf::Vector2f tileSize) {
		this->tileSize = tileSize;
	}
	sf::Vector2f& get_tileSize() {
		return tileSize;
	}
	//getters and setters-
	
	//constructors and destructors+
	TextureTile() {
		fullscreen_mode = sf::VideoMode::getFullscreenModes();
		tileSize = sf::Vector2f(32, 32);
		xy = sf::Vector2i(int(fullscreen_mode[0].width / tileSize.x) * tileSize.x, int(fullscreen_mode[0].height / tileSize.y) * tileSize.y);
		load();
	}
	~TextureTile() {}
	//constructors and destructors-


	//management methods+
	void up() {
		if (object.getPosition().y > 0) {
			object.move(0, -tileSize.y);
		}
	}
	void down() {
		if (object.getPosition().y < xy.y) {
			object.move(0, tileSize.y);
		}
	}
	void left() {
		if (object.getPosition().x > 0) {
			object.move(-tileSize.x, 0);
		}
	}
	void right() {
		if (object.getPosition().x < xy.x-32) {
			object.move(tileSize.x, 0);
		}
	}
	void updating_the_mouse_position() {
		position = sf::Vector2f(sf::Mouse::getPosition());
		object.setPosition(int(position.x / tileSize.x) * tileSize.x, int(position.y / tileSize.y) * tileSize.y);
	}
	//management methods-

private:
	sf::RectangleShape object;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}
};                                                                                                                                                                                                                                                                                               