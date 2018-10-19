#ifndef SNAKE_H
#define SNAKE_H

#include "Console.h"
#include "Food.h"
#include "list"
#include "vector"
#include "conio.h"

//��
class Snake
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
	Snake &operator=(Snake &snake);
	~Snake();

	void move(); //�ƶ�
	void display(bool isDisplay); //�Ƿ���ʾ������������������������ˢ�£�
	void changeDir(); //ת���ƶ�����
	bool isDead(); //�ж�����
	bool isEatFood(Food food); //�ж��Ƿ�Ե�ʳ��
};

#endif // !SNAKE_H
