#ifndef SPEEDCHOOSESCENE_H
#define SPEEDCHOOSESCENE_H

#include "Scene.h"

//����Ϸ��ѡ���ߵ������ٶȳ���
class SpeedChooseScene :public Scene
{
public:
	SpeedChooseScene();
	~SpeedChooseScene();

	void init() override; //��ʼ������
	int run() override; //���г���
};

#endif // !SPEEDCHOOSESCENE_H
