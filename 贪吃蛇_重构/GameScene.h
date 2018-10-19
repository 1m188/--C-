#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "snake.h"
#include "food.h"
#include "Scene.h"

//��Ϸ������
class GameScene :public Scene
{
private:
	Snake snake; //��
	Food food; //ʳ��

public:
	GameScene();
	~GameScene();

	void init() override; //������ʼ��
	int run() override; //��������
};

#endif // !GAMESCENE_H
