#pragma once
class DataBase
{
	std::fstream file;
	std::string dataBase[3];

	sf::Vector2i capacity; //the number of tiles that fit on the coordinate axes
public:

	/*void fill_with_tiles(int tile_id) {
		file.open(dataBase[0], std::ios::in);
		file << capacity.x << std::endl
			<< capacity.y << std::endl;
		for (int i = 0; i < capacity.y; i++) {
			for (int ii = 0; ii < capacity.x; ii++) {
				file << ii << ' ' << i << 

			}
		}
	}*/

	//getters and setters+
	const std::string* get_NameDB() const {
		return dataBase;
	}
	void set_NameDB(std::string& file_0, std::string& file_1, std::string& file_2) {
		dataBase[0] = file_0;
		dataBase[1] = file_1;
		dataBase[2] = file_2;
	}
	//getters and setters-
	

	//constructors and destructors+
	DataBase(SelectArea* cl_0, TextureTile* cl_1) {
		dataBase[0] = "db_map.txt";
		dataBase[1] = "db_change.txt";
		dataBase[0] = "db_save_last_version.txt";
	}
	~DataBase() {}
	//constructors and destructors-

};

