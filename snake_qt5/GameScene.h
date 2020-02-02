#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "Snake.h"
#include "Food.h"

//��Ϸ������
class GameScene : public Scene
{
	Q_OBJECT

public:
	GameScene(Window *parent);
	~GameScene();

private:
	int lineNum; //��ͼ��Ҫ����������Ŀ
	double interval; //����������֮��ļ��

	//��
	Snake snake;
	//ʳ��
	Food food;

	//��ǰ����
	int nowScore;
	//ÿ�γԵ�ʳ���ʱ��������Ӷ���
	int scoreGrowth;

	//֡��
	int fps;
	//����ˢ�¶�ʱ��
	QTimer *paintTimer;

public:
	void init(int difficulty); //��ʼ����Ϸ���ݣ������Ѷ�ϵ����ͬ����ͬ�Σ����ؼ̳еĺ�����
	void keyPressEvent(QKeyEvent *) override; //��д�Ը����ض��İ��¼��¼����ֲ�ͬ����Ϊ
	void keyReleaseEvent(QKeyEvent *event) override; //...�ͷ�...

protected:
	void paintEvent(QPaintEvent *) override; //��д���ƺ����Ի��Ƶ�ͼ����

	private slots:
	void updateSnake(); //��ÿһ֡�����»���
};

#endif // GAMESCENE_H
