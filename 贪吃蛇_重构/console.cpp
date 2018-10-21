#include "Console.h"

//��ʼ������ģʽ�Ļ�ȡ������ָ��
Console *Console::instance = nullptr;

Console::Console() :stdOut(GetStdHandle(STD_OUTPUT_HANDLE))
{

}

Console & Console::operator=(const Console &)
{
	return *this;
}

Console::~Console()
{

}

Console *Console::getInstance()
{
	//�������Ϊ��
	if (instance == nullptr)
	{
		//���쵥��
		instance = new Console();
	}
	//���շ������赥��
	return instance;
}

void Console::showCursor(bool isShow)
{
	//����һ�������Ϣ�ṹ��
	CONSOLE_CURSOR_INFO info = {};
	//��ȡ��ǰ�����Ϣ
	GetConsoleCursorInfo(stdOut, &info);
	//������ʾ�������ع��
	info.bVisible = isShow;
	//���ù����Ϣ
	SetConsoleCursorInfo(stdOut, &info);
}

void Console::moveCursor(int x, int y)
{
	//���ƶ��������곬���߽���׳��쳣
	if (x < 0 || x >= getWindowWidth() || y < 0 || y >= getWindowHeight())
	{
		throw std::exception("args out of range");
	}
	else
	{
		COORD coord = {};
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(stdOut, coord);
	}
}

void Console::clearScreen()
{
	system("cls");
}

void Console::setWindowSize(int width, int height)
{
	//���Ҫ���õĿ�Ⱥ͸߶Ⱥ���
	if (width > 0 && height > 0)
	{
		//����ͨ��system���������ÿ���̨��С����֪��Ϊʲôֱ�����û�������С���У�����
		//���������ַ���
		std::string w = "";
		while (width)
		{
			w += width % 10 + '0';
			width /= 10;
		}
		std::reverse(w.begin(), w.end());

		std::string h = "";
		while (height)
		{
			h += height % 10 + '0';
			height /= 10;
		}
		std::reverse(h.begin(), h.end());

		system(("mode con cols=" + w + " lines=" + h).c_str()); //system�������ÿ���̨��С
	}
	else //�Ƿ������׳��쳣
	{
		throw std::exception("args out of range");
	}
}

int Console::getWindowWidth()
{
	//��ȡ��ǰ����̨��������Ϣ
	CONSOLE_SCREEN_BUFFER_INFO info = {};
	GetConsoleScreenBufferInfo(stdOut, &info);
	return info.dwSize.X; //���ؿ���̨���ڿ��
}

int Console::getWindowHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(stdOut, &info);
	return info.dwSize.Y; //���ؿ���̨���ڸ߶�
}

void Console::setWindowTitle(std::string title)
{
	system((std::string("title ") + title).c_str());
}

std::string Console::getWindowTitle()
{
	char titleTemp[1024]{};
	GetConsoleTitleA(titleTemp, 1024);
	return std::string(titleTemp);
}