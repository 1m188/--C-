#ifndef HIGHESTSCORESCENE_H
#define HIGHESTSCORESCENE_H

#include "Scene.h"

class HighestScoreScene : public Scene
{
	Q_OBJECT

public:
	HighestScoreScene(Window *parent);
	~HighestScoreScene();
public:
	void init() override;

	private slots:
	void returnToStartSceneButtonClicked(); //�������ؿ�ʼ���水ť
};

#endif // HIGHESTSCORESCENE_H
