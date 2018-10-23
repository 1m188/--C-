#ifndef CONFIG_H
#define CONFIG_H

//����������Ϸ��ĳЩȫ�����ݵĵ�����
class Config
{
private:
	Config(); //��ֹ�ⲿ�Զ�����

	static Config *instance; //Ψһʵ�������

public:
	Config(const Config &) = delete; //��ֹ���ƹ���
	Config &operator=(const Config &) = delete; //��ֹ��ֵ����
	~Config();

	static Config *getInstance(); //��ȡ����
	void init(); //���ļ��г�ʼ���������
	void end(); //��Ϸ����֮������ݴ���

	int highestScore; //��߷�
};

#endif // !CONFIG_H
