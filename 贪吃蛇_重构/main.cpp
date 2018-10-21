#include "Console.h"
#include "Config.h"
#include "StartScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "HighestScoreScene.h"

int main()
{
	//��ȡ��������̨����
	Console *console = Console::getInstance();
	//��ʼ����Ϸ���������
	Config::getInstance();
	//���ÿ���̨��С
	console->setWindowSize(100, 50);
	//���ÿ���̨����
	console->setWindowTitle("̰����");
	//���ع����ʾ
	console->showCursor(false);

	while (true)
	{
		//��Ϸ��ʼ�˵�����
		StartScene startScene;
		//��ʼ�˵�������ʼ��
		startScene.init();
		//��ȡ��ʼ�˵��������а�������
		int startSceneRunResult = startScene.run();

		//�������ȥ�ļ�Ϊ1�����������Ϸ
		if (startSceneRunResult == '1')
		{
			console->clearScreen();
			//��Ϸ������
			GameScene gameScene;
			gameScene.init(); //��ʼ����Ϸ������
			gameScene.run(); //������Ϸ������
			console->clearScreen();
			//��Ϸ��������
			GameOverScene gameOverScene;
			gameOverScene.init(); //��ʼ����Ϸ��������
			gameOverScene.run(); //������Ϸ��������
			console->clearScreen();
		}
		//�������ȥ�ļ�Ϊ2������ʾ��߷�
		else if (startSceneRunResult == '2')
		{
			console->clearScreen();
			HighestScoreScene highestScoreScene;
			highestScoreScene.init();
			highestScoreScene.run();
			console->clearScreen();
		}
		//�������ȥ�ļ�Ϊ4�����˳���Ϸ
		else if (startSceneRunResult == '4')
		{
			break;
		}
	}

	return 0;
}