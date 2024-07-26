#include "Player.h";
#include "Bullet.h";
#include "Enemy.h";

const double SQUARE_ROOT2 = sqrt(2);
Player::Player(const std::string& name, int x, int y, int speed, IMAGE player_image, IMAGE player_shadow) {
	Player::name = name;
	Player::postion_x = x;
	Player::postion_y = y;
	Player::speed = speed;
	Player::enemy_image = enemy_image;
	Player::shadow = shadow;

	Player::image_height = enemy_image.getheight();
	Player::image_width = enemy_image.getwidth();
	Player::shadow_height = shadow.getheight();
	Player::shadow_width = shadow.getwidth();

	const int interval = 30;
	Animation anim_left(_T("twt/img/player_left_%d.png"), 6, interval);
	Animation anim_right(_T("twt/img/player_right_%d.png"), 6, interval);
	Player::left_anim = anim_left;
	Player::right_anim = anim_right;

}

//bool Player::CheckBullectCollision(const Bullet& bullet) {
//	return false;
//}


void Player::Draw(int delta) {

	int pos_shadow_x = Player::postion_x + (Player::image_width / 2 - Player::shadow_width / 2);
	int pos_shadow_y = Player::postion_y + Player::image_height - 8;
	Animation::putimage_alpha(pos_shadow_x, pos_shadow_y, &shadow);

	if (Player::direction == false) {
		Player::left_anim.Play(Player::postion_x, Player::postion_y, delta);
	}
	else {
		Player::right_anim.Play(Player::postion_x, Player::postion_y, delta);
	}
}

void Player::ProcessEvent(ExMessage msg, bool &is_move_up, bool &is_move_down, bool &is_move_left, bool &is_move_right) {

    if (is_move_left) {
        Player::direction = false;
        if (is_move_up) {
            Player::postion_x -= Player::speed / SQUARE_ROOT2;
            Player::postion_y -= Player::speed / SQUARE_ROOT2;
        }
        else if (is_move_down) {
            Player::postion_x -= Player::speed / SQUARE_ROOT2;
            Player::postion_y += Player::speed / SQUARE_ROOT2;
        }
        else {
            Player::postion_x -= Player::speed;
        }
    }
    else if (is_move_right) {
        Player::direction = true;
        if (is_move_up) {
            Player::postion_x += Player::speed / SQUARE_ROOT2;
            Player::postion_y -= Player::speed / SQUARE_ROOT2;
        }
        else if (is_move_down) {
            Player::postion_x += Player::speed / SQUARE_ROOT2;
            Player::postion_y += Player::speed / SQUARE_ROOT2;
        }
        else {
            Player::postion_x += Player::speed;
        }
    }
    else {
        if (is_move_up) Player::postion_y -= Player::speed;
        if (is_move_down) Player::postion_y += Player::speed;
    }
}



