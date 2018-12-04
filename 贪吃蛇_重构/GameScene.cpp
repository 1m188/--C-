#include "GameScene.h"
#include "Console.h"
#include "conio.h"
#include "algorithm"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init(int difficulty)
{
	//ʵ���������ϷԪ��
	snake = Snake({ 11,10 }, 2, 3);
	food = Food();
	food.setSection(difficulty + 1);
	score = 0;
	timeout = 120 - 40 * difficulty;
	isAcc = false;
	activeScreenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	backScreenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
}

int GameScene::run()
{
	Console *console = Console::getInstance();

	//��ȡ��ͼ�߽�
	int up = 2;
	int down = console->getWindowHeight() - 2;
	int left = 2;
	int right = console->getWindowWidth() - 3;

	//��ʼ��ʳ������
	food.updatePos(up, down, left, right);

	//�������õ�˫��������������������һ��ǰ̨һ����̨�����⻹��һ����ʾ��ͨ�����
	//����̨��Ļ�������������һ����Ⱦ�Ļ�����õ������������Լ��ı�����̨��������
	//֮�����ǰ��̨�������������棬��ԭ���Ŀ���̨��Ļ��������û�������ˡ�
	//��ʼ��˫���������������
	std::string data;
	COORD coord = {};
	DWORD bytes = 0;

	//������Ϸѭ��
	while (true)
	{
		//��ȡ�жϰ�����������Ϸ���˵Ļ���
		if (_kbhit())
		{
			int key = _getch();
			//�ı��ߵ����з���
			if (key == 'w' || key == 'a' || key == 's' || key == 'd')
			{
				snake.changeDir(key); //�ı䷽��
			}
			//������µ��ǿո���ı��ߵ���������
			else if (key == ' ')
			{
				if (isAcc)
				{
					timeout *= 3;
				}
				else
				{
					timeout /= 3;
				}
				isAcc = !isAcc;
			}
		}

		snake.move(); //�ƶ�

		//�ж�����
		if (snake.isDead(up, down, left, right))
		{
			//һ����Ϸ�����������������������������ԭ���Ļ������������Ҫ��ԭ���Ļ�����������
			//��������Ȼ��Щ��������������Ĺ�궨λʲô�ľͲ�������
			SetConsoleActiveScreenBuffer(console->getStdHandle());
			break;
		}

		//�ж��Ƿ�Ե�ʳ��
		if (snake.isEatFood(food))
		{
			food.updatePos(up, down, left, right); //����ʳ������
			//���µ÷����
			score += food.getSection();
		}

		//��ʾ
		//��ʾ����
		auto snakePos = snake.getPos();
		for (auto &i : snakePos)
		{
			coord.X = i.first;
			coord.Y = i.second;
			WriteConsoleOutputCharacterA(backScreenBuffer, "#", 1, coord, &bytes);
		}

		//��ʾʳ��
		coord.X = food.getX();
		coord.Y = food.getY();
		WriteConsoleOutputCharacterA(backScreenBuffer, "*", 1, coord, &bytes);

		//��ʾ����
		coord.X = 5;
		coord.Y = 1;
		data = "�÷֣�" + std::to_string(score);
		WriteConsoleOutputCharacterA(backScreenBuffer, data.c_str(), data.size(), coord, &bytes);

		//��ʾ��ͼ�߽�
		//��ͼ�ϱ߽�
		coord.X = 3;
		coord.Y = 2;
		data.clear();
		for (int i = 2; i < console->getWindowWidth() - 4; i++)
		{
			data.append("_");
		}
		WriteConsoleOutputCharacterA(backScreenBuffer, data.c_str(), data.size(), coord, &bytes);
		//��ͼ�±߽�
		coord.X = 3;
		coord.Y = console->getWindowHeight() - 2;
		data.clear();
		for (int i = 2; i < console->getWindowWidth() - 4; i++)
		{
			data.append("~");
		}
		WriteConsoleOutputCharacterA(backScreenBuffer, data.c_str(), data.size(), coord, &bytes);
		//��ͼ��߽�
		coord.X = 2;
		for (int i = 3; i < console->getWindowHeight() - 2; i++)
		{
			coord.Y = i;
			WriteConsoleOutputCharacterA(backScreenBuffer, "|", 1, coord, &bytes);
		}
		//��ͼ�ұ߽�
		coord.X = console->getWindowWidth() - 3;
		for (int i = 3; i < console->getWindowHeight() - 2; i++)
		{
			coord.Y = i;
			WriteConsoleOutputCharacterA(backScreenBuffer, "|", 1, coord, &bytes);
		}

		//˫����
		SetConsoleActiveScreenBuffer(backScreenBuffer); //����Ⱦ�õĺ�̨�������滻��ǰ̨ȥ
		std::swap(activeScreenBuffer, backScreenBuffer); //��ǰ̨�Ļ��������ɺ�̨������
		//����ֻ�����һ����̨��������������ԭ����Ĭ��ǰ̨������������˫���壬���ǲ�֪��Ϊʲô��
		//����������Ļ�һ������������պ�̨�Ļ����������ܹ���ǰ̨���ۿ����ģ�����˴�������˸��
		//��ϸ������������Ĭ�ϵĻ�������������ζ�������ǰ̨���޷�����ģ��µ���ǰ̨û�л���
		//����ì��
		//��պ�̨������
		data.clear();
		for (int i = 0; i < console->getWindowWidth(); i++)
		{
			data.append(" ");
		}
		coord.X = 0;
		for (int i = 0; i < console->getWindowHeight(); i++)
		{
			coord.Y = i;
			WriteConsoleOutputCharacterA(backScreenBuffer, data.c_str(), data.size(), coord, &bytes);
		}

		Sleep(timeout); //�ӳ���ʾ
	}
	return score;
}