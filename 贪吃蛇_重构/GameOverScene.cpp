#include "GameOverScene.h"
#include "Console.h"
#include "conio.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::init()
{
	//��������Ϣ
	Console::getInstance()->moveCursor(0, 0);
	printf("�����~����������ص����˵�...��");
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