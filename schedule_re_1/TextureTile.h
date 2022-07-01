
#pragma once

class TextureTile: public sf::Drawable, public sf::Transformable
{
private:
	static sf::Vector2i position;
	std::string dataBase[3];
	sf::Vector2f tileSize;
	std::vector <sf::VideoMode> fullscreen_mode;
	int width;
	int height;
	//sf::Vector2i position;
public:
	//bool write_changes();
	//bool save_changes();
	//bool save_last_normal_version;
	const std::string* get_NameDB() const {
		return dataBase;
	}
	void set_NameDB(std::string & file_0, std::string& file_1, std::string& file_2) {
		dataBase[0] = file_0;
		dataBase[1] = file_1;
		dataBase[2] = file_2;
	}

	
	TextureTile() {
		fullscreen_mode = sf::VideoMode::getFullscreenModes();
		dataBase[0] = "db_map.txt"; 
		dataBase[1] = "db_change.txt";
		dataBase[0] = "db_save_last_version.txt";
		tileSize = sf::Vector2f(32, 32);
		width = int(fullscreen_mode[0].width/32)*32;
		height = int(fullscreen_mode[0].height/32)*32;
		load();
	}
	~TextureTile() {}


	void load() {
	
		object.setPosition(0, 0);
		object.setOutlineThickness(-1);
		object.setOutlineColor(sf::Color::Green);
		object.setSize(tileSize);
		object.setFillColor(sf::Color::Color(0, 0, 0, 255));
	}
	void up() {
		if (object.getPosition().y > 0) {
			object.move(0, -32);
		}
	}
	void down() {
		if (object.getPosition().y < height) {
			object.move(0, 32);
		}
	}
	void left() {
		if (object.getPosition().x > 0) {
			object.move(-32, 0);
		}
	}
	void right() {
		if (object.getPosition().x < width-32) {
			object.move(32, 0);
		}
	}
	void updating_the_mouse_position() {
		position = sf::Mouse::getPosition();
		std::cout << position.x << std::endl << position.y << std::endl;
		object.setPosition(0, 0);
		object.setPosition(int(position.x / 32) * 32, int(position.y / 32) * 32);
	}
private:
	//sf::RectangleShape::Transformable m_rectangle;
	sf::RectangleShape object;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		//states.transform *= m_rectangle.getTransform();
		// You can draw other high-level objects
		target.draw(object, states);
	}
};                                                                                                                                                                                                                                                                                               