#pragma once
#include <graphics.h>
class Bullet
{
public:
	int position_x = 0;
	int position_y = 0;

	Bullet() = default;
	~Bullet() = default;
	
	void Draw() const {
		setlinecolor(RGB(255, 155, 50));
		setfillcolor(RGB(200, 75, 10));
		fillcircle(position_x, position_y, RADIUS);
	}
private:
	const int RADIUS = 10;

};

