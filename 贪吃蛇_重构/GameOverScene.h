#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "Scene.h"

//��Ϸ��������
class GameOverScene :public Scene
{
private:

public:
	GameOverScene();
	~GameOverScene();

	void init(int score); //���س�ʼ����Ϸ��������
	int run() override; //��������
};

#endif // !GAMEOVERSCENE_H
