#include "snake.h"

Snake::Snake() :Game(), pos({}), moveDir({ {0, -1}, { 0,1 }, { -1,0 }, { 1,0 } }), dir(Direction::right)
{
	pos.push_back({ 11,10 });
	pos.push_back({ 10,10 });
	pos.push_back({ 9,10 });
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

	//ת������

	//�ж�����
}

void Snake::display(char *c)
{
	//������������Ȼ�󰤸�����Ӧ��λ�������Ӧ���ַ�
	for (std::list<std::pair<int, int>>::const_iterator it = pos.begin(); it != pos.end(); it++)
	{
		moveCursor(it->first, it->second);
		printf(c);
	}
}