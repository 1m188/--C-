#ifndef CONSOLE_H
#define CONSOLE_H

#include "windows.h"
#include "string"
#include "algorithm"
#include "vector"
#include "Config.h"

//����̨���ݵ�����
class Console
{
private:
	Console(); //��ֹ�ⲿ�Զ�����

	static Console *instance; //Ψһʵ����ָ��
	HANDLE stdOut; //����̨���

	const std::vector<std::string> colorIndex; //����ɫö������������ɫ����

public:
	Console(const Console &) = delete; //��ֹ���ƹ���
	Console &operator=(const Console &) = delete; //��ֹ��ֵ����
	~Console();

	static Console *getInstance(); //��ȡ����

	void showCursor(bool isShow); //�Ƿ���ʾ���
	void moveCursor(int x, int y); //�ƶ����
	void clearScreen(); //����
	void setWindowSize(int width, int height); //���ÿ���̨���ڴ�С
	int getWindowWidth(); //��ȡ����̨���ڿ��
	int getWindowHeight(); //��ȡ����̨���ڸ߶�
	void setWindowTitle(std::string title); //���ô��ڱ���
	std::string getWindowTitle(); //��ȡ���ڱ���
	void setWindowColor(Config::color foreColor, Config::color backgroundColor); //���ô��ڵ�ǰ��ɫ�ͱ���ɫ
	Config::color getWindowForeColor(); //��ȡ����̨ǰ��ɫ
	Config::color getWindowBackgroundColor(); //��ȡ����̨����ɫ
};

#endif // !CONSOLE_H
