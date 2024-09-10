#include "Ingame.h"
#include "Include.h"
#include "Device.h"

void Ingame::Initialize()
{
	// ����(2D����)���� ����ߴ� ��ȯ
	// ����(��) �����̽� -> ���� ��ȯ

	// �̹��� �߰������� ������ ��ȯ (3D ������ 2D�� ��Ÿ���� ���� ��ȯ)
	// �� ��ȯ -> �������� ��ȯ
	// �� ��ȯ�� ���� ���� �� ī�޶� �����ϰ�,
	// �������� ��ȯ�� ���� ī�޶� � ������ ���带 ������ �������� ���� (���� - Orthographic, ���� - Perspective)

	// �� ��ȯ�� ���� �� ����� ����
	// ī�޶��� ��ġ�� ��Ÿ���� ���� -> eye
	// ī�޶� �ٶ󺸰� �ִ� ������ ��Ÿ���� ���� -> lookAt
	// ���� �󿡼� ���� y��(����)�� ����Ű�� ũ�Ⱑ 1�� ���� -> up
	// ���� 3���� ���͸� ���� �� ����� ������

	// up ������ ���� ����
	// up ���͸� ���� ī�޶��� ���� ���� ����� �۾��� ��

	// �� ��� 4x4
	// right.x,   right.y,   right.z,   0		<- ī�޶��� ���� x��
	// up.x,	  up.y,	     up.z,	    0		<- ī�޶��� ���� y��
	// forward.x, forward.y, forward.z, 0		<- ī�޶��� ���� z��
	// eye.x,	  eye.y,	 eye.z,		1		<- ī�޶��� ��ġ

	// ���ӿ��� �Ϲ������� ���� ���Ǵ� ���� ����� 2����
	// Orthographic		<- ���ٹ� ���� X
	// Perspective		<- ���ٹ� ���� O

	// Perspective �������� ���� ��ķ� ���� �𵨵��� ũ�Ⱑ �Ÿ��� ���� �ٸ��� ����
	// 1. ��Ⱦ�� (Aspect ratio) -> ��ġ���� �ٸ� ��Ⱦ�� ���� x, y ���� ���� (�Ϲ������� ���� fov�� ����ϰ� �׶��� aspective ratio = width / height)
	// 2. �þ߰� (FOV : Field Of View) ���� -> �þ߰��� ���� ��ü�� �� ���� �Ǵ� �� ���� ���� ��
	//										  �þ߰��� ���ؼ��� x, y ���� ����
	// 3. ����ȭ : x(-1 ~ 1), y(-1 ~ 1), z(-1 ~ 1) ��ǥ���� ����ȭ����, NDC(����ȭ�� ��ġ ����, ī�޶� ���� �׷����� ����ü �������� ����)�� ����

	// ����Ʈ (viewport)
	// ��ġ�� �������� ��ǥ ü��� ��ȯ
	// �⺻������ Ŭ���̾�Ʈ �ػ󵵷� ����

	// ī�޶��� ��ġ
	eye = D3DXVECTOR3(0, 0, -40.f);

	// ī�޶� ���� ����
	lookAt = D3DXVECTOR3(0, 0, 0);

	// ī�޶��� ���� ����
	up = D3DXVECTOR3(0, 1, 0);

	// ������ ���� ī�޶��� ���� ���͸� ����� ��
	// �� ��� ���� (�޼���ǥ�� ����)
	D3DXMatrixLookAtLH(&view, &eye, &lookAt, &up);
	// ������ �� ����� ����
	auto device = GET_SINGLE(Device)->GetDevice();
	device->SetTransform(D3DTS_VIEW, &view);

	// ���� ���
	D3DXMatrixPerspectiveFovLH(&projection, D3DX_PI * .5f, 1, 1, 100);
	// ������ ���� ����� ��ġ�� ����
	device->SetTransform(D3DTS_PROJECTION, &projection);

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	// Ŭ���̾�Ʈ �ػ󵵸� ������� �� ����Ʈ ����
	D3DVIEWPORT9 vp = { 0, 0, rc.right - rc.left, rc.bottom - rc.top, 0, 1 };
	// ������ ����Ʈ ����
	device->SetViewport(&vp);

	shape.Initialize();
	shape.shapeNum = 1;
}

int Ingame::Update()
{
	shape.Update();

	return 0;
}

void Ingame::Render()
{
	shape.Render();
}

void Ingame::Release()
{
	shape.Release();
}

Ingame::Ingame()
{
}

Ingame::~Ingame()
{
    Release();
}
