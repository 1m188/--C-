#include "StartScene.h"
#include "Console.h"
#include "conio.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::init()
{
	Console *console = Console::getInstance();
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4);
	printf("̰ �� ��");
	console->moveCursor(console->getWindowWidth() / 2 - 5, console->getWindowHeight() / 4 + 4);
	printf("1. ����Ϸ");
	console->moveCursor(console->getWindowWidth() / 2 - 5, console->getWindowHeight() / 4 + 8);
	printf("2. ��߷�");
	console->moveCursor(console->getWindowWidth() / 2 - 5, console->getWindowHeight() / 4 + 12);
	printf("3. ����");
	console->moveCursor(console->getWindowWidth() / 2 - 5, console->getWindowHeight() / 4 + 16);
	printf("4. �˳���Ϸ");
}

int StartScene::run()
{
	while (true)
	{
		//����а������µĻ�
		if (_kbhit())
		{
			//���ذ��µİ���������ַ�0�Ĵ�С����������µ������ֵĻ����ظ������ַ���int����
			return _getch() - '0';
		}
		Sleep(1);
	}
}