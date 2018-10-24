#include "GameScene.h"
#include "Console.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init()
{
	//��ͼ���Ʒֵ�����
	Console *console = Console::getInstance();
	//��ͼ�ϱ߽�
	console->moveCursor(2, 2);
	for (int i = 2; i < console->getWindowWidth() - 2; i++)
	{
		printf("_");
	}
	//��ͼ�±߽�
	console->moveCursor(2, console->getWindowHeight() - 2);
	for (int i = 2; i < console->getWindowWidth() - 2; i++)
	{
		printf("~");
	}
	//��ͼ��߽�
	for (int i = 2; i < console->getWindowHeight() - 2; i++)
	{
		console->moveCursor(2, i);
		printf("|");
	}
	//��ͼ�ұ߽�
	for (int i = 2; i < console->getWindowHeight() - 2; i++)
	{
		console->moveCursor(console->getWindowWidth() - 3, i);
		printf("|");
	}
	//�÷���Ϣ
	console->moveCursor(5, 1);
	printf("�÷֣�%d", score);

	//ʵ�����ߺ�ʳ��
	snake = Snake();
	food = Food();
	score = 0;
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

	//������Ϸѭ��
	while (true)
	{
		snake.display(true); //��ʾ����
		food.display(true); //��ʾʳ��
		Sleep(200); //�ӳ���ʾ
		snake.display(false); //��������
		food.display(false); //����ʳ��
		snake.changeDir(); //�ı䷽��
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
			//���µ÷����
			score++;
			console->moveCursor(5, 1);
			printf("�÷֣�%d", score);
		}
	}
	return score;
}