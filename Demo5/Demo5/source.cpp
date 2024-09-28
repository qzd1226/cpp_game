#include "Scene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "SelectorScene.h"
#include "atlas.h"
#include "util.h"

#include <windows.h>
#pragma comment(lib, "Winmm.lib")
IMAGE img_menu_background;         // main menu background

IMAGE img_VS;                      // VS art character
IMAGE img_1P;                      // 1P character image
IMAGE img_2P;                      // 2P character image
IMAGE img_1P_desc;                 // 1P control description
IMAGE img_2P_desc;                 // 2P control description
IMAGE img_gravestone_left;
IMAGE img_gravestone_right;
IMAGE img_selector_tip;            // character select scene tips image
IMAGE img_selector_background;     // character select scene tips background
IMAGE img_1P_selector_btn_idle_left; // 1P character select left button image
IMAGE img_1P_selector_btn_idle_right; // 1P character select right button image
IMAGE img_1P_selector_btn_down_left; // 1P character select left button down image
IMAGE img_1P_selector_btn_down_right; // 1P character select right button down image
IMAGE img_2P_selector_btn_idle_left; // 2P character select left button image
IMAGE img_2P_selector_btn_idle_right; // 2P character select right button image
IMAGE img_2P_selector_btn_down_left; // 2P character select left button down image
IMAGE img_2P_selector_btn_down_right; // 2P character select right button down image
IMAGE img_peashooter_selector_background_left;
IMAGE img_peashooter_selector_background_right;
IMAGE img_sunflower_selector_background_left;
IMAGE img_sunflower_selector_background_right;

IMAGE img_sky;
IMAGE img_hills;
IMAGE img_platform_large;
IMAGE img_platform_small;

IMAGE img_1P_cursor;
IMAGE img_2P_cursor;

Atlas atlas_peashooter_idle_left;   
Atlas atlas_peashooter_idle_right;
Atlas atlas_peashooter_run_left;
Atlas atlas_peashooter_run_right;
Atlas atlas_peashooter_attack_ex_left;
Atlas atlas_peashooter_attack_ex_right;
Atlas atlas_peashooter_die_left;
Atlas atlas_peashooter_die_right;

Atlas atlas_sunflower_idle_left;
Atlas atlas_sunflower_idle_right;
Atlas atlas_sunflower_run_left;
Atlas atlas_sunflower_run_right;
Atlas atlas_sunflower_attack_ex_left;
Atlas atlas_sunflower_attack_ex_right;
Atlas atlas_sunflower_die_left;
Atlas atlas_sunflower_die_right;

IMAGE img_pea;
Atlas atlas_pea_break;
Atlas atlas_sun;
Atlas atlas_sun_explode;
Atlas atlas_sun_ex;
Atlas atlas_sun_ex_explode;
Atlas atlas_sun_text;

Atlas atlas_run_effect;
Atlas atlas_junmp_effect;
Atlas atlas_land_effect;

IMAGE img_1P_winner;                      // 1P win text
IMAGE img_2P_winner;                      // 2P win text
IMAGE img_winner_bar;                     // winner bar background

IMAGE img_avatar_peashooter;
IMAGE img_avatar_sunflower;


Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;

Camera main_camera;

void flip_atlas(Atlas& src, Atlas& dst) {
	dst.clear();
	for (int i = 0; i < src.get_size(); i++) {
		IMAGE img_flpipped;
		flip_image(src.get_image(i), &img_flpipped);
		dst.add_image(img_flpipped);
	}
}

void load_game_resources() {

	
	AddFontResourceEx(_T("pvz/resources/IPix.ttf"), FR_PRIVATE, NULL);

	loadimage(&img_menu_background, _T("pvz/resources/menu_background.png"));

	loadimage(&img_VS, _T("pvz/resources/VS.png"));
	loadimage(&img_1P, _T("pvz/resources/1P.png"));
	loadimage(&img_2P, _T("pvz/resources/2P.png"));
	loadimage(&img_1P_desc, _T("pvz/resources/1P_desc.png"));
	loadimage(&img_2P_desc, _T("pvz/resources/2P_desc.png"));
	loadimage(&img_gravestone_right, _T("pvz/resources/gravestone.png"));
	flip_image(&img_gravestone_right, &img_gravestone_left);
	loadimage(&img_selector_tip, _T("pvz/resources/selector_tip.png"));
	loadimage(&img_selector_background, _T("pvz/resources/selector_background.png"));
	loadimage(&img_1P_selector_btn_idle_right, _T("pvz/resources/1P_selector_btn_idle.png"));
	flip_image(&img_1P_selector_btn_idle_right, &img_1P_selector_btn_idle_left);
	loadimage(&img_1P_selector_btn_down_right, _T("pvz/resources/1P_selector_btn_down.png"));
	flip_image(&img_1P_selector_btn_down_right, &img_1P_selector_btn_down_left);
	loadimage(&img_2P_selector_btn_idle_right, _T("pvz/resources/2P_selector_btn_idle.png"));
	flip_image(&img_2P_selector_btn_idle_right, &img_2P_selector_btn_idle_left);
	loadimage(&img_2P_selector_btn_down_right, _T("pvz/resources/2P_selector_btn_down.png"));
	flip_image(&img_2P_selector_btn_down_right, &img_2P_selector_btn_down_left);
	loadimage(&img_peashooter_selector_background_right, _T("pvz/resources/peashooter_selector_background.png"));
	flip_image(&img_peashooter_selector_background_right, &img_peashooter_selector_background_left);
	loadimage(&img_sunflower_selector_background_right, _T("pvz/resources/sunflower_selector_background.png"));
	flip_image(&img_sunflower_selector_background_right, &img_sunflower_selector_background_left);

	loadimage(&img_sky, _T("pvz/resources/sky.png"));
	loadimage(&img_hills, _T("pvz/resources/hills.png"));
	loadimage(&img_platform_large, _T("pvz/resources/platform_large.png"));
	loadimage(&img_platform_small, _T("pvz/resources/platform_small.png"));

	loadimage(&img_1P_cursor, _T("pvz/resources/1P_cursor.png"));
	loadimage(&img_2P_cursor, _T("pvz/resources/2P_cursor.png"));

	atlas_peashooter_idle_right.load_from_file(_T("pvz/resources/peashooter_idle_%d.png"), 9);
	flip_atlas(atlas_peashooter_idle_right, atlas_peashooter_idle_left);
	atlas_peashooter_run_right.load_from_file(_T("pvz/resources/peashooter_run_%d.png"), 5);
	flip_atlas(atlas_peashooter_run_right, atlas_peashooter_run_left);
	atlas_peashooter_attack_ex_right.load_from_file(_T("pvz/resources/peashooter_attack_ex_%d.png"), 3);
	flip_atlas(atlas_peashooter_attack_ex_right, atlas_peashooter_attack_ex_left);
	atlas_peashooter_die_right.load_from_file(_T("pvz/resources/peashooter_die_%d.png"), 4);
	flip_atlas(atlas_peashooter_die_right, atlas_peashooter_die_left);

	atlas_sunflower_idle_right.load_from_file(_T("pvz/resources/sunflower_idle_%d.png"), 8);
	flip_atlas(atlas_sunflower_idle_right, atlas_sunflower_idle_left);
	atlas_sunflower_run_right.load_from_file(_T("pvz/resources/sunflower_run_%d.png"), 5);
	flip_atlas(atlas_sunflower_run_right, atlas_sunflower_run_left);
	atlas_sunflower_attack_ex_right.load_from_file(_T("pvz/resources/sunflower_attack_ex_%d.png"), 9);
	flip_atlas(atlas_sunflower_attack_ex_right, atlas_sunflower_attack_ex_left);
	atlas_sunflower_die_right.load_from_file(_T("pvz/resources/sunflower_die_%d.png"), 2);
	flip_atlas(atlas_sunflower_die_right, atlas_sunflower_die_left);

	loadimage(&img_1P_winner, _T("pvz/resources/1P_winner.png"));
	loadimage(&img_2P_winner, _T("pvz/resources/2P_winner.png"));
	loadimage(&img_winner_bar, _T("pvz/resources/winner_bar.png"));

	loadimage(&img_avatar_peashooter, _T("pvz/resources/avatar_peashooter.png"));
	loadimage(&img_avatar_sunflower, _T("pvz/resources/avatar_sunflower.png"));

	mciSendString(_T("open pvz/resources/bgm_game.mp3 alias bgm_game"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/bgm_menu.mp3 alias bgm_menu"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/pea_break_1.mp3 alias pea_break_1"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/pea_break_2.mp3 alias pea_break_2"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/pea_break_3.mp3 alias pea_break_3"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/pea_shoot_1.mp3 alias pea_shoot_1"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/pea_shoot_2.mp3 alias pea_shoot_2"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/pea_shoot_ex.mp3 alias pea_shoot_ex"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/sun_explode.mp3 alias sun_explode"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/sun_explode_ex.mp3 alias sun_explode_ex"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/sun_text.mp3 alias sun_text"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/ui_confirm.wav alias ui_confirm"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/ui_switch.wav alias ui_switch"), NULL, 0, NULL);
	mciSendString(_T("open pvz/resources/ui_win.wav alias ui_win"), NULL, 0, NULL);

}



SceneManager scene_manager;



int main() {
	ExMessage msg;
	const int FPS = 60;

	initgraph(1280, 720, EW_SHOWCONSOLE);

	BeginBatchDraw();

	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();

	scene_manager.set_current_scene(menu_scene);
	load_game_resources(); 
	initgraph(1280, 720, EW_SHOWCONSOLE);
	
	settextstyle(28, 0, _T("IPix"));
	setbkmode(TRANSPARENT);
	while (true) {
		DWORD frame_start_time = GetTickCount();

		while (peekmessage(&msg)) {
			scene_manager.on_input(msg);
		}
		static DWORD last_tick_time = GetTickCount();
		DWORD current_tick_time = GetTickCount();
		DWORD delta_tick = current_tick_time - last_tick_time;
		scene_manager.on_update(delta_tick);
		last_tick_time = current_tick_time;

		cleardevice();
		scene_manager.on_draw(main_camera);
		FlushBatchDraw();

		DWORD frame_end_time = GetTickCount();

		DWORD frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / FPS) {
			Sleep(1000 / FPS - frame_delta_time);
		}
	}
	EndBatchDraw();

	return 0;
}