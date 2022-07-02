#include "lib.h"
#include "object.h"

int main() {
	sf::Uint32 style = sf::Style::Fullscreen;// setting the window style
	std::vector <sf::VideoMode> fullscreen_mode = sf::VideoMode::getFullscreenModes();
	//these variables show the screen size in pixels.
	int width = fullscreen_mode[0].width;
	int height = fullscreen_mode[0].height;
	const int level[] = {0,1,2,3,45,8,8,7};
	LandscapeGenerator map;
	TextureTile edit;
	SelectArea f(&edit);
	if (!map.load_map("source.png", sf::Vector2u(32, 32), level, sf::Vector2u(8, 1)))
		return -1;

	sf::RenderWindow window(fullscreen_mode[0], "GunGame", style);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			//event processing
			if (event.type == sf::Event::EventType::KeyPressed) {
				switch (event.key.code)
				{

				case sf::Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}
			}
			//In this cycle, everything that depends on the buttons is processed.
		}
		//edit.updating_the_mouse_position();
		f.update_selected_area();
		//In this cycle, everything that is displayed on the screen is processed.
		window.clear(sf::Color::Black);
		window.draw(map);
		window.draw(edit);
		window.draw(f);
		window.display();
	}
	return 0;
}