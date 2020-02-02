#ifndef SNAKE_H
#define SNAKE_H

#include "QVector"
#include "Food.h"

//����
class Snake
{
private:
	//��������
	QVector<QPair<int, int>> pos;

	//����
	const enum Dir
	{
		up,
		down,
		left,
		right,
	};
	QVector<QPair<int, int>> dirChange; //���ŷ����н���ʱ�������ı仯
	Dir nowDir; //��ǰ��ͷ����

public:
	Snake();
	Snake(QPair<int, int> head, int sectionNum, int nowDir);
	~Snake();

	//��ȡ��������
	const QVector<QPair<int, int>> getPos() const;

	//�ƶ�
	void move();
	//�Ƿ�����
	bool isDead(int up, int down, int left, int right);
	//���õ�ǰ����
	void setNowDir(int nowDir);
	//�Ե�ʳ��
	bool eatFood(Food food);
};

#endif // SNAKE_H
