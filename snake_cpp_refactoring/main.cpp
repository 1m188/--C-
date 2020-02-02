#include "Console.h"
#include "Config.h"
#include "StartScene.h"
#include "DifficultyChooseScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "HighestScoreScene.h"
#include "SettingScene.h"
#include "ColorChooseScene.h"

int main()
{
	//��ȡ��������̨����
	Console *console = Console::getInstance();
	//���ÿ���̨��С
	console->setWindowSize(100, 50);
	//���ÿ���̨����
	console->setWindowTitle("̰����");
	//���ع����ʾ
	console->showCursor(false);

	//��ȡ��Ϸ����������ݵĵ���
	Config *config = Config::getInstance();
	//��ʼ��������Ϸ�����������
	config->init();

	//������Ϸѭ��
	while (true)
	{
		//��Ϸ��ʼ�˵�����
		StartScene startScene;
		//��ʼ�˵�������ʼ��
		startScene.init();
		//��ȡ��ʼ�˵��������а�������
		int startSceneRunResult = startScene.run();
		console->clearScreen();

		//�������ȥ�ļ�Ϊ1�����������Ϸ
		if (startSceneRunResult == '1')
		{
			//�Ѷ�ѡ�񳡾�
			DifficultyChooseScene difficultyChooseScene;
			difficultyChooseScene.init();
			int difficulty = difficultyChooseScene.run();
			console->clearScreen();
			if (difficulty != 3)
			{
				//��Ϸ������
				GameScene gameScene;
				gameScene.init(difficulty); //��ʼ����Ϸ������
				int score = gameScene.run(); //������Ϸ������
				console->clearScreen();
				//��Ϸ��������
				GameOverScene gameOverScene;
				gameOverScene.init(score); //��ʼ����Ϸ��������
				gameOverScene.run(); //������Ϸ��������
				console->clearScreen();
			}
			else
			{
				//��Ϸ��������
				GameOverScene gameOverScene;
				gameOverScene.init(0); //��ʼ����Ϸ��������
				gameOverScene.run(); //������Ϸ��������
				console->clearScreen();
			}
		}
		//�������ȥ�ļ�Ϊ2������ʾ��߷�
		else if (startSceneRunResult == '2')
		{
			//��߷ֳ���
			HighestScoreScene highestScoreScene;
			highestScoreScene.init();
			highestScoreScene.run();
			console->clearScreen();
		}
		//�������ȥ�ļ�λ3����������ó���
		else if (startSceneRunResult == '3')
		{
			//���ò˵�����
			SettingScene settingScene;
			settingScene.init();
			int settingKey = settingScene.run();
			console->clearScreen();
			//ǰ������ɫѡ�񳡾�
			ColorChooseScene colorChooseScene(settingKey);
			colorChooseScene.init();
			colorChooseScene.run();
			console->clearScreen();
		}
		//�������ȥ�ļ�Ϊ4�����˳���Ϸ
		else if (startSceneRunResult == '4')
		{
			break;
		}
	}

	//���´������Щ���س���������
	config->end();

	return 0;
}