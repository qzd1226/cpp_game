#pragma once

#include <string>
#include <graphics.h>
#include "Animation.h"

class Player {

public:
	// Constructor
	Player(const std::string& name, int x, int y);

	int position_x;
	int position_y;
	std::string getName() const;
	void setName(std::string name);
	void setSize(int len, int width);
	void drawPlayer(int delta, int dir_x, Animation anim_left_player, Animation anim_right_player);

private:
	std::string name;
	int length;
	int width;
};
