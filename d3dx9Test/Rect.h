#pragma once

#include<d3d9.h>
#include <d3dx9math.h>



class CRect {
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DINDEXBUFFER9 m_pIB;
	LPDIRECT3DDEVICE9	m_pd3dDevice;
public:
	CRect();
	~CRect();

	void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice);
	void OnRender();
	void OnRelease();

	void SetupMatrix();
};