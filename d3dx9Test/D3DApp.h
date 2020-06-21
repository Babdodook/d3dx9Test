#pragma once
#include<d3d9.h>

class CD3DApp 
{
protected:
	LPDIRECT3D9			m_pD3D;			// Used to create the D3DDevice
	LPDIRECT3DDEVICE9	m_pd3dDevice;	// Our rendering device
	HWND m_hWnd;

protected:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnRelease() = 0;

public:
	HRESULT InitD3D(HWND hWnd);
	VOID Update();
	VOID Render();
	VOID Cleanup();

public:
	CD3DApp();
	~CD3DApp();
};