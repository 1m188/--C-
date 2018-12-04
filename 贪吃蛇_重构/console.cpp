#include "Console.h"

//��ʼ������ģʽ�Ļ�ȡ������ָ��
Console *Console::instance = nullptr;

Console::Console() :stdOut(GetStdHandle(STD_OUTPUT_HANDLE)), colorIndex({ "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" })
{
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
	COORD coord = {};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(stdOut, coord);
}

void Console::clearScreen()
{
	std::string data;
	COORD coord = {};
	DWORD bytes = 0;
	for (int i = 0; i < getWindowWidth(); i++)
	{
		data.append(" ");
	}
	coord.X = 0;
	for (int i = 0; i < getWindowHeight(); i++)
	{
		coord.Y = i;
		WriteConsoleOutputCharacterA(stdOut, data.c_str(), data.size(), coord, &bytes);
	}
}

void Console::setWindowSize(int width, int height)
{
	//���ÿ���̨������Ϣ
	SMALL_RECT sr = { 0,0,static_cast<short>(width - 1) ,static_cast<short>(height - 1) };
	SetConsoleWindowInfo(stdOut, true, &sr);
	//���ÿ���̨��Ļ��������С
	COORD coord = { static_cast<short>(width),static_cast<short>(height) };
	SetConsoleScreenBufferSize(stdOut, coord);
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
	SetConsoleTitleA(title.c_str());
}

std::string Console::getWindowTitle()
{
	char titleTemp[1024]{};
	GetConsoleTitleA(titleTemp, 1024);
	return std::string(titleTemp);
}

void Console::setWindowColor(Config::color foreColor, Config::color backgroundColor)
{
	system(("color " + colorIndex[backgroundColor] + colorIndex[foreColor]).c_str());
}

Config::color Console::getWindowForeColor()
{
	return Config::getInstance()->foreColor;
}

Config::color Console::getWindowBackgroundColor()
{
	return Config::getInstance()->backgroundColor;
}