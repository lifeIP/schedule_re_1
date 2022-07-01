#include "lib.h"
#include "object.h"


int main() {
	bool a = true;
	sf::Uint32 style = sf::Style::Fullscreen;// setting the window style
	std::vector <sf::VideoMode> fullscreen_mode = sf::VideoMode::getFullscreenModes();
	TextureTile edit;
	SelectArea f(&edit);
	//these variables show the screen size in pixels.
	int width = fullscreen_mode[0].width;
	int height = fullscreen_mode[0].height;

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
				case sf::Keyboard::W:
					edit.up();
					break;
				case sf::Keyboard::S:
					edit.down();
					break;
				case sf::Keyboard::A:
					edit.left();
					break;
				case sf::Keyboard::D:
					edit.right();
					break;
				case sf::Keyboard::M:
					edit.updating_the_mouse_position();
					a = true;
					break;
				case sf::Keyboard::N:
					f.update_selected_area();
					a = false;
					break;
				default:
					break;
				}
			}
			//In this cycle, everything that depends on the buttons is processed.
		}
		//In this cycle, everything that is displayed on the screen is processed.
		window.clear(sf::Color::Black);
		if (a) {
			window.draw(edit);
		}
		else {
			window.draw(f);
		}
		window.display();
	}
	return 0;
}