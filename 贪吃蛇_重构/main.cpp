#include "console.h"
#include "GameScene.h"
#include "GameOverScene.h"

int main()
{
	//��ȡ��������̨����
	Console *console = Console::getInstance();
	//���ÿ���̨��С
	console->setWindowSize(100, 50);
	//���ع����ʾ
	console->showCursor(false);

	//��Ϸ������
	GameScene gameScene = GameScene();
	//��Ϸ��������
	GameOverScene gameOverScene = GameOverScene();
	while (true)
	{
		gameScene.init();
		gameScene.run();
		Console::getInstance()->clearScreen();
		gameOverScene.run();
		Console::getInstance()->clearScreen();
	}

	return 0;
}