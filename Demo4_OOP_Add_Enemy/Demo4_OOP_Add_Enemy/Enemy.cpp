#include "Enemy.h"



Enemy::Enemy(const std::string& name, int x, int y, int speed, IMAGE enemy_image, IMAGE shadow){
	Enemy::name = name;
	Enemy::postion_x = x;
	Enemy::postion_y = y;
	Enemy::speed = speed;
	Enemy::enemy_image = enemy_image;
	Enemy::shadow = shadow;

	Enemy::image_height = enemy_image.getheight();
	Enemy::image_width = enemy_image.getwidth();
	Enemy::shadow_height = shadow.getheight();
	Enemy::shadow_width = shadow.getwidth();

	const int interval = 30;
	Animation anim_left(_T("twt/img/enemy_left_%d.png"), 6, interval);
	Animation anim_right(_T("twt/img/enemy_right_%d.png"), 6, interval);
	Enemy::left_anim = anim_left;
	Enemy::right_anim = anim_right;

}