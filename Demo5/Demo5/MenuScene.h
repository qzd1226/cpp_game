#pragma once
#include "Scene.h"
#include "SceneManager.h"

#include <iostream>

extern SceneManager scene_manager;
class MenuScene : public Scene
{

public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter() {
		std::cout << "enter main menu" << std::endl;
	}
	void on_update() {
		std::cout << "updating enter main menu" << std::endl;
	}
	void on_draw() {
		std::cout << "drawing main menu" << std::endl;
	}
	void on_input(const ExMessage& msg) {
		//std::cout << "input message:" << &msg << std::endl;
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}
	void on_exit() {
		std::cout << "exiting main menu" << std::endl;
	}


private:

};

