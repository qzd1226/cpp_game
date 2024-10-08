#pragma once

#include "bullet.h"
#include "animation.h"

extern Atlas atlas_sun;
extern Atlas atlas_sun_explode;

class SunBullet : public Bullet
{
public:
	SunBullet() {
		size.x = 96, size.y = 96;

		damage = 20;

		animation_idle.set_atlas(&atlas_sun);
		animation_idle.set_interval(50);
		animation_explode.set_loop(false);
		animation_explode.set_callback([&]() {can_remove = true; });

		IMAGE* frame_idle = animation_idle.get_frame();
		IMAGE* frame_explode = animation_explode.get_frame();
	}
	~SunBullet() = default;

private:
	Animation animation_idle;
	Animation animation_explode;
	Vector2 explode_render_offset;
};