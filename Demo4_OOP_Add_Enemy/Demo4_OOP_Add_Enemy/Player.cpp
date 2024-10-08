#include "Player.h";
#include "Bullet.h";
#include "Enemy.h";

const double SQUARE_ROOT2 = sqrt(2);
Player::Player(const std::string& name, int x, int y, int speed, IMAGE player_image, IMAGE player_shadow, Anim* player_anim_left, Anim* player_anim_right) {
	Player::name = name;
	Player::postion_x = x;
	Player::postion_y = y;
	Player::speed = speed;
	Player::enemy_image = enemy_image;
	Player::shadow = shadow;

	Player::image_height = player_image.getheight();
	Player::image_width = player_image.getwidth();
	Player::shadow_height = shadow.getheight();
	Player::shadow_width = shadow.getwidth();

    Player::bullet_list.push_back(new Bullet());

	const int interval = 30;
    Animation anim_left(player_anim_left, 6, interval);
    Animation anim_right(player_anim_right, 6, interval);
	//Animation anim_left(_T("twt/img/player_left_%d.png"), 6, interval);
	//Animation anim_right(_T("twt/img/player_right_%d.png"), 6, interval);
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
    for (size_t i = 0; i < bullet_list.size(); ++i) {
        bullet_list[i]->Draw();
        bullet_list[i]->updateOrbitPosition(Player::postion_x + Player::image_width/2, Player::postion_y + Player::image_height/2);
    }
}

void Player::ProcessEvent(ExMessage msg) {

    if (Player::is_move_left) {
        Player::direction = false;
        if (Player::is_move_up) {
            Player::postion_x -= Player::speed / SQUARE_ROOT2;
            Player::postion_y -= Player::speed / SQUARE_ROOT2;
        }
        else if (Player::is_move_down) {
            Player::postion_x -= Player::speed / SQUARE_ROOT2;
            Player::postion_y += Player::speed / SQUARE_ROOT2;
        }
        else {
            Player::postion_x -= Player::speed;
        }
    }
    else if (Player::is_move_right) {
        Player::direction = true;
        if (Player::is_move_up) {
            Player::postion_x += Player::speed / SQUARE_ROOT2;
            Player::postion_y -= Player::speed / SQUARE_ROOT2;
        }
        else if (Player::is_move_down) {
            Player::postion_x += Player::speed / SQUARE_ROOT2;
            Player::postion_y += Player::speed / SQUARE_ROOT2;
        }
        else {
            Player::postion_x += Player::speed;
        }
    }
    else {
        if (Player::is_move_up) Player::postion_y -= Player::speed;
        if (Player::is_move_down) Player::postion_y += Player::speed;
    }
}



