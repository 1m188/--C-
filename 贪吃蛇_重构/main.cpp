#include "snake.h"
#include "console.h"

int main()
{
	//��ȡ����̨����
	Console *console = Console::getInstance();
	//���ÿ���̨��С
	console->setWindowSize(100, 50);
	//���ع����ʾ
	console->showCursor(false);

	//��ʼ����
	Snake snake = Snake();

	//������Ϸѭ��
	while (true)
	{
		snake.display(true); //��ʾ����
		Sleep(200); //�ӳ���ʾ
		snake.display(false); //��������
		snake.changeDir(); //�ı䷽��
		snake.move(); //�ƶ�
		//�ж�����
		if (snake.isDead())
		{
			snake.display(false);
			console->moveCursor(0, 0);
			printf("�����~");
			break;
		}
	}

	//ɾ������
	Console::deleteInstance();

	//�ó�����ͣ��������CPU���Ĺ��ߣ���ʹ��system��ԭ������������һ����
	while (1)
	{
		Sleep(1);
	}
	return 0;
}