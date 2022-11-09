#include "../headers/resourceallocator.h"
#include <iostream>
// Constructor
ResourceAllocator::ResourceAllocator() {
	// Add resouces here
	std::cout << addImage("assets/img/topdown_shooter/characters/1.png", "player", "idle");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_diagdown.png", "player", "se");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_diagup.png", "player", "ne");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_north.png", "player", "n");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_side.png", "player", "e");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_south.png", "player", "s");
	std::cout << addImage("assets/img/topdown_shooter/characters/1_south2.png", "player", "sgun");
	std::cout << addImage("assets/img/mainmenu/bg.png", "mainmenu", "bg");
	std::cout << addImage("assets/img/mainmenu/play.png", "mainmenu", "play");
	std::cout << addImage("assets/img/mainmenu/quit.png", "mainmenu", "quit");
	std::cout << addImage("assets/img/mainmenu/setting.png", "mainmenu", "setting");
}

// Function to add new image resouces, store the pointer to that resource in _imageResouces map
std::string ResourceAllocator::addImage(std::string filePath, std::string parent, std::string child) {
	// Handle image load
	auto it = _imageResources.find(parent);
	// If found parent
	if (it != _imageResources.end()) {
		auto itc = _imageResources[parent].find(child);
		// If found child
		if (itc != _imageResources[parent].end()) {
			// Do nothing and return added
			return "added";
		}
	}
	// If not found, we will load it
	std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
	// If load fail, return error message
	if (!resource->loadFromFile(filePath)) {
		return "loadfail";
	}
	// Load success and return success message
	_imageResources[parent].insert(std::make_pair(child, resource));
	return "success";
}

// Function to get pointer to added image resource
std::shared_ptr<sf::Texture> ResourceAllocator::getImage(std::string parent, std::string child) {
	// Find parent
	auto it = _imageResources.find(parent);
	// If parent found
	if (it != _imageResources.end()) {
		// Find child
		auto itc = _imageResources[parent].find(child);
		// If child found
		if (itc != _imageResources[parent].end()) {
			// Return pointer to that resource
			return _imageResources[parent][child];
		}
	}
	// If not found return null pointer
	return nullptr;
}

// NOT IMPLEMENTED YET

std::string ResourceAllocator::addSound(std::string filePath, std::string parent, std::string child)
{
	return "nothinghere";
}

std::shared_ptr<sf::SoundBuffer> ResourceAllocator::getSound(std::string parent, std::string child)
{
	return nullptr;
}
