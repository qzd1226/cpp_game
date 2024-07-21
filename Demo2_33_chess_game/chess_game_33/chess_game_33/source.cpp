#include <graphics.h>


#include <iostream>

//while (true) {
//	��ȡ����();
//	��������();
//	���ƻ���();
//	��
//�ͷ���Դ();

char board_data[3][3] =
{
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'},
};


char current_piece = 'O';
// ���ָ�����ӵ�����Ƿ��ʤ
bool CheckWin(char c)
{
	if (board_data[0][0] == c && board_data[0][1] == c && board_data[0][2] == c)
		return true;
	if (board_data[1][0] == c && board_data[1][1] == c && board_data[1][2] == c)
		return true;
	if (board_data[2][0] == c && board_data[2][1] == c && board_data[2][2] == c)
		return true;
	if (board_data[0][0] == c && board_data[1][0] == c && board_data[2][0] == c)
		return true;
	if (board_data[0][1] == c && board_data[1][1] == c && board_data[2][1] == c)
		return true;
	if (board_data[0][2] == c && board_data[1][2] == c && board_data[2][2] == c)
		return true;
	if (board_data[0][0] == c && board_data[1][1] == c && board_data[2][2] == c)
		return true;
	if (board_data[0][2] == c && board_data[1][1] == c && board_data[2][0] == c)
		return true;
	return false;
}

// ��⵱ǰ�Ƿ����ƽ��
bool CheckDraw()
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			if (board_data[i][j] == '-') {
				return false;
			}
		}
	}
	return true;
}

//��������
void DrawBoard()
{
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}

//��������
void DrawPiece()
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			switch (board_data[i][j])
			{
			case 'O':
				circle(200 * j + 100, 200 * i + 100, 100);
				break;
			case 'X':
				line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
				line(200 * (j + 1), 200 * i, 200 * j, 200 * (i + 1));
				break;
			case '-':
				break;
			}
		}
	}

}

//������ʾ��Ϣ
void DrawTipText()
{
	static TCHAR str[64];
	_stprintf_s(str, _T("��ǰ��������:%c"), current_piece);
	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}
int main()
{
	// x,yΪԲ��λ��
	int x = 300;
	int y = 300;

	initgraph(600, 600);

	bool gameRuning = true;
	while (gameRuning) {

		DWORD start_time = GetTickCount();

		// ��Ϣ������������Ϣ��
		ExMessage msg;
		while (peekmessage(&msg)) {
			if (msg.message == WM_MOUSEMOVE)
			{
				x = msg.x;
				y = msg.y;

				int index_x = x / 200;
				int index_y = y / 200;

				//��������

				if (board_data[index_y][index_x] == '-')
				{
					board_data[index_y][index_x] = current_piece;

					//�л���������
					if (current_piece == 'O')
					{
						current_piece = 'X';
					}
					else
					{
						current_piece = 'O';
					}
				}
			}
		}
		cleardevice();

		DrawBoard();
		DrawPiece();
		DrawTipText();

		FlushBatchDraw();
		if (CheckWin('X'))
		{
			MessageBox(GetHWnd(), _T("X��һ�ʤ"), _T("��Ϸ����"), MB_OK);
			gameRuning = false;
		}
		else if (CheckWin('O'))
		{
			MessageBox(GetHWnd(), _T("O��һ�ʤ"), _T("��Ϸ����"), MB_OK);
			gameRuning = false;
		}
		else if (CheckDraw())
		{
			MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);
		}
		
		DWORD end_time = GetTickCount();
		if(end_time - start_time < 1000/60)
		{
			Sleep(1000 / 60 - (end_time - start_time));
		}

	}
	EndBatchDraw();
	return 0;
}
