#include "Food.h"
#include "QTime"

Food::Food() :pos({}), bodyGrowth(1)
{

}

Food::~Food()
{

}

const QPair<int, int> Food::getPos() const
{
	return pos;
}

const int Food::getBodyGrowth() const
{
	return bodyGrowth;
}

void Food::setBodyGrowth(int bodyGrowth)
{
	this->bodyGrowth = bodyGrowth;
}

void Food::updatePos(int up, int down, int left, int right, QVector<QPair<int, int>> snakePos)
{
	//��ʼ�����������
	qsrand(QTime::currentTime().msec());
again:
	//��������µ�����
	int newX = qrand() % (right - left + 1);
	int newY = qrand() % (down - up + 1);
	//�����ԭ����������ͬ�����¼���
	if (newX == pos.first&&newY == pos.second)
	{
		goto again;
	}
	//����к������غϵ�������Ҳ���¼���
	for (auto it = snakePos.cbegin(); it < snakePos.cend(); it++)
	{
		if (newX == it->first&&newY == it->second)
		{
			goto again;
		}
	}
	//��������
	pos.first = newX;
	pos.second = newY;
}