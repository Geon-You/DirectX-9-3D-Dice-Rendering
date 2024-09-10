#pragma once
#include "Scene.h"
#include "Shape.h"

class Ingame :
    public Scene
{
private:
    D3DXVECTOR3 eye, lookAt, up; // ī�޶��� ��ġ, ī�޶� �ٶ󺸴� ����, ���忡���� ���� ����
    D3DXMATRIX view, projection; // ��, �������� ���
    Shape shape;

public:
    void Initialize() override;
    int Update() override;
    void Render() override;
    void Release() override;

public:
    Ingame();
    virtual ~Ingame();
};

