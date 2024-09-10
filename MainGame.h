#pragma once
#include "Include.h"

class Scene;

class MainGame
{
private:
	Scene* scene;

public:
	void Initialize(); // �ʱ�ȭ
	void Update(); // ���� �� ���� ����
	void Render(); // ���� �� �׸���
	void Release(); // �޸� ����

public:
	MainGame();
	~MainGame();
};

