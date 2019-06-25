#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Window.h"
#include "Scene.h"

//������
class Director
{
private:
	Director(); //��ֹ�Զ����ⲿ����

	static Director *instance; //�������

	Window *window; //��Ϸ����ָ��
	Scene *nowScene; //��ǰ����Ӧ�ĳ���

public:
	~Director();
	Director(const Director &) = delete;
	Director &operator=(const Director &) = delete;

	static Director *getInstance(); //��ȡ�������

	void setWindow(Window *window); //������Ϸ����ָ��
	Window *getWindow(); //��ȡ��Ϸ����ָ��
	void setNowScene(Scene *scene); //���õ�ǰ����Ӧ����
	Scene *getNowScene(); //��ȡ��ǰ����Ӧ����
};

#endif // !DIRECTOR_H
