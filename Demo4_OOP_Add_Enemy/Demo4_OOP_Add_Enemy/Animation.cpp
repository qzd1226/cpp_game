#include <iostream>
#include "Animation.h"


Animation::Animation(LPCTSTR path, int num, int interval)
{
	interval_ms = interval;

	TCHAR path_file[256];
	for (size_t i = 0; i < num; i++) {
		_stprintf_s(path_file, path, i);

		//��Ϊ��ָ��������new�����ڴ�
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file);
		frame_list.push_back(frame);
	}
}
//�����������������
Animation::~Animation() {
	//for (size_t i = 0; i < frame_list.size(); i++) {
	//	delete frame_list[i];
	//	frame_list[i] = nullptr; // ��ֹ����ָ��
	//}
}


#pragma comment(lib, "MSIMG32.LIB")
inline void putimage_alpha(int x, int y, IMAGE* img) {

	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}


void Animation::Play(int x, int y, int delta) {
	this->timer += delta;
	std::cout << "timer:" << this->timer << std::endl;
	if (this->timer >= interval_ms) {
		this->idx_frame = (this->idx_frame + 1) % this->frame_list.size();
		this->timer = 0;
	}
	//std::cout << this->frame_list.size() << std::endl;
	putimage_alpha(x, y, frame_list[idx_frame]);
	}

