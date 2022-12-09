#include <iostream>
#include "../headers/resourceallocator.h"

// Constructor
ResourceAllocator::ResourceAllocator() {
	// Add resouces here
	addImage("assets/img/topdown_shooter/characters/1.png");
	addImage("assets/img/topdown_shooter/characters/1_diagdown.png");
	addImage("assets/img/topdown_shooter/characters/1_diagup.png");
	addImage("assets/img/topdown_shooter/characters/1_north.png");
	addImage("assets/img/topdown_shooter/characters/1_side.png");
	addImage("assets/img/topdown_shooter/characters/1_south.png");
	addImage("assets/img/topdown_shooter/characters/1_south2.png");
	addImage("assets/img/mainmenu/bg.png");
	addImage("assets/img/mainmenu/play.png");
	addImage("assets/img/mainmenu/quit.png");
	addImage("assets/img/mainmenu/setting.png");

	addImage("assets/img/topdown_shooter/guns/cannon/cannon_diagdown.png");
	addImage("assets/img/topdown_shooter/guns/cannon/cannon_diagup.png");
	addImage("assets/img/topdown_shooter/guns/cannon/cannon_down.png");
	addImage("assets/img/topdown_shooter/guns/cannon/cannon_side.png");
	addImage("assets/img/topdown_shooter/guns/cannon/cannon_up.png");
	addImage("assets/img/mainmenu/star.png");
	addImage("assets/img/credit/creditbg.png");
	addImage("assets/img/credit/backmm.png");
	addImage("assets/img/topdown_shooter/monster/slime1_back.png");
	addImage("assets/img/topdown_shooter/monster/slime1_front.png");
	addImage("assets/img/topdown_shooter/monster/slime1_side.png");
	addImage("assets/img/topdown_shooter/other/cannonball.png");
	addImage("assets/img/topdown_shooter/other/explode1.png");
	addImage("assets/img/topdown_shooter/other/explode2.png");
	addImage("assets/img/topdown_shooter/other/coin2.png");
	addImage("assets/img/topdown_shooter/health-bar.png");
	addImage("assets/img/topdown_shooter/health-bar-fill.png");
	addImage("assets/img/topdown_shooter/wall/boxwall.png");
	addImage("assets/img/topdown_shooter/wall/greenwall.png");
	addImage("assets/img/topdown_shooter/wall/redwall.png");
	addImage("assets/img/topdown_shooter/wall/bluewall.png");
	addImage("assets/img/topdown_shooter/wall/icewall.png");
	addImage("assets/img/gameover/gameoverbg.png");
	addImage("assets/img/gameover/backtomain.png");
	addImage("assets/img/gameover/tryagain.png");
	addImage("assets/img/gameover/giveup.png");
	addImage("assets/img/setting/setting_bg.png");
	addImage("assets/img/topdown_shooter/cursors/mouse_pointer.png");
	addImage("assets/img/topdown_shooter/cursors/6crosshair2.png");
	addImage("assets/img/topdown_shooter/cursors/1crosshair2.png");
	addImage("assets/img/topdown_shooter/cursors/7crosshair2.png");
	addImage("assets/img/topdown_shooter/cursors/4crosshair2.png");
	addImage("assets/img/topdown_shooter/other/powerup.png");
	addImage("assets/img/ending/28.png");
	addImage("assets/img/ending/1.png");
	addImage("assets/img/ending/2.png");
	addImage("assets/img/saving/7.png");
	addImage("assets/img/score/back3.png");
	addImage("assets/img/score/explosion.png");
	addImage("assets/img/score/gem3.png");
	addImage("assets/img/score/number.png");
	addImage("assets/fonts/font-20x20.png");
	addImage("assets/img/tiles.png");
	addImage("assets/img/topdown_shooter/guns/flamthrower/flamethrower_up.png");
	addImage("assets/img/topdown_shooter/guns/flamthrower/flamethrower_diagup.png");
	addImage("assets/img/topdown_shooter/guns/flamthrower/flamethrower_side.png");
	addImage("assets/img/topdown_shooter/guns/flamthrower/flamethrower_diagdown.png");
	addImage("assets/img/topdown_shooter/guns/flamthrower/flamethrower_down.png");
	addImage("assets/img/topdown_shooter/other/flamethrower_bullet.png");
	addImage("assets/img/topdown_shooter/other/bulletc.png");
	addImage("assets/img/topdown_shooter/other/burning.png");
	addImage("assets/img/topdown_shooter/guns/mg/mg_up.png");
	addImage("assets/img/topdown_shooter/guns/mg/mg_diagup.png");
	addImage("assets/img/topdown_shooter/guns/mg/mg_side.png");
	addImage("assets/img/topdown_shooter/guns/mg/mg_diagdown.png");
	addImage("assets/img/topdown_shooter/guns/mg/mg_down.png");
	addImage("assets/img/topdown_shooter/guns/matter/matter_up.png");
	addImage("assets/img/topdown_shooter/guns/matter/matter_diagup.png");
	addImage("assets/img/topdown_shooter/guns/matter/matter_side.png");
	addImage("assets/img/topdown_shooter/guns/matter/matter_diagdown.png");
	addImage("assets/img/topdown_shooter/guns/matter/matter_down.png");
	addImage("assets/img/topdown_shooter/other/onion.png");
	addImage("assets/img/topdown_shooter/other/tomato.png");
	addImage("assets/img/topdown_shooter/other/onion_effect.png");
	addImage("assets/img/topdown_shooter/other/tomato_effect.png");
	addImage("assets/img/topdown_shooter/other/cat.png");
	addImage("assets/img/topdown_shooter/other/catscratch.png");
	addImage("assets/img/coinhud.png");
	addImage("assets/img/dust.png");
	addImage("assets/img/topdown_shooter/other/base.png");


	addFont("assets/fonts/monogram-extended.ttf");
	addFont("assets/fonts/ThaleahFat.ttf");
	addFont("assets/fonts/04B_19.ttf");

	for (int i = 0; i < 540; i++) {
		sf::IntRect temp(i%36*16, i/36*16, 16, 16);
		_tilesImgRects.push_back(temp);
	}

	for (int i = 0; i < 120; i++) {
		sf::IntRect temp((i % 15)*20, (i / 15)*20, 20, 20);
		_imgFontIntRects.push_back(temp);
	}
	_charMapping['A'] = 33;
	_charMapping['B'] = 34;
	_charMapping['C'] = 35;
	_charMapping['D'] = 36;
	_charMapping['E'] = 37;
	_charMapping['F'] = 38;
	_charMapping['G'] = 39;
	_charMapping['H'] = 40;
	_charMapping['I'] = 41;
	_charMapping['J'] = 42;
	_charMapping['K'] = 43;
	_charMapping['L'] = 44;
	_charMapping['M'] = 45;
	_charMapping['N'] = 46;
	_charMapping['O'] = 47;
	_charMapping['P'] = 48;
	_charMapping['Q'] = 49;
	_charMapping['R'] = 50;
	_charMapping['S'] = 51;
	_charMapping['T'] = 52;
	_charMapping['U'] = 53;
	_charMapping['V'] = 54;
	_charMapping['W'] = 55;
	_charMapping['X'] = 56;
	_charMapping['Y'] = 57;
	_charMapping['Z'] = 58;

	_charMapping['0'] = 16;
	_charMapping['1'] = 17;
	_charMapping['2'] = 18;
	_charMapping['3'] = 19;
	_charMapping['4'] = 20;
	_charMapping['5'] = 21;
	_charMapping['6'] = 22;
	_charMapping['7'] = 23;
	_charMapping['8'] = 24;
	_charMapping['9'] = 25;

	_charMapping[' '] = 0;
	_charMapping[':'] = 26;

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

std::string ResourceAllocator::addFont(std::string filePath) {
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

std::string ResourceAllocator::addSound(std::string filePath) {
	return "nothinghere";
}