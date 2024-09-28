#pragma once

#include<functional>

class Timer
{
public:
	Timer() = default;
	~Timer() = default;

	void restart() {
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(int val) {
		wait_time = val;
	}

	void set_one_shot(bool flag) {
		one_shot = flag;
	}

	void set_callback(std::function<void()> callback) {
		this->callback = callback;
	}
	
	void pause() {
		paused = true;
	}

	void resume() {
		paused = false;
	}

	void on_update(int delta) {
		if (paused) {
			return;
		}
		pass_time += delta;
		if (pass_time >= wait_time) {
			if ((!one_shot || (one_shot && !shotted)) && callback) // if timer is not one time timer or is one time timer and has not been triggered
				callback();
			shotted = true;
			pass_time = 0;
		}
	}

private:
	int pass_time = 0;
	int wait_time = 0;
	bool paused = false;     // pause or not
	bool shotted = false;    // trigger or not
	bool one_shot = false;   // trigger once
	std::function<void()> callback;
};
