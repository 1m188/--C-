#include "Config.h"
#include "fstream"
#include "Console.h"

Config *Config::instance = nullptr; //��ʼ������ָ��

Config::Config() :highestScore(0), foreColor(color::BrightWhite), backgroundColor(color::Black)
{
}

Config::~Config()
{
}

Config * Config::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Config();
	}
	return instance;
}

void Config::init()
{
	//����ļ���������ᴴ��һ���յ������ļ���ֻ����
	std::ifstream in;
	in.open("config.ini");
	if (!in)
	{
		std::ofstream out;
		out.open("config.ini");
		out.close();
	}
	else
	{
		//��ȡ�ļ�����
		in >> highestScore; //��ȡ����ʼ����߷�
		//��ȡǰ��ɫ�ͱ���ɫ
		int temp = 0;
		in >> temp;
		foreColor = static_cast<color>(temp);
		in >> temp;
		backgroundColor = static_cast<color>(temp);
	}
	Console::getInstance()->setWindowColor(foreColor, backgroundColor); //��ʼ��ǰ��ɫ�ͱ���ɫ
	in.close();
}

void Config::end()
{
	//����֮ǰ����init֮��ض����������ļ�������ֱ�Ӵ򿪣������������
	//֮�����������������뱣��
	std::ofstream out;
	out.open("config.ini", std::ios::trunc);

	out << highestScore; //���벢������߷�
	out << ' ';
	out << foreColor; //���벢����ǰ��ɫ
	out << ' ';
	out << backgroundColor; //���벢���汳��ɫ

	out.close();
}