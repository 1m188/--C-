#ifndef HIGHESTSCORESCENE_H
#define HIGHESTSCORESCENE_H

#include "Scene.h"

//��߷ֳ���
class HighestScoreScene :public Scene
{
public:
	HighestScoreScene();
	~HighestScoreScene();

	void init() override; //��ʼ����߷ֳ���
	int run() override; //������߷ֳ���
};

#endif // !HIGHESTSCORESCENE_H
