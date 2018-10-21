#include "HighestScoreScene.h"
#include "Console.h"
#include "Config.h"
#include "conio.h"

HighestScoreScene::HighestScoreScene()
{
}

HighestScoreScene::~HighestScoreScene()
{
}

void HighestScoreScene::init()
{
	Console *console = Console::getInstance();
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4 + 5);
	printf("��߷֣�%d", Config::getInstance()->highestScore);
	console->moveCursor(console->getWindowWidth() / 2 - 9, console->getWindowHeight() / 4 + 10);
	printf("��������������˵�...");
}

int HighestScoreScene::run()
{
	//ѭ����ⰴ��������а������µ�ʱ������հ����������������������
	while (true)
	{
		if (_kbhit())
		{
			_getch();
			break;
		}
		Sleep(1);
	}
	return Scene::run();
}