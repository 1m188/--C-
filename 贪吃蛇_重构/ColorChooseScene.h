#ifndef COLORCHOOSESCENE
#define COLORCHOOSESCENE

#include "Scene.h"

//ǰ��ɫ������ɫ��ѡ�񳡾�
class ColorChooseScene :public Scene
{
private:
	//ģʽ����ζ�ŵ�ǰ������ǰ��ɫѡ���Ǳ���ɫ��ѡ��
	//Ϊ'1'��ǰ��ɫѡ��Ϊ'2'�Ǳ���ɫѡ��
	int mode;

public:
	ColorChooseScene(int mode);
	~ColorChooseScene();

	void init() override;
	int run() override;
};

#endif // !COLORCHOOSESCENE
