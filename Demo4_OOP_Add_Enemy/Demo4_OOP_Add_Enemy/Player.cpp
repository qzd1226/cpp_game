#include "Player.h";


// Constructor
Player::Player(const std::string& name, int x, int y) : name(name), position_x(x), position_y(y) {}

// Getter for name
std::string Player::getName() const {
	return name;
}

// Setter for name
void Player::setName(std::string name) {
	name = name;
}
// Setter for size
void Player::setSize(int len, int wid) {
	length = len;
	width = wid;
}

void Player::drawPlayer(int delta, int dir_x, Animation anim_left_player, Animation anim_right_player) {

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
