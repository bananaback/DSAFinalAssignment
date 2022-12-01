#pragma once
#ifndef CANNONDISPLAY_H
#define CANNONDISPLAY_H

#include "weapondisplay.h"

class CannonDisplay : public WeaponDisplay {
public:
	CannonDisplay(Game& game, float x, float y, float scale);
	~CannonDisplay();
	void update(Game& game);
private:

};

#endif // ! CANNONDISPLAY_H
