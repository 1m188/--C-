#ifndef SNAKE_H
#define SNAKE_H

#include "Food.h"
#include "list"
#include "vector"

//��
class Snake
{
private:
	std::list<std::pair<int, int>> pos; //��������
	std::vector<std::pair<int, int>> moveDir; //�ƶ���ʱ���xy�仯����
	const enum Direction //����
	{
		up,
		down,
		left,
		right,
	};
	Direction dir; //��ǰ�����������������moveDir���Եõ���ǰ���ƶ�������任��

public:
	Snake();
	//�����ʼ��ͷ���ꡢ�����������ʼ��������ʼ���ߵ������Ϣ
	Snake(std::pair<int, int> headPos, int bodyNum, int dir);
	~Snake();

	void move(); //�ƶ�
	const std::list<std::pair<int, int>> getPos()const { return pos; } //��ȡ���������б�
	void changeDir(char dir); //ת���ƶ�����
	bool isDead(int up, int down, int left, int right); //�ж�����
	bool isEatFood(Food food); //�ж��Ƿ�Ե�ʳ��
};

#endif // !SNAKE_H
