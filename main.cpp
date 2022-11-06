#include "codes/headers/game.h"
#include "codes/headers/mainmenu.h"
 
// Driver code
int main() {
	// Pointer to main menu game state
	std::shared_ptr<MainMenu> mainMenu(new MainMenu());
	// Pointer to resouce allocator
	std::shared_ptr<ResourceAllocator> resouceAllocator(new ResourceAllocator);

	// Make a game!
	Game pewpew;
	// Init our game with the first state
	pewpew.init(mainMenu);
	// Attach resouce allocator to our game
	pewpew.ra_ptr = resouceAllocator;
	// Run our game
	pewpew.run();

	// Program is finished with no error
	return 0;
} 