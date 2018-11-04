#include "GameOverScene.h"
#include "Console.h"
#include "Config.h"
#include "conio.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::init(int score)
{
	Console *console = Console::getInstance();

	//��������Ϣ
	console->moveCursor(console->getWindowWidth() / 2 - 15, console->getWindowHeight() / 4 + 5);
	printf("ʤ���˱��ҳ��£���������������");
	console->moveCursor(console->getWindowWidth() / 2 - 6, console->getWindowHeight() / 4 + 8);
	printf("��ĵ÷֣�%d", score);
	//���Ϊ��߷�
	if (score > Config::getInstance()->highestScore)
	{
		printf("  (---��ϲ���Ϊ��߷֣�����)");
		//������߷�
		Config::getInstance()->highestScore = score;
	}
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 12);
	printf("��������������˵�...");
}

int GameOverScene::run()
{
	//�ó�����ͣ��������CPU���Ĺ��ߣ���ʹ��system��ԭ������������һ����
	//һ���а�����������հ�����������ѭ��
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