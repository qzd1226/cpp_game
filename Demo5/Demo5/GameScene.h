#pragma once
#include <iostream>
#include "Scene.h"
#include "SceneManager.h"
#include "camera.h"

extern SceneManager scene_manager;

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() {
		std::cout << "enter game scene" << std::endl;
	}
	void on_update(int delta) {
		std::cout << "game is running" << std::endl;
	}
	void on_draw(const Camera& camera) {
		outtextxy(10, 10, _T("Draw game scene"));
	}
	void on_input(const ExMessage& msg) {
		std::cout << "game: input message:" << &msg << std::endl;
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}
	void on_exit() {
		std::cout << "exiting game scene" << std::endl;
	}
};

