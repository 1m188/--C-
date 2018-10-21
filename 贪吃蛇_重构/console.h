#ifndef CONSOLE_H
#define CONSOLE_H

#include "windows.h"
#include "string"
#include "algorithm"

//����̨���ݵ�����
class Console final
{
private:
	Console(); //��ֹ�ⲿ�Զ�����

	static Console *instance; //Ψһʵ����ָ��
	HANDLE stdOut; //����̨���

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
};

#endif // !CONSOLE_H
