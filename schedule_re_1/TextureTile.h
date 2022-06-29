                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 #pragma once
class TextureTile: public sf::Drawable, public sf::Transformable
{
private:
	std::string dataBase[3];
	sf::Vector2f tileSize;
	std::vector <sf::VideoMode> fullscreen_mode;
	int width;
	int height;
	sf::Vector2i position;
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
	
		m_rectangle_.setPosition(0, 0);
		m_rectangle_.setOutlineThickness(-1);
		m_rectangle_.setOutlineColor(sf::Color::Green);
		m_rectangle_.setSize(tileSize);
		m_rectangle_.setFillColor(sf::Color::Color(0, 0, 0, 255));
	}
	void up() {
		if (m_rectangle_.getPosition().y > 0) {
			m_rectangle_.move(0, -32);
		}
	}
	void down() {
		if (m_rectangle_.getPosition().y < height) {
			m_rectangle_.move(0, 32);
		}
	}
	void left() {
		if (m_rectangle_.getPosition().x > 0) {
			m_rectangle_.move(-32, 0);
		}
	}
	void right() {
		if (m_rectangle_.getPosition().x < width-32) {
			m_rectangle_.move(32, 0);
		}
	}
	void h() {
		//position = sf::Mouse::getPosition();//Development has been stopped in order to learn multithreaded programming.
	}
	void updating_the_mouse_position() {
		position = sf::Mouse::getPosition();
		std::cout << position.x << std::endl << position.y << std::endl;
		m_rectangle.setPosition(0, 0);
		m_rectangle_.setPosition(int(position.x / 32) * 32, int(position.y / 32) * 32);
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