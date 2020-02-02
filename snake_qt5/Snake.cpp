#include "Snake.h"

Snake::Snake() :Snake({}, 0, 3)
{

}

Snake::Snake(QPair<int, int> head, int sectionNum, int nowDir) : pos({}), dirChange({ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } }), nowDir(Dir::right)
{
	//ȷ����ǰ����
	nowDir = (nowDir >= 0 ? nowDir : -nowDir) % 4;
	this->nowDir = static_cast<Dir>(nowDir);

	//��ʼ����������
	pos.append(head);
	for (int i = 0; i < sectionNum - 1; i++)
	{
		QPair<int, int> last = pos.last();
		last.first -= dirChange[this->nowDir].first;
		last.second -= dirChange[this->nowDir].second;
		pos.append(last);
	}
}

Snake::~Snake()
{

}

const QVector<QPair<int, int>> Snake::getPos() const
{
	return pos;
}

void Snake::move()
{
	pos.pop_back(); //�Ƴ����һ��
	QPair<int, int> newHead(pos.at(0)); //ȡͷ����������ͷ
	//����Ӧ��xy�ı仯�ӵ���ͷ��
	newHead.first += dirChange[nowDir].first;
	newHead.second += dirChange[nowDir].second;
	//����ͷ��ͷ��ѹ�������������飬��Ϊ��������ͷ
	pos.push_front(newHead);
}

bool Snake::isDead(int up, int down, int left, int right)
{
	//�ж��Ƿ�ײ��ǽ
	if (pos[0].first<left || pos[0].first>right || pos[0].second<up || pos[0].second>down)
	{
		return true;
	}
	//�����ж��Ƿ�������ײ
	else
	{
		for (int i = 1; i < pos.size(); i++)
		{
			if (pos[0].first == pos[i].first&&pos[0].second == pos[i].second)
			{
				return true;
			}
		}
		return false;
	}
}

void Snake::setNowDir(int nowDir)
{
	this->nowDir = static_cast<Dir>(nowDir % 4);
}

bool Snake::eatFood(Food food)
{
	if (pos[0].first == food.getPos().first&&pos[0].second == food.getPos().second)
	{
		//��һ��ʳ��������Ӧ�Ľ���
		for (int i = 0; i < food.getBodyGrowth(); i++)
		{
			QPair<int, int> last = pos[pos.size() - 1]; //��ǰ���һ��
			QPair<int, int> secondLast = pos[pos.size() - 2]; //��ǰ�����ڶ���
			QPair<int, int> newLast = last; //�µ����һ��
			newLast.first += last.first - secondLast.first;
			newLast.second += last.second - secondLast.second;
			pos.append(newLast);
		}
		return true;
	}
	else
	{
		return false;
	}
}