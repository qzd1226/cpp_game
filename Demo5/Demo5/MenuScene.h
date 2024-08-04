#pragma once
#include "Scene.h"

#include <iostream>
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
		std::cout << "input message:" << &msg << std::endl;
	}
	void on_exit() {
		std::cout << "exiting main menu" << std::endl;
	}


private:

};

