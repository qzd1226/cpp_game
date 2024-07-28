#pragma once
#include <graphics.h>
#include <string>
class Bullet
{
public:
	int position_x = 0;
	int position_y = 0;
	double angle = 0;

	Bullet() = default;
	~Bullet() = default;
	void Draw() const;
	void updateOrbitPosition(int player_pos_x, int player_pos_y);
private:
	const int RADIUS = 5;
	std::string bullet_type;

};

