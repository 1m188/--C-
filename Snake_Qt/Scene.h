#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "Window.h"

//������
class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(Window *parent);
	virtual ~Scene();

private:

public:
	virtual void init(); //��ʼ����ϷԪ�غ�����
	virtual void keyPressEvent(QKeyEvent *event) override; //�Ѱ����¼���д��public�£�ʹ���������ڷַ������¼���ʱ���ܹ����ó����İ�����Ӧ����
	virtual void keyReleaseEvent(QKeyEvent *event) override; //ͬ��
};

#endif // SCENE_H
