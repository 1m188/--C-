#include "GameScene.h"
#include "Director.h"
#include "Config.h"
#include "StartScene.h"
#include "QPainter"
#include "QTimer"
#include "QKeyEvent"
#include "QMessageBox"
#include "QInputDialog"

GameScene::GameScene(Window *parent) :Scene(parent)
{

}

GameScene::~GameScene()
{
}

void GameScene::init(int difficulty)
{
	//��ʼ����Ϸ���ݲ�����
	//��ʼ����ͼ������Ŀ������
	lineNum = 25;
	interval = static_cast<double>(width()) / (lineNum + 1);

	//��ʼ����Ϸ֡��
	fps = 1000 / (200 - difficulty * 50);

	//��ʼ����
	snake = Snake({ 2,2 }, 2, 3);
	//��ʼ��ʳ��
	food.setBodyGrowth(difficulty + 1);
	food.updatePos(0, lineNum, 0, lineNum, snake.getPos());

	//��ʼ����ǰ����
	nowScore = 0;
	//��ʼ������������Ŀ
	scoreGrowth = difficulty + 1;

	//���ñ���
	setAutoFillBackground(true);
	setPalette(QColor(255, 255, 255));

	//��ʼ��������¶�ʱ������ʼ���½���
	paintTimer = new QTimer(this);
	connect(paintTimer, &QTimer::timeout, this, &GameScene::updateSnake);
	paintTimer->setInterval(1000 / fps);
	paintTimer->start();
}

void GameScene::updateSnake()
{
	//���ƶ�
	snake.move();

	//�ж��Ƿ�Ե�ʳ��
	if (snake.eatFood(food))
	{
		//����ˢ��
		nowScore += scoreGrowth;

		//����ʳ������
		food.updatePos(0, lineNum, 0, lineNum, snake.getPos());
	}

	//�ж�����
	if (snake.isDead(0, lineNum, 0, lineNum))
	{
		//ֹͣ���»���
		paintTimer->stop();

		//�ж������Ƿ�Ϊ��߷�
		if (nowScore > Config::getInstance()->getHighestScore())
		{
			//����߷ֺ���߷ֱ����߱����Config����
			Config::getInstance()->setHighestScore(nowScore);
			Config::getInstance()->setHighestScorePlayer(QInputDialog::getText(this, tr(u8"��߷�"), tr(u8"��ϲ��λ��������ķ����ǣ�%1���������������еļ�¼��Ϊ��߷֣����������¼����Ĵ�����").arg(nowScore)));
		}

		//�Ƿ�����һ��
		if (QMessageBox::information(this, tr(u8"��Ϸ����"), tr(u8"���꣬����ˣ�������շ����ǣ�%1���Ƿ�Ҫ���յ�ǰ�ٶ�����һ�֣�").arg(nowScore), QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
		{
			StartScene *startScene = new StartScene(Director::getInstance()->getWindow());
			Director::getInstance()->setNowScene(startScene);
			startScene->init();
			startScene->show();
			deleteLater();
			return;
		}
		//����һ�������³�ʼ����Ϸ���ݵ�����
		//��ʼ������
		nowScore = 0;

		//��ʼ��
		snake = Snake({ 2,2 }, 2, 3);

		//����ʳ������
		food.updatePos(0, lineNum, 0, lineNum, snake.getPos());

		//��ʼ���»���
		paintTimer->setInterval(1000 / fps);
		paintTimer->start();

		return;
	}

	//���ƻ���
	update();
}

void GameScene::paintEvent(QPaintEvent *event)
{
	QPainter *painter = new  QPainter(this);

	//���Ʊ�����
	for (int i = 1; i <= lineNum; i++)
	{
		painter->drawLine(0, i*interval, width(), i*interval);
		painter->drawLine(i*interval, 0, i*interval, height());
	}

	//��������
	painter->setPen(QPen(Qt::blue));
	painter->setBrush(QBrush(Qt::blue));
	for (QPair<int, int> pos : snake.getPos())
	{
		painter->drawRect(pos.first*interval, pos.second*interval, interval, interval);
	}

	//����ʳ��
	painter->setPen(QPen(Qt::red));
	painter->setBrush(QBrush(Qt::red));
	painter->drawRect(food.getPos().first*interval, food.getPos().second*interval, interval, interval);

	//���Ʒ���
	painter->setFont(QFont(u8"΢���ź�", 12));
	painter->drawText(0, 0, width(), 30, Qt::AlignCenter, QString(tr(u8"������%1").arg(nowScore)));

	painter->end();
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
	//��������
	//�������
	auto snakePos = snake.getPos();
	if (event->key() == Qt::Key_Up && snakePos[0].second - snakePos[1].second != 1)
	{
		snake.setNowDir(0);
	}
	else if (event->key() == Qt::Key_Down && snakePos[0].second - snakePos[1].second != -1)
	{
		snake.setNowDir(1);
	}
	else if (event->key() == Qt::Key_Left && snakePos[0].first - snakePos[1].first != 1)
	{
		snake.setNowDir(2);
	}
	else if (event->key() == Qt::Key_Right && snakePos[0].first - snakePos[1].first != -1)
	{
		snake.setNowDir(3);
	}
	//��ס�ո����
	else if (event->key() == Qt::Key_Space && !event->isAutoRepeat())
	{
		paintTimer->setInterval(paintTimer->interval() / 3);
	}
}

void GameScene::keyReleaseEvent(QKeyEvent * event)
{
	//�ͷſո�ص�ԭ�����ٶ�
	if (event->key() == Qt::Key_Space && !event->isAutoRepeat())
	{
		paintTimer->setInterval(paintTimer->interval() * 3);
	}
}