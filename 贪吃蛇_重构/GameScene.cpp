#include "GameScene.h"
#include "console.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init()
{
	snake = Snake();
	food = Food();
}

int GameScene::run()
{
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
		if (snake.isDead())
		{
			break;
		}
		//�ж��Ƿ�Ե�ʳ��
		if (snake.isEatFood(food))
		{
			food.updatePos(); //����ʳ������
		}
	}
	return 0; //���ﹹ�췵��ֵ��ԭ����Ϊ���ܹ����ⲿ���õĺ�run��������������run����������ȵ�
}