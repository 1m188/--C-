#include "Director.h"

Director *Director::instance = nullptr; //��ʼ����ĵ������

Director::Director() :window(nullptr), nowScene(nullptr)
{
}

Director::~Director()
{
}

Director * Director::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Director();
	}
	return instance;
}

void Director::setWindow(Window * window)
{
	this->window = window;
}

Window * Director::getWindow()
{
	return window;
}

void Director::setNowScene(Scene * scene)
{
	nowScene = scene;
}

Scene * Director::getNowScene()
{
	return nowScene;
}