#ifndef DIFFICULTYCHOOSESCENE_H
#define DIFFICULTYCHOOSESCENE_H

#include "Scene.h"

//����Ϸ��ѡ���ߵ������ٶȳ���
class DifficultyChooseScene :public Scene
{
public:
	DifficultyChooseScene();
	~DifficultyChooseScene();

	void init() override; //��ʼ������
	int run() override; //���г���
};

#endif // !DIFFICULTYCHOOSESCENE_H
