#include "GameScene.h"
#include "Console.h"
#include "conio.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init(int timeout)
{
	//ʵ���������ϷԪ��
	snake = Snake({ 11,10 }, 2, 3);
	food = Food();
	score = 0;
	isAcc = false;
	this->timeout = timeout;

	Console *console = Console::getInstance();

	//��ͼ�ϱ߽�
	console->moveCursor(3, 2);
	for (int i = 2; i < console->getWindowWidth() - 4; i++)
	{
		printf("_");
	}
	//��ͼ�±߽�
	console->moveCursor(3, console->getWindowHeight() - 2);
	for (int i = 2; i < console->getWindowWidth() - 4; i++)
	{
		printf("~");
	}
	//��ͼ��߽�
	for (int i = 3; i < console->getWindowHeight() - 2; i++)
	{
		console->moveCursor(2, i);
		printf("|");
	}
	//��ͼ�ұ߽�
	for (int i = 3; i < console->getWindowHeight() - 2; i++)
	{
		console->moveCursor(console->getWindowWidth() - 3, i);
		printf("|");
	}

	//�÷���Ϣ
	console->moveCursor(5, 1);
	printf("�÷֣�%d", score);
}

int GameScene::run()
{
	Console *console = Console::getInstance();

	//��ȡ��ͼ�߽�
	int up = 2;
	int down = console->getWindowHeight() - 2;
	int left = 2;
	int right = console->getWindowWidth() - 3;

	//��ʼ��ʳ������
	food.updatePos(up, down, left, right);
	food.display(true); //��ʾʳ��

	//������Ϸѭ��
	while (true)
	{
		snake.display(true); //��ʾ����
		Sleep(timeout); //�ӳ���ʾ
		snake.display(false); //��������
		//��ȡ�жϰ�����������Ϸ���˵Ļ���
		if (_kbhit())
		{
			int key = _getch();
			//�ı��ߵ����з���
			if (key == 'w' || key == 'a' || key == 's' || key == 'd')
			{
				snake.changeDir(key); //�ı䷽��
			}
			//������µ��ǿո���ı��ߵ���������
			else if (key == ' ')
			{
				if (isAcc)
				{
					timeout *= 3;
				}
				else
				{
					timeout /= 3;
				}
				isAcc = !isAcc;
			}
		}
		snake.move(); //�ƶ�
		//�ж�����
		if (snake.isDead(up, down, left, right))
		{
			break;
		}
		//�ж��Ƿ�Ե�ʳ��
		if (snake.isEatFood(food))
		{
			food.updatePos(up, down, left, right); //����ʳ������
			food.display(true);
			//���µ÷����
			score++;
			console->moveCursor(5, 1);
			printf("�÷֣�%d", score);
		}
	}
	return score;
}