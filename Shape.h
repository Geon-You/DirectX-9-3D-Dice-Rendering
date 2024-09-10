#pragma once
#include "Include.h"

class Shape
{
public:
	int shapeNum; // �ش� �ʵ尪���� � �޽ø� �׸� ������ ����
	D3DXVECTOR3 pos; // ��ġ
	D3DXVECTOR3 angle; // ȸ��
	D3DXVECTOR3 scale; // ũ��

private:
	LPDIRECT3DTEXTURE9 texture; // �ؽ���
	IDirect3DVertexBuffer9* vb; // ���ؽ� ����

public:
	void Initialize();
	void Update();
	void Render();
	void Release();
};

