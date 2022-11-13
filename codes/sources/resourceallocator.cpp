#include "../headers/resourceallocator.h"
#include <iostream>
// Constructor
ResourceAllocator::ResourceAllocator() {
	// Add resouces here
	std::cout << addImage("assets/img/topdown_shooter/characters/1.png");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_diagdown.png");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_diagup.png");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_north.png");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_side.png");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_south.png");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_south2.png");
	std::cout << addImage("assets/img/mainmenu/bg.png");
	std::cout << addImage("assets/img/mainmenu/play.png");
	std::cout << addImage("assets/img/mainmenu/quit.png");
	std::cout << addImage("assets/img/mainmenu/setting.png");

	std::cout << addImage("assets/img/topdown_shooter/guns/cannon/cannon_diagdown.png");
	std::cout << addImage("assets/img/topdown_shooter/guns/cannon/cannon_diagup.png");
	std::cout << addImage("assets/img/topdown_shooter/guns/cannon/cannon_down.png");
	std::cout << addImage("assets/img/topdown_shooter/guns/cannon/cannon_side.png");
	std::cout << addImage("assets/img/topdown_shooter/guns/cannon/cannon_up.png");
	std::cout << addImage("assets/img/mainmenu/star.png");
	std::cout << addImage("assets/img/credit/creditbg.png");
	std::cout << addImage("assets/img/credit/backmm.png");
	std::cout << addFont("assets/fonts/monogram-extended.ttf");
	std::cout << addFont("assets/fonts/ThaleahFat.ttf");
	std::cout << addFont("assets/fonts/04B_19.ttf");

}

// Function to add new image resouces, store the pointer to that resource in _imageResouces map
std::string ResourceAllocator::addImage(std::string filePath) {
	std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
	// If load fail, return error message
	if (!resource->loadFromFile(filePath)) {
		std::string res = "Load file" + filePath + " failed.\n";
		return res;
	}
	// Load success and return success message
	_imageResources.push_back(resource);
	std::string res = "Load file" + filePath + " success.\n";
	return res;
}

std::string ResourceAllocator::addFont(std::string filePath)
{
	std::shared_ptr<sf::Font> resource = std::make_shared<sf::Font>();
	// If load fail, return error message
	if (!resource->loadFromFile(filePath)) {
		std::string res = "Load file" + filePath + " failed.\n";
		return res;
	}
	// Load success and return success message
	_fontResources.push_back(resource);
	std::string res = "Load file" + filePath + " success.\n";
	return res;
}

// NOT IMPLEMENTED YET

std::string ResourceAllocator::addSound(std::string filePath)
{
	return "nothinghere";
}