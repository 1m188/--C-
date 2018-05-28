#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"
#include "list"
#include "vector"

class Snake :public Game
{
private:
	std::list<std::pair<int, int>> pos; //��������
	const std::vector<std::pair<int, int>> moveDir; //�ƶ���ʱ���xy�仯����
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
	~Snake();

	void move(); //�ƶ�
	void display(char *c); //���������괦��ʾ��Ӧ���ַ�����������������������ˢ�£�
};

#endif // !SNAKE_H
