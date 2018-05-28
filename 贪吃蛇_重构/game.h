#ifndef GAME_H
#define GAME_H

#include "windows.h"

class Game
{
private:
	HANDLE stdOut; //����̨���
	CONSOLE_CURSOR_INFO cursorInfo; //�����Ϣ�ṹ��

public:
	Game();
	virtual ~Game();

	void showCursor(bool isShow); //�Ƿ���ʾ���
	void moveCursor(int x, int y); //�ƶ���굽x��y��
};

#endif // !GAME_H
