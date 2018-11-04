#include "Food.h"
#include "Console.h"
#include "stdlib.h"
#include "time.h"

Food::Food() :x(0), y(0), section(1)
{

}

Food::~Food()
{

}

void Food::display(bool isDisplay)
{
	Console::getInstance()->moveCursor(x, y);
	if (isDisplay)
	{
		printf("*");
	}
	else
	{
		printf(" ");
	}
}

void Food::updatePos(int up, int down, int left, int right)
{
	int newX = 0, newY = 0;
	//���ɳ����ڵ�ͼ�߽�֮�ڵ�����
	//ֱ�����ɺ�֮ǰ��ʳ�����겻ͬ������Ϊֹ
	while (true)
	{
		srand(time(0));
		newX = rand() % (right - left - 1) + left + 1;
		srand(time(0));
		newY = rand() % (down - up - 1) + up + 1;
		if (newX != x && newY != y)
		{
			break;
		}
	}
	x = newX;
	y = newY;
}

void Food::setSection(int section)
{
	this->section = section;
}

int Food::getSection()
{
	return section;
}