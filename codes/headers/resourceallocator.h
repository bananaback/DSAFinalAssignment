#pragma once
#ifndef RESOURCESALLOCATOR_H
#define RESOURCEALLOCATOR_H

#include <string> // For std::string
#include <map> // For std::map
#include <memory> // For std::shared_ptr
#include "SFML/Graphics.hpp" // For sf::Texture
#include "SFML/Audio.hpp" // For sf::SoundBuffer

// Resource allocator class
class ResourceAllocator {
public:
	// Constructor
	ResourceAllocator();

	// IMAGE
	
	// Function to add new image resouces, store the pointer to that resource in _imageResouces map
	std::string addImage(std::string filePath);
	
	// A vector to manage pointer to the loaded image resources
	std::vector<std::shared_ptr<sf::Texture>> _imageResources;

	// SOUND

	// ATTENTION! Resouce allocator for sound not implemented yet...
	
	// Function to add new sound resouces, store the pointer to that resource in _soundResources map
	std::string addSound(std::string filePath);
	
	// A vector to manage pointer to the loaded sound resources
	std::vector<std::shared_ptr<sf::SoundBuffer>> _soundResources;

	// FONT
	std::string addFont(std::string filePath);

	// A vector to manage pointer to the loaded font resources
	std::vector<std::shared_ptr<sf::Font>> _fontResources;

	enum IMAGE{PLAYER_IDLE, PLAYER_SE, PLAYER_NE, PLAYER_N, PLAYER_E, PLAYER_S, PLAYER_SGUN, MAINMENU_BG, MAINMENU_PLAY, MAINMENU_QUIT, MAINMENU_SETTING};
	enum FONT{MONO, THALEAHFAT};
	enum SOUND{};
};

#endif // ! RESOUCESALLOCATOR_H
