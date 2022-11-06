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

	// Image
	
	// Function to add new image resouces, store the pointer to that resource in _imageResouces map
	std::string addImage(std::string filePath, std::string parent, std::string child);
	// Function to get pointer to added image resource
	std::shared_ptr<sf::Texture> getImage(std::string parent, std::string child);
	// A map in a map to manage pointer to the loaded image resources
	std::map < std::string, std::map<std::string, std::shared_ptr<sf::Texture>>> _imageResources;

	// Sound

	// ATTENTION! Resouce allocator for sound not implemented yet...
	
	// Function to add new sound resouces, store the pointer to that resource in _soundResources map
	std::string addSound(std::string filePath, std::string parent, std::string child);
	// Function to get pointer to added sound resource
	std::shared_ptr<sf::SoundBuffer> getSound(std::string parent, std::string child);
	// A map in a map to manage pointer to the loaded sound resources
	std::map < std::string, std::map<std::string, std::shared_ptr<sf::SoundBuffer>>> _soundResources;
};

#endif // ! RESOUCESALLOCATOR_H
