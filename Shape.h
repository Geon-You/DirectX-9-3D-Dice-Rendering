#pragma once
#include "Include.h"

class Shape
{
public:
	int shapeNum; // 해당 필드값으로 어떤 메시를 그릴 것인지 결정
	D3DXVECTOR3 pos; // 위치
	D3DXVECTOR3 angle; // 회전
	D3DXVECTOR3 scale; // 크기

private:
	LPDIRECT3DTEXTURE9 texture; // 텍스쳐
	IDirect3DVertexBuffer9* vb; // 버텍스 버퍼

public:
	void Initialize();
	void Update();
	void Render();
	void Release();
};

