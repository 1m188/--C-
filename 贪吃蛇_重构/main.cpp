#include "snake.h"
//#include "conio.h" //getch()���������ڽ�����ҵ���ʱ����

int main()
{
	Snake snake = Snake();
	snake.showCursor(false);

	while (true)
	{
		snake.display("#");
		Sleep(800);
		snake.display(" ");
		snake.move();
	}
	return 0;
}