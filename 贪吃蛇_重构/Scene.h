#ifndef SCENE_H
#define SCENE_H

//������
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void init(); //������ʼ��
	virtual int run(); //���г���
};

#endif // !SCENE_H
