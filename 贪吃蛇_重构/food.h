#ifndef FOOD_H
#define FOOD_H

//ʳ��
class Food
{
private:
	//ʳ��ĵ�ǰ����
	int x;
	int y;

public:
	Food();
	~Food();

	void display(bool isDisplay); //��ʾ�������أ�
	void updatePos(); //����ʳ������
	//��ȡ��ǰʳ������
	const int getX() const { return x; }
	const int getY() const { return y; }
};

#endif // !FOOD_H
