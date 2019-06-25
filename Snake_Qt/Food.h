#ifndef FOOD_H
#define FOOD_H

#include "QVector"

//ʳ����
class Food
{
private:
	//ʳ������
	QPair<int, int> pos;

	//�Ե����ʳ���ʱ����������
	int bodyGrowth;

public:
	Food();
	~Food();

	//��ȡʳ������
	const QPair<int, int> getPos() const;
	//��ȡ��������
	const int getBodyGrowth() const;
	//������������
	void setBodyGrowth(int bodyGrowth);

	//����ʳ�����꣬�������Ϊ��������
	void updatePos(int up, int down, int left, int right, QVector<QPair<int, int>> snakePos);
};

#endif // FOOD_H
