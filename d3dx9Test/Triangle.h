#pragma once

#include<d3d9.h>

// A structure for our custom vertex type
struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw; // The transformed position for the vertex
	DWORD color;        // The vertex color
};

// Our custom FVF, which describes our custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class CTriangle
{
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DDEVICE9	m_pd3dDevice;
public:
	CTriangle();
	~CTriangle();

	void OnInit(LPDIRECT3DDEVICE9 m_pd3dDevice);
	void OnRender();
	void OnRelease();
};