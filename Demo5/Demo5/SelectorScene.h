#pragma once

#include "scene.h"
#include "SceneManager.h"
#include "animation.h"

extern IMAGE img_VS;                      // VS art character
extern IMAGE img_1P;                      // 1P character image
extern IMAGE img_2P;                      // 2P character image
extern IMAGE img_1P_desc;                 // 1P control description
extern IMAGE img_2P_desc;                 // 2P control description
extern IMAGE img_gravestone_left;
extern IMAGE img_gravestone_right;
extern IMAGE img_selector_tip;            // character select scene tips image
extern IMAGE img_selector_background;     // character select scene tips background
extern IMAGE img_1P_selector_btn_idle_left; // 1P character select left button image
extern IMAGE img_1P_selector_btn_idle_right; // 1P character select right button image
extern IMAGE img_1P_selector_btn_down_left; // 1P character select left button down image
extern IMAGE img_1P_selector_btn_down_right; // 1P character select right button down image
extern IMAGE img_2P_selector_btn_idle_left; // 2P character select left button image
extern IMAGE img_2P_selector_btn_idle_right; // 2P character select right button image
extern IMAGE img_2P_selector_btn_down_left; // 2P character select left button down image
extern IMAGE img_2P_selector_btn_down_right; // 2P character select right button down image
extern IMAGE img_peashooter_selector_background_left;
extern IMAGE img_peashooter_selector_background_right;
extern IMAGE img_sunflower_selector_background_left;
extern IMAGE img_sunflower_selector_background_right;

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

extern IMAGE img_avatar_peashooter;
extern IMAGE img_acatar_sunflower;

extern SceneManager scene_manager;

class SelectorScene : public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void on_enter()
	{
		printf("enter selector scene");
		animation_peashooter.set_atlas(&atlas_peashooter_idle_right);
		animation_sunflower.set_atlas(&atlas_sunflower_idle_right);

		animation_peashooter.set_interval(100);
		animation_sunflower.set_interval(100);
		static const int OFFSET_X = 50;
		pos_img_VS.x = (getwidth() - img_VS.getwidth()) / 2;
		pos_img_VS.y = (getheight() - img_VS.getheight()) / 2;
		pos_img_tip.x = (getwidth() - img_selector_tip.getwidth()) / 2;
		pos_img_tip.y = getheight() - 125;
		pos_img_1P.x = (getwidth() / 2 - img_1P.getwidth()) / 2 - OFFSET_X;
		pos_img_1P.y = 35;
		pos_img_2P.x = getwidth() / 2 + (getwidth() / 2 - img_2P.getwidth()) / 2 + OFFSET_X;
		pos_img_2P.y = pos_img_1P.y;
		pos_img_1P_desc.x = (getwidth() / 2 - img_1P_desc.getwidth()) / 2 - OFFSET_X;
		pos_img_1P_desc.y = getheight() - 150;
		pos_img_2P_desc.x = getwidth() / 2 + (getwidth() / 2 - img_2P_desc.getwidth()) / 2 + OFFSET_X;
		pos_img_2P_desc.y = pos_img_1P_desc.y;
		pos_img_1P_gravestone.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
		pos_img_1P_gravestone.y = pos_img_1P.y + img_1P.getheight() + 35;
		pos_img_2P_gravestone.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth()) / 2 + OFFSET_X;
		pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
		pos_animation_1P.x = (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 - OFFSET_X;
		pos_animation_1P.y = pos_img_1P_gravestone.y + 80;
		pos_animation_2P.x = getwidth() / 2 + (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 + OFFSET_X;
		pos_animation_2P.y = pos_animation_1P.y;
		pos_img_1P_name.y = pos_animation_1P.y + 155;
		pos_img_2P_name.y = pos_img_1P_name.y;
		pos_img_1P_name.x = pos_animation_1P.x;
		pos_img_2P_name.x = pos_animation_2P.x;
		pos_1P_selector_btn_left.x = pos_img_1P_gravestone.x - img_1P_selector_btn_idle_left.getwidth();
		pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y + (img_gravestone_right.getheight() - img_1P_selector_btn_idle_left.getheight()) / 2;
		pos_1P_selector_btn_right.x = pos_img_1P_gravestone.x + img_gravestone_right.getwidth();
		pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;
		pos_2P_selector_btn_left.x = pos_img_2P_gravestone.x - img_2P_selector_btn_idle_left.getwidth();
		pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;
		pos_2P_selector_btn_right.x = pos_img_2P_gravestone.x + img_gravestone_left.getwidth();
		pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;

	} 

	void on_update(int delta) {
		animation_peashooter.on_update(delta);
		animation_sunflower.on_update(delta);
	}

	void on_draw(const Camera& camera) {

		printf("on draw");
		putimage(0, 0, &img_selector_background);

		putimage_alpha(camera, pos_img_VS.x, pos_img_VS.y, &img_VS);

		putimage_alpha(camera, pos_img_1P.x, pos_img_1P.y, &img_1P);
		putimage_alpha(camera, pos_img_2P.x, pos_img_2P.y, &img_2P);

		putimage_alpha(camera, pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, &img_gravestone_right);
		putimage_alpha(camera, pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, &img_gravestone_left);

		switch(player_type_1) {
		case PlayerType::Peashooter:
				animation_peashooter.on_draw(camera, pos_animation_1P.x, pos_animation_1P.y);
				outtextxy_shaded(pos_img_1P_name.x, pos_img_1P_name.y, str_peashooter_name);
				break;
			case PlayerType::Sunflower:
				animation_sunflower.on_draw(camera, pos_animation_1P.x, pos_animation_1P.y);
				outtextxy_shaded(pos_img_1P_name.x, pos_img_1P_name.y, str_sunflower_name);
		}
		switch (player_type_2) {
		case PlayerType::Peashooter:
			animation_peashooter.on_draw(camera, pos_animation_2P.x, pos_animation_2P.y);
			outtextxy_shaded(pos_img_2P_name.x, pos_img_2P_name.y, str_peashooter_name);
			break;
		case PlayerType::Sunflower:
			animation_sunflower.on_draw(camera, pos_animation_2P.x, pos_animation_2P.y);
			outtextxy_shaded(pos_img_2P_name.x, pos_img_2P_name.y, str_sunflower_name);
		}

		putimage_alpha(camera, pos_img_1P_desc.x, pos_img_1P_desc.y, &img_1P_desc);
		putimage_alpha(camera, pos_img_2P_desc.x, pos_img_2P_desc.y, &img_2P_desc);

		putimage_alpha(camera, pos_img_tip.x, pos_img_tip.y, &img_selector_tip);
	}

	void on_input() {
	
	}

	void on_exit() {

	}
private:
	enum class PlayerType
	{
		Peashooter = 0,
		Sunflower,
		Invalid
	};

private:
	POINT pos_img_VS = { 0 };
	POINT pos_img_tip = { 0 };
	POINT pos_img_1P = { 0 };
	POINT pos_img_2P = { 0 };
	POINT pos_img_1P_desc = { 0 };
	POINT pos_img_2P_desc = { 0 };
	POINT pos_img_1P_name = { 0 };
	POINT pos_img_2P_name = { 0 };
	POINT pos_animation_1P = { 0 };
	POINT pos_animation_2P = { 0 };
	POINT pos_img_1P_gravestone = { 0 };
	POINT pos_img_2P_gravestone = { 0 };
	POINT pos_1P_selector_btn_left = { 0 };
	POINT pos_1P_selector_btn_right = { 0 };
	POINT pos_2P_selector_btn_left = { 0 };
	POINT pos_2P_selector_btn_right = { 0 };

	Animation animation_peashooter;
	Animation animation_sunflower;

	PlayerType player_type_1 = PlayerType::Peashooter;   // P1 player type
	PlayerType player_type_2 = PlayerType::Sunflower;    // P2 player type

	LPCTSTR str_peashooter_name = _T("豌豆射手");
	LPCTSTR str_sunflower_name = _T("向日葵");

private:
	void outtextxy_shaded(int x, int y, LPCTSTR str) {
		settextcolor(RGB(45, 45, 45));
		outtextxy(x + 3, y + 3, str);
		settextcolor(RGB(255, 255, 255));
		outtextxy(x, y, str);
	}

};

