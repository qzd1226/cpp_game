#include <graphics.h>


#include <iostream>

int main()
{
	// x,yΪԲ��λ��
	int x = 300;
	int y = 300;

	initgraph(1200, 720);
	while (true) {
		// ��Ϣ������������Ϣ��
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
