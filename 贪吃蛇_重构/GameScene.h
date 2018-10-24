#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Snake.h"
#include "Food.h"
#include "Scene.h"

//��Ϸ������
class GameScene :public Scene
{
private:
	Snake snake; //��
	Food food; //ʳ��
	int score; //�÷�

public:
	GameScene();
	~GameScene();

	void init() override; //������ʼ��
	int run() override; //��������
};

#endif // !GAMESCENE_H
