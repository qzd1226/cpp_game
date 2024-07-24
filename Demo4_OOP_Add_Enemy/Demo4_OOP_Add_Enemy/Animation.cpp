#include <iostream>
#include "Animation.h"


Animation::Animation(LPCTSTR path, int num, int interval)
{
	interval_ms = interval;

	TCHAR path_file[256];
	for (size_t i = 0; i < num; i++) {
		_stprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file);
		frame_list.push_back(frame);
	}
}
// clear memory 
Animation::~Animation() {
	//for (size_t i = 0; i < frame_list.size(); i++) {
	//	delete frame_list[i];
	//	frame_list[i] = nullptr; // ·ÀÖ¹Ðü¹ÒÖ¸Õë
	//}
}


#pragma comment(lib, "MSIMG32.LIB")
void Animation::putimage_alpha(int x, int y, IMAGE* img) {

	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}


void Animation::Play(int x, int y, int delta) {
	
	Animation::timer += delta;
	std::cout << "idx_frame" << this-> idx_frame << std::endl;
	if (Animation::timer >= interval_ms) {
		this->idx_frame = (this->idx_frame + 1) % this->frame_list.size();
		Animation::timer = 0;
	}
	putimage_alpha(x, y, frame_list[this->idx_frame]);
	}


