#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "Scene.h"

//��Ϸ��ʼ�˵�����
class StartScene :public Scene
{
public:
	StartScene();
	~StartScene();

	void init() override; //��ʼ����ʼ�˵�����
	int run() override; //���п�ʼ�˵�����
};

#endif // !STARTSCENE_H
