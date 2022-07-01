
#pragma once

class TextureTile: public sf::Drawable, public sf::Transformable
{
private:
	sf::Vector2i position;
	std::string dataBase[3];
	sf::Vector2f tileSize;
	std::vector <sf::VideoMode> fullscreen_mode;
	sf::Vector2i xy;


	void load() {

		object.setPosition(0, 0);
		object.setOutlineThickness(-1);
		object.setOutlineColor(sf::Color::Green);
		object.setSize(tileSize);
		object.setFillColor(sf::Color::Color(0, 0, 0, 255));
	}

public:
	//getters and setters+
	sf::Vector2i& get_position() {
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


	const std::string* get_NameDB() const {
		return dataBase;
	}
	void set_NameDB(std::string & file_0, std::string& file_1, std::string& file_2) {
		dataBase[0] = file_0;
		dataBase[1] = file_1;
		dataBase[2] = file_2;
	}
	//getters and setters-
	
	//constructors and destructors+
	TextureTile() {
		fullscreen_mode = sf::VideoMode::getFullscreenModes();
		dataBase[0] = "db_map.txt"; 
		dataBase[1] = "db_change.txt";
		dataBase[0] = "db_save_last_version.txt";
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
		position = sf::Mouse::getPosition();
		std::cout << position.x << std::endl << position.y << std::endl;
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