#include "Bullet.h"

const double PI = 3.14159265358979323846;

void Bullet::Draw() const {
	setlinecolor(RGB(255, 155, 50));
	setfillcolor(RGB(200, 75, 10));
	fillcircle(position_x, position_y, RADIUS);
}

void Bullet::updateOrbitPosition(int player_pos_x, int player_pos_y)
{
	Bullet::position_x = player_pos_x;
	Bullet::position_y = player_pos_y;
	int r = 80;
	double angleInRadians = angle * PI / 180.0;
	position_x = player_pos_x + r * cos(angleInRadians);
	position_y = player_pos_y + r * sin(angleInRadians);
	angle += 5;
	if (angle > 360) {
		angle -= 360;
	}

}
