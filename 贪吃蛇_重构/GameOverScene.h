#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "Scene.h"

//��Ϸ��������
class GameOverScene :public Scene
{
private:
	int score; //��Ϸ�÷�

public:
	GameOverScene(int score);
	~GameOverScene();

	void init() override; //��ʼ����Ϸ��������
	int run() override; //��������
};

#endif // !GAMEOVERSCENE_H
