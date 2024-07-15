#include <graphics.h>


#include <iostream>

int main()
{
	// x,y为圆心位置
	int x = 300;
	int y = 300;

	initgraph(1200, 720);
	while (true) {
		// 消息处理（鼠标键盘消息）
		ExMessage msg;
		while (peekmessage(&msg)) {
			if (msg.message == WM_MOUSEMOVE)
			{
				x = msg.x;
				y = msg.y;
			}
		}
		cleardevice();
		solidcircle(x, y, 100);
		FlushBatchDraw();

	}
	return 0;
}
