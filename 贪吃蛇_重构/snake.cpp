#include "snake.h"

Snake::Snake() :pos({ {11,10},{10,10},{9,10} }), moveDir({ {0, -1}, { 0,1 }, { -1,0 }, { 1,0 } }), dir(Direction::right)
{

}

Snake::~Snake()
{

}

void Snake::move()
{
	//�ƶ�
	pos.pop_back(); //����β��
	std::pair<int, int> newHead(pos.front()); //��ԭ����ͷ��ʼ����ͷ
	//ԭ����ͷ���շ����ƶ�������ͷ
	newHead.first += moveDir[dir].first;
	newHead.second += moveDir[dir].second;
	//����ͷװ��ȥ��Ϊ��������ͷ
	pos.push_front(newHead);
}

void Snake::display(bool isDisplay)
{
	Console *console = Console::getInstance();
	//������������Ȼ�󰤸�����Ӧ��λ�������Ӧ���ַ�
	for (std::list<std::pair<int, int>>::const_iterator it = pos.cbegin(); it != pos.cend(); it++)
	{
		try
		{
			console->moveCursor(it->first, it->second);
		}
		catch (std::exception) //��������̨��С��Χ�Ĳ�������
		{
			continue;
		}
		if (isDisplay)
		{
			printf("#");
		}
		else
		{
			printf(" ");
		}
	}
}

void Snake::changeDir()
{
	//ת������
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		{
			if (dir != Direction::down)
			{
				dir = Direction::up;
			}
			break;
		}
		case 's':
		{
			if (dir != Direction::up)
			{
				dir = Direction::down;
			}
			break;
		}
		case 'a':
		{
			if (dir != Direction::right)
			{
				dir = Direction::left;
			}
			break;
		}
		case 'd':
		{
			if (dir != Direction::left)
			{
				dir = Direction::right;
			}
			break;
		}
		}
	}
}

bool Snake::isDead()
{
	//�ж�����
	return false;
}