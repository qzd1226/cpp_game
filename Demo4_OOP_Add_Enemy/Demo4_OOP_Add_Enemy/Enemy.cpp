#include "Enemy.h"
#include "Animation.h"



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

bool Enemy::CheckBullectCollision(const Bullet& bullet) {
	return false;
}

bool Enemy::CheckPlayerCollision(const Player& player) {
	return false;
}

void Enemy::Draw(int delta) {

	int pos_shadow_x = Enemy::postion_x + (Enemy::image_width / 2 - Enemy::shadow_width / 2);
	int pos_shadow_y = Enemy::postion_y + Enemy::image_height - 8;
	Animation::putimage_alpha(pos_shadow_x , pos_shadow_y, &shadow);
	
	if (Enemy::direction == false) {
		Enemy::left_anim.Play(Enemy::postion_x, Enemy::postion_y, delta);
	}
	else {
		Enemy::right_anim.Play(Enemy::postion_x, Enemy::postion_y, delta);
	}

}

void Enemy::Chase(Player player) {
	int target_x = player.postion_x;
	int target_y = player.postion_y;
	double distance = sqrt((Enemy::postion_x - target_x) * (Enemy::postion_x - target_x) + (Enemy::postion_y - target_y) * (Enemy::postion_y - target_y));
	if (distance < speed) {
		Enemy::postion_x = target_x;
		Enemy::postion_y = target_y;
	}
	else {
		// direction
		double dx = (target_x - Enemy::postion_x) / distance;
		double dy = (target_y - Enemy::postion_y) / distance;
		// update position
		Enemy::postion_x += round(dx * speed);
		Enemy::postion_y += round(dy * speed);
	}
	if ((target_x - Enemy::postion_x) < 0) {
		Enemy::direction = false;
	}
	else {
		Enemy::direction = true;
	}
}
