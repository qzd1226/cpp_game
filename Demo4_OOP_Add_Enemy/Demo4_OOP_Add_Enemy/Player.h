#pragma once

#include <string>
#include <graphics.h>
#include "Animation.h"

class Player
{
public:
	// Constructor
	Player(const std::string& name, int x, int y, int speed, IMAGE enemy_image, IMAGE shadow);

public:

	Animation left_anim;
	Animation right_anim;
	int postion_x;
	int postion_y;
	int speed;
	bool direction;
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;

	//Animation anim_left_player(_T("twt/img/player_left_%d.png"), 6, interval);
public:
	void SetLeftAnim(std::string url, int frame_num, int interval);
	void SetRightAnim(std::string url, int frame_num, int interval);

	//bool CheckBullectCollision(const Bullet& bullet);

public:
	void Draw(int delta);
	void ProcessEvent(ExMessage msg);


private:
	std::string name;
	int frame_num;
	int interval;

	int image_width;
	int image_height;

	int shadow_width;
	int shadow_height;

	IMAGE shadow;
	IMAGE enemy_image;
};