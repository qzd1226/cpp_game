#pragma once
#include "player.h"
#include <iostream>

extern Atlas atlas_sunflower_idle_left;
extern Atlas atlas_sunflower_idle_right;
extern Atlas atlas_sunflower_run_left;
extern Atlas atlas_sunflower_run_right;

class SunflowerPlayer : public Player{

public:
	~SunflowerPlayer() = default;

	void on_update(int delta) { 

		Player::on_update(delta);
		std::cout << "向日葵正在更新..." << std::endl;
	}
	SunflowerPlayer() {
		animation_idle_left.set_atlas(&atlas_sunflower_idle_left);
		animation_idle_right.set_atlas(&atlas_sunflower_idle_right);
		animation_run_left.set_atlas(&atlas_sunflower_run_left);
		animation_run_right.set_atlas(&atlas_sunflower_run_right);

		animation_idle_left.set_interval(75);
		animation_idle_right.set_interval(75);
		animation_run_left.set_interval(75);
		animation_run_right.set_interval(75);
	}
private:

};