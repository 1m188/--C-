#include "GameOverScene.h"
#include "Console.h"
#include "conio.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

int GameOverScene::run()
{
	//��������Ϣ
	Console::getInstance()->moveCursor(0, 0);
	printf("�����~");
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