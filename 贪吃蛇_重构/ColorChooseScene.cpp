#include "ColorChooseScene.h"
#include "Console.h"
#include "Config.h"
#include "conio.h"

ColorChooseScene::ColorChooseScene(int mode) :mode(mode)
{
}

ColorChooseScene::~ColorChooseScene()
{
}

void ColorChooseScene::init()
{
	Console *console = Console::getInstance();
	console->moveCursor(console->getWindowWidth() / 2 - 4, console->getWindowHeight() / 4);
	//����ǰ������ɫѡ��ģʽ��ͬ�����ͬ�ı���
	if (mode == '1')
	{
		printf("ǰ��ɫѡ��");
	}
	else if (mode == '2')
	{
		printf("����ɫѡ��");
	}
	//�������ɫѡ��
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 4);
	printf("0. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 7);
	printf("1. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 10);
	printf("2. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 13);
	printf("3. ����ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 16);
	printf("4. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 19);
	printf("5. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 22);
	printf("6. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 - 10, console->getWindowHeight() / 4 + 25);
	printf("7. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 4);
	printf("8. ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 7);
	printf("9. ǳ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 10);
	printf("a. ǳ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 13);
	printf("b. ǳ����");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 16);
	printf("c. ǳ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 19);
	printf("d. ǳ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 22);
	printf("e. ǳ��ɫ");
	console->moveCursor(console->getWindowWidth() / 2 + 5, console->getWindowHeight() / 4 + 25);
	printf("f. ����ɫ");
}

int ColorChooseScene::run()
{
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			//�ж������Ƿ�Ϊ�ض�����������ǵĻ�����任�ɶ�Ӧ����
			if (key >= '0'&&key <= '9')
			{
				key -= '0';
			}
			else if (key >= 'a'&&key <= 'f')
			{
				key = key - 'a' + 10;
			}
			//���key�����任�Ļ�����Ӧ����������ж�����������һ���жϴ���
			if (key >= 0 && key <= 15)
			{
				//��ȡ��Ӧ�İ����任���ת��Ϊ��color���͵ı���
				Config::color color = static_cast<Config::color>(key);
				//ǰ��ɫ
				if (mode == '1')
				{
					//�����������е�ǰ��ɫ
					Config::getInstance()->foreColor = color;
					//�����������̨���ڵ�ǰ��ɫ
					Console::getInstance()->setWindowColor(color, Console::getInstance()->getWindowBackgroundColor());
				}
				//����ɫ
				else if (mode == '2')
				{
					//�����������еı���ɫ
					Config::getInstance()->backgroundColor = color;
					//�����������̨���ڵı���ɫ
					Console::getInstance()->setWindowColor(Console::getInstance()->getWindowForeColor(), color);
				}
				break;
			}
		}
		Sleep(1);
	}
	return Scene::run();
}