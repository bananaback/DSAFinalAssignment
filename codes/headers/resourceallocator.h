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

	// A vector to manage image font
	std::vector<sf::IntRect> _imgFontIntRects;
	// mapping char to index of _imgFontIntRect;
	std::map<char, int> _charMapping;

	// A vector to manage int rect of tiles
	std::vector<sf::IntRect> _tilesImgRects;
	
	enum IMAGE {
		PLAYER_IDLE, PLAYER_SE, PLAYER_NE, PLAYER_N, PLAYER_E, PLAYER_S, PLAYER_SGUN, MAINMENU_BG, MAINMENU_PLAY,
		MAINMENU_QUIT, MAINMENU_SETTING, CANNON_DIAGDOWN, CANNON_DIAGUP,
		CANNON_DOWN, CANNON_SIDE, CANNON_UP, MAINMENU_STAR, CREDIT_BG, BACK_MAIN_MENU, SLIME_BACK, SLIME_FRONT,
		SLIME_SIDE, CANNONBALL, EXPLOSION_BIG, EXPLOSION_SMALL, COIN_BIG, HEALTHBAR, HEALTHBAR_FILL, BOXWALL, GREENWALL, REDWALL,
		BLUEWALL, ICEWALL, GAMEOVER_BG, BACK_TO_MAIN, TRY_AGAIN, GIVE_UP, SETTING_BG, CURSOR_1, CURSOR_2, CURSOR_3, CURSOR_4, CURSOR_5,
		MEDKIT, ENDING_BG, YES_BTN, NO_BTN, SAVING_BG, SCORE_BG, EXPLOSION, GEM3, NUMBER, IMG_FONT, TILES, 
		FLAMETHROWER_UP, FLAMETHROWER_DIAGUP, FLAMETHROWER_SIDE, FLAMETHROWER_DIAGDOWN, FLAMETHROWER_DOWN, FLAMETHROWER_BULLET,
		MG_BULLET, BURNING, MG_UP, MG_DIAGUP, MG_SIDE, MG_DIAGDOWN, MG_DOWN, MATTER_UP, MATTER_DIAGUP, MATTER_SIDE, MATTER_DIAGDOWN, MATTER_DOWN
	};
	enum FONT { MONO, THALEAHFAT, FONT_CREDIT };
	enum SOUND {};
};

#endif // ! RESOUCESALLOCATOR_H
