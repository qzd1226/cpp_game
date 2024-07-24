#pragma once

#include <string>
#include <graphics.h>
#include "Animation.h"

class Player {

public:
	// Constructor
	Player(const std::string& name, int x, int y, IMAGE player_image, IMAGE shadow);

	int position_x;
	int position_y;

	std::string getName() const;

	void setName(std::string name);

	void setShadow(IMAGE shadow);

	void setPlayerImage(IMAGE player_image);

	IMAGE getPlayerImage();

	IMAGE getShadow();

	void drawPlayer(int delta, int dir_x, Animation &anim_left_player, Animation &anim_right_player);

	void drawShadow();

	int chase(int speed, int target_x, int target_y);
	

private:
	std::string name;
	int height;
	int width;
	IMAGE shadow;
	IMAGE player_image;
};
