#include "DifficultyChooseScene.h"
#include "Console.h"
#include "conio.h"

DifficultyChooseScene::DifficultyChooseScene()
{
}

DifficultyChooseScene::~DifficultyChooseScene()
{
}

void DifficultyChooseScene::init()
{
	Console *console = Console::getInstance();
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4);
	printf("�Ѷ�ѡ��");
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4 + 5);
	printf("1. ����");
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4 + 10);
	printf("2. ����");
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4 + 15);
	printf("3. ����");
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4 + 20);
	printf("4. ����");
}

int DifficultyChooseScene::run()
{
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == '1' || key == '2' || key == '3' || key == '4')
			{
				return key - '0' - 1;
			}
		}
		Sleep(1);
	}
}