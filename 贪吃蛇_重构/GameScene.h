#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "snake.h"
#include "food.h"

//��Ϸ������
class GameScene
{
private:
	Snake snake; //��
	Food food; //ʳ��

public:
	GameScene();
	~GameScene();

	void init(); //������ʼ��
	int run(); //��������
};

#endif // !GAMESCENE_H
