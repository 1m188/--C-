#include "SettingScene.h"
#include "Console.h"
#include "conio.h"

SettingScene::SettingScene()
{
}

SettingScene::~SettingScene()
{
}

void SettingScene::init()
{
	Console *console = Console::getInstance();
	//�����ѡ��
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4);
	printf("��Ϸ����");
	console->moveCursor(console->getWindowWidth() / 2 - 5, console->getWindowHeight() / 4 + 4);
	printf("1. ǰ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 5, console->getWindowHeight() / 4 + 8);
	printf("2. ����ɫ");
	//ע��
	console->moveCursor(console->getWindowWidth() / 2 - 15, console->getWindowHeight() / 4 + 12);
	printf("ע�⣺");
	console->moveCursor(console->getWindowWidth() / 2 - 15, console->getWindowHeight() / 4 + 14);
	printf("ǰ����ɫ���ܹ�����Ϊͬһ����ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 15, console->getWindowHeight() / 4 + 16);
	printf("��������Ϊͬһ����ɫ��ʱ��");
	console->moveCursor(console->getWindowWidth() / 2 - 15, console->getWindowHeight() / 4 + 18);
	printf("��Ӧ��ɫ�仯������һ��ǰ�򱳾�ɫ����Ϊ��ͬ��ɫ��ʱ����Ч");
}

int SettingScene::run()
{
	//��ѡ���˺��ʵİ���ѡ��֮��ͷ���
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == '1' || key == '2')
			{
				return key;
			}
		}
		Sleep(1);
	}
}