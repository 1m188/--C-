#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Snake.h"
#include "Food.h"
#include "Scene.h"
#include "windows.h"

//��Ϸ������
class GameScene :public Scene
{
private:
	Snake snake; //��
	Food food; //ʳ��
	int score; //�÷�
	int timeout; //ÿһ֡������ʾ���ӳ�ʱ��
	bool isAcc; //�Ƿ����ڼ���
	//˫����
	HANDLE activeScreenBuffer; //ǰ̨��Ļ������
	HANDLE backScreenBuffer; //��̨��Ļ������

public:
	GameScene();
	~GameScene();

	void init(int timeout); //���ػ���ͬ��������������ʼ��
	int run() override; //��������
};

#endif // !GAMESCENE_H
