#pragma once
class TextureTile: public sf::Drawable, public sf::Transformable
{
private:
	std::string dataBase[3];
	sf::Vector2f tileSize;
	std::vector <sf::VideoMode> fullscreen_mode;
	int width;
	int height;

public:
	//bool write_changes();
	//bool save_changes();
	//bool save_last_normal_version;
	const std::string* get_NameDB() const {
		return dataBase;
	}
	bool set_NameDB(std::string & file_0, std::string& file_1, std::string& file_2) {
		dataBase[0] = file_0;
		dataBase[1] = file_1;
		dataBase[2] = file_2;
		return true;
	}

	
	TextureTile() {
		fullscreen_mode = sf::VideoMode::getFullscreenModes();
		dataBase[0] = "db_map.txt"; 
		dataBase[1] = "db_change.txt";
		dataBase[0] = "db_save_last_version.txt";
		tileSize = sf::Vector2f(32, 32);
		width = fullscreen_mode[0].width;
		height = fullscreen_mode[0].height;
		load();
	}
	~TextureTile() {}


	bool load() {
	
		m_rectangle.setPosition(0, 0);
		m_rectangle_.setOutlineThickness(-1);
		m_rectangle_.setOutlineColor(sf::Color::Green);
		m_rectangle_.setSize(tileSize);
		m_rectangle_.setFillColor(sf::Color::Color(0, 0, 0, 255));
		return 1;
	}
	void up() {
		m_rectangle.move(0, -32);
	}
	void down() {
		m_rectangle.move(0, 32);
	}
	void left() {
		m_rectangle.move(-32, 0);
	}
	void right() {
		m_rectangle.move(32, 0);
	}
private:
	sf::RectangleShape::Transformable m_rectangle;
	sf::RectangleShape m_rectangle_;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= m_rectangle.getTransform();
		// You can draw other high-level objects
		target.draw(m_rectangle_, states);
	}
};

