#pragma once
#include <iostream>
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() {
		std::cout << "enter game scene" << std::endl;
	}
	void on_update() {
		std::cout << "game is running" << std::endl;
	}
	void on_draw() {
		outtextxy(10, 10, _T("Draw game scene"));
	}
	void on_input(const ExMessage& msg) {
		std::cout << "game: input message:" << &msg << std::endl;
	}
	void on_exit() {
		std::cout << "exiting game scene" << std::endl;
	}
};

