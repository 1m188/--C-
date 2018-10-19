#include "snake.h"

Snake::Snake() :pos({ {11,10},{10,10},{9,10} }), moveDir({ {0, -1}, { 0,1 }, { -1,0 }, { 1,0 } }), dir(Direction::right)
{

}

Snake & Snake::operator=(Snake & snake)
{
	this->pos = snake.pos;
	this->dir = snake.dir;
	return *this;
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
	for (auto it = pos.cbegin(); it != pos.cend(); it++)
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
	if (_kbhit()) //����а������µĻ�
	{
		switch (_getch()) //���ȡ���������жϽ�Ҫת���ķ���
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
	//��ȡ��ͷ
	std::pair<int, int> head = pos.front();
	//�ж���ͷ�Ƿ�ײ���߽�
	if (head.first < 0 || head.first >= Console::getInstance()->getWindowWidth() || head.second < 0 || head.second >= Console::getInstance()->getWindowHeight())
	{
		return true;
	}
	//�ж���ͷ�Ƿ�ײ���Լ�������
	else
	{
		//����ͷ֮���һ����ʼ�ж�������еĻ���
		auto it = pos.cbegin();
		it++;
		for (; it != pos.cend(); it++)
		{
			//�������ͷ�ص�
			if (it->first == head.first&&it->second == head.second)
			{
				return true;
			}
		}
	}
	//����û��
	return false;
}

bool Snake::isEatFood(Food food)
{
	//����Ե���
	if (pos.front().first == food.getX() && pos.front().second == food.getY())
	{
		//��ȡβ��
		std::pair<int, int> last = pos.back();
		//��ȡ�����ڶ���
		pos.pop_back();
		std::pair<int, int> lastSecond = pos.back();
		//���°�β�Ͱ���ȥ
		pos.push_back(last);
		//�µ�β��
		std::pair<int, int> newLast{};
		//�����µ�β�͵�λ��
		newLast.first = last.first + last.first - lastSecond.first;
		newLast.second = last.second + last.second - lastSecond.second;
		//��װ
		pos.push_back(newLast);
		return true;
	}
	else
	{
		return false;
	}
}