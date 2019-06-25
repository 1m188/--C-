#ifndef CONFIG_H
#define CONFIG_H

#include "QString"

//������
class Config
{
private:
	Config(); //��ֹ�ⲿ�Զ�����

	static Config *instance; //����ָ��

	int highestScore; //��߷�
	QString highestScorePlayer; //��߷ֱ�����
	QString themeResourceUrl; //������Դurl

public:
	~Config();
	Config(const Config &) = delete;
	Config &operator=(const Config &) = delete;

	static Config *getInstance(); //��ȡ����ָ��

	void init(); //��ʼ����������
	void uninit(); //�����������

	void setHighestScore(int highestScore); //������߷�
	int getHighestScore(); //�����߷�
	void setHighestScorePlayer(QString highestScorePlayer); //������߷ֱ�����
	QString getHighestScorePlayer(); //��ȡ��߷ֱ�����
	void setTheme(QString themePath); //���õ�ǰ����
};

#endif // !CONFIG_H
