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
	void save(const std::string& filename, int tile_id) {
		std::fstream file;
		file.open(filename, std::ios::app);
		int x = std::abs(position.x - pos.x) / tileSize.x;
		int y = std::abs(position.y - pos.y) / tileSize.y;
		int posx_a = int(pos.x / tileSize.x) * tileSize.x;
		int posy_a = int(pos.y / tileSize.y) * tileSize.y;
		int posx_b = int(position.x / tileSize.x) * tileSize.x;
		int posy_b = int(position.y / tileSize.y) * tileSize.y;
		
		if (posx_a < posx_b && posy_a < posy_b) {
			for (int i = 0; i <= y; i++) {
				for (int j = 0; j <= x; j++) {
					file << posx_a + j * tileSize.x 
						<< ' ' << posy_a + i * tileSize.y
						<< std::endl;
				}
			}
		}
		else if (posx_a > posx_b && posy_a > posy_b) {
			for (int i = y; i > 0; i--) {
				for (int j = x; j > 0; j--) {
					file << posx_a - j * tileSize.x
						<< ' ' << posy_a - i * tileSize.y
						<< std::endl;
				}
			}
		}
		else if (posx_a == posx_b && posy_a == posy_b) {
			file << posx_a << ' ' << posy_a
				<< std::endl;
		}
		else if (posx_a > posx_b && posy_a < posy_b) {
			for (int i = 0; i <= y; i++) {
				for (int j = x; j > 0; j--) {
					file << posx_a - j * tileSize.x
						<< ' ' << posy_a + i * tileSize.y
						<< std::endl;
				}
			}
		}
		else if (posx_a < posx_b && posy_a > posy_b) {
			for (int i = y; i > 0; i--) {
				for (int j = 0; j <= x; j++) {
					file << posx_a + j * tileSize.x
						<< ' ' << posy_a - i * tileSize.y
						<< std::endl;
				}
			}
		}
		else if (posx_a > posx_b && posy_a == posy_b) {
			for (int j = x; j > 0; j--) {
				file << posx_a - j * tileSize.x
					<< ' ' << posy_a
					<< std::endl;
			}
		}
		else if (posx_a < posx_b && posy_a == posy_b) {
			for (int j = 0; j <= x; j++) {
				file << posx_a + j * tileSize.x
					<< ' ' << posy_a
					<< std::endl;
			}
		}
		else if (posx_a == posx_b && posy_a > posy_b) {
			for (int i = y; i > 0; i--) {
				file << posx_a
					<< ' ' << posy_a - i * tileSize.y
					<< std::endl;
			}
		}
		else if (posx_a == posx_b && posy_a < posy_b) {
			for (int i = 0; i <= y; i++) {
				file << posx_a
					<< ' ' << posy_a + i * tileSize.y
					<< std::endl;
			}
		}


		file.close();
	}

	//getters and setters+
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
			if (difference.x < 0) {
				stsa.x = difference.x;
			}
			else {
				stsa.x = difference.x + tileSize.x;
			}
			object.setSize(sf::Vector2f(difference.x, stsa.y));
		}

		if (difference.y == 0) {
			object.setSize(stsa);
		}
		else {
			stsa.y = difference.y;
			if (difference.y < 0) {
				object.setSize(sf::Vector2f(stsa.x, difference.y));
			}
			else {
				object.setSize(sf::Vector2f(stsa.x, difference.y + tileSize.y));
			}
		}
	}

private:
	sf::RectangleShape object;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}
};

