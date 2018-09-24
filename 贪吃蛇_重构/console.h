#ifndef CONSOLE_H
#define CONSOLE_H

#include "windows.h"
#include "string"
#include "algorithm"

//����̨���ݵ�����
class Console final
{
private:
	Console(); //��ֹ�Զ�����

	static Console *instance; //Ψһʵ����ָ��
	HANDLE stdOut; //����̨���

public:
	~Console();

	static Console *getInstance(); //��ȡ����
	static void deleteInstance(); //ɾ������
	void showCursor(bool isShow); //�Ƿ���ʾ���
	void moveCursor(int x, int y); //�ƶ����
	int getWindowWidth(); //��ȡ����̨���ڿ��
	int getWindowHeight(); //��ȡ����̨���ڸ߶�
	void setWindowSize(int width, int height); //���ÿ���̨���ڴ�С
};

#endif // !CONSOLE_H

