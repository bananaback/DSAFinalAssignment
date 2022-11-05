#include "codes/headers/game.h"
#include "codes/headers/mainmenu.h"


int main() {
	std::shared_ptr<MainMenu> mainMenu(new MainMenu());

	Game pewpew;
	pewpew.init(mainMenu);

	pewpew.run();

	return 0;
}