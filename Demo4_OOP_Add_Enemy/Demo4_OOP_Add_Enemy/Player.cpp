#include "Player.h";


// Constructor
Player::Player(const std::string& name, int x, int y, IMAGE player_image, IMAGE shadow) : name(name), position_x(x), position_y(y), player_image(player_image), shadow(shadow ) {
	Player::height = player_image.getheight();
	Player::width = player_image.getwidth();
}

// Getter for name
std::string Player::getName() const {
	return name;
}

// Setter for name
void Player::setName(std::string name) {
	name = name;
}

// Setter for shadow
void Player::setShadow(IMAGE shadow) {
	Player::shadow = shadow;
}

IMAGE Player::getShadow() {
	return Player::shadow;
}

void Player::drawPlayer(int delta, int dir_x, Animation &anim_left_player, Animation &anim_right_player) {

	Player::drawShadow();

	static bool facing_left = false;
	if (dir_x < 0) {
		facing_left = true;
	}
	else if (dir_x > 0) {
		facing_left = false;
	}
	if (facing_left)
		anim_left_player.Play(position_x, position_y, delta);
	else
		anim_right_player.Play(position_x, position_y, delta);
}

void Player::drawShadow() {

	IMAGE img = Player::getShadow();
	Animation::putimage_alpha(Player::position_x + Player::width/2, Player::position_y + Player::height, &img);

}

int Player::chase(int speed, int target_x, int target_y) {
	double distance = sqrt((Player::position_x - target_x) * (Player::position_x - target_x) + (Player::position_y - target_y) * (Player::position_y - target_y));
	if (distance < speed) {
		Player::position_x = target_x;
		Player::position_y = target_y;
	}
	else {
		// direction
		double dx = (target_x - Player::position_x) / distance;
		double dy = (target_y - Player::position_y) / distance;
		// update position
		Player::position_x += round(dx * speed);
		Player::position_y += round(dy * speed);
	}
	if ((target_x - Player::position_x) < 0) {
		return -1;
	}
	else {
		return 1;
	}
}

void Player::setPlayerImage(IMAGE player) {
	Player::height = player.getheight();
	Player::width = player.getwidth();
	Player::player_image = player;
	return;
}

IMAGE Player::getPlayerImage() {
	return Player::player_image;
}