#include "snake.h"
#include "console.h"
#include "food.h"

int main()
{
	//��ȡ��������̨����
	Console *console = Console::getInstance();
	//���ÿ���̨��С
	console->setWindowSize(100, 50);
	//���ع����ʾ
	console->showCursor(false);

	//��ʼ����
	Snake snake = Snake();
	//��ʼ��ʳ��
	Food food = Food();

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
			//������ϷԪ�أ������Ϣ
			snake.display(false);
			food.display(false);
			console->moveCursor(0, 0);
			printf("�����~");
			break;
		}
		//�ж��Ƿ�Ե�ʳ��
		if (snake.isEatFood(food))
		{
			food.updatePos(); //����ʳ������
		}
	}

	//ɾ����������̨����
	Console::deleteInstance();

	//�ó�����ͣ��������CPU���Ĺ��ߣ���ʹ��system��ԭ������������һ����
	while (1)
	{
		Sleep(1);
	}
	return 0;
}