#include "Config.h"
#include "fstream"

Config *Config::instance = nullptr; //��ʼ������ָ��

Config::Config() :highestScore(0)
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
		in.open("config.ini");
	}
	//��ȡ�ļ�����
	in >> highestScore; //��ȡ����ʼ����߷�
	in.close();
}

void Config::end()
{
	//����֮ǰ����init֮��ض����������ļ�������ֱ�Ӵ򿪣������������
	//֮�����������������뱣��
	std::ofstream out;
	out.open("config.ini", std::ios::trunc);
	out << highestScore; //���벢������߷�
	out.close();
}