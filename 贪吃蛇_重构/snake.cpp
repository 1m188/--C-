#include "Snake.h"
#include "Console.h"

Snake::Snake() :Snake({ 0,0 }, 0, 0)
{
}

Snake::Snake(std::pair<int, int> headPos, int bodyNum, int dir) : pos({}), moveDir({ {0, -1}, { 0,1 }, { -1,0 }, { 1,0 } }), dir(static_cast<Direction>((dir < 0 ? -dir : dir) % 4))
{
	//������ͷ���ꡢ��������ͳ�ʼ�����ʼ����������
	pos.push_back(headPos);
	for (int i = 0; i < bodyNum; i++)
	{
		pos.push_back({ pos.back().first - moveDir[this->dir].first, pos.back().second - moveDir[this->dir].second });
	}
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

void Snake::changeDir(char dir)
{
	//ת������
	//�жϴ������ķ����ַ�
	switch (dir)
	{
	case 'w':
	{
		if (this->dir != Direction::down)
		{
			this->dir = Direction::up;
		}
		break;
	}
	case 's':
	{
		if (this->dir != Direction::up)
		{
			this->dir = Direction::down;
		}
		break;
	}
	case 'a':
	{
		if (this->dir != Direction::right)
		{
			this->dir = Direction::left;
		}
		break;
	}
	case 'd':
	{
		if (this->dir != Direction::left)
		{
			this->dir = Direction::right;
		}
		break;
	}
	}
}

bool Snake::isDead(int up, int down, int left, int right)
{
	//��ȡ��ͷ
	std::pair<int, int> head = pos.front();
	//�ж���ͷ�Ƿ�ײ���߽�
	if (head.first <= left || head.first >= right || head.second <= up || head.second >= down)
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
		//�������ʳ��֮���������Ӷ��ٽ�
		for (int i = 0; i < food.getSection(); i++)
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
		}
		return true;
	}
	else
	{
		return false;
	}
}