#include "Window.h"
#include "Director.h"
#include "StartScene.h"
#include "QApplication"
#include "QDeskTopWidget"

Window::Window() : QWidget(Q_NULLPTR)
{
	//��������
	setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_QuitOnClose, true);

	//���ô��ڱ���ʹ�С
	setWindowTitle(tr(u8"̰����"));
	setFixedSize(950, 950);

	//�ƶ����ڵ���Ļ����
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());
}

Window::~Window()
{
}

void Window::show()
{
	StartScene *startScene = new StartScene(this);
	Director::getInstance()->setNowScene(startScene);
	startScene->init();
	startScene->show();
	QWidget::show();
}

void Window::keyPressEvent(QKeyEvent * event)
{
	Director::getInstance()->getNowScene()->keyPressEvent(event);
}

void Window::keyReleaseEvent(QKeyEvent * event)
{
	Director::getInstance()->getNowScene()->keyReleaseEvent(event);
}