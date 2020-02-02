#ifndef FOOD_H
#define FOOD_H

//ʳ��
class Food
{
private:
	//ʳ��ĵ�ǰ����
	int x;
	int y;
	//�������ʳ��֮�����Ӷ��ٽ�
	int section;

public:
	Food();
	~Food();

	void updatePos(int up, int down, int left, int right); //����ʳ������
	//��ȡ��ǰʳ������
	const int getX() const { return x; }
	const int getY() const { return y; }
	//���ó��˸�ʳ��֮�����Ӷ��ٽ�
	void setSection(int section);
	//��ȡ���˸�ʳ��֮�����Ӷ��ٽ�
	int getSection();
};

#endif // !FOOD_H
