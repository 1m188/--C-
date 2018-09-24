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
	}

	//ɾ������
	console->deleteInstance();

	return 0;
}