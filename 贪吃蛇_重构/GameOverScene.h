#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "Scene.h"

//��Ϸ��������
class GameOverScene :public Scene
{
public:
	GameOverScene();
	~GameOverScene();

	void init() override; //��ʼ����Ϸ��������
	int run() override; //��������
};

#endif // !GAMEOVERSCENE_H
