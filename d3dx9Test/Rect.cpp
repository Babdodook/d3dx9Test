#include"Rect.h"

// A structure for our custom vertex type
struct CUSTOMVERTEX
{
	//FLOAT x, y, z; // The transformed position for the vertex
	D3DXVECTOR3 position;
	DWORD color;        // The vertex color
};

// Our custom FVF, which describes our custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

CRect::CRect()
{

}

CRect::~CRect()
{

}

void CRect::OnInit(LPDIRECT3DDEVICE9 _pd3dDevice)
{
	this->m_pd3dDevice = _pd3dDevice;

	// Initialize three vertices for rendering a triangle
	CUSTOMVERTEX vertices[] =
	{
		// x, y, z, rhw, color
		{  D3DXVECTOR3(-1.0f,  1.0f, -1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
		{  D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
		{  D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
		{  D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,

		{  D3DXVECTOR3(-1.0f,  -1.0f, -1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
		{  D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
		{  D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
		{  D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DCOLOR_RGBA(255,255,255,255), } ,
	};

	WORD Indices[] =
	{
		0,1,4,
		1,5,4,
		1,7,5,
		1,3,7,
		0,2,1,
		2,3,1,
		2,4,6,
		2,0,4,
		3,6,7,
		3,2,6,
		4,7,6,
		4,5,7,
	};

	// Create the vertex buffer. Here we are allocating enough memory
	// (from the default pool) to hold all our 3 custom vertices. We also
	// specify the FVF, so the vertex buffer knows what data it contains.
	m_pd3dDevice->CreateVertexBuffer(sizeof(vertices), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &m_pVB, NULL);

	// Now we fill the vertex buffer. To do this, we need to Lock() the VB to
	// gain access to the vertices. This mechanism is required becuase vertex
	// buffers may be in device memory.
	VOID* pVertices;
	m_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0);
	memcpy(pVertices, vertices, sizeof(vertices));
	m_pVB->Unlock();

	m_pd3dDevice->CreateIndexBuffer(sizeof(Indices), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_pIB, NULL);

	VOID* pIndices;
	m_pIB->Lock(0, sizeof(Indices), (void**)&pIndices, 0);
	memcpy(pIndices, Indices, sizeof(Indices));
	m_pIB->Unlock();
}

void CRect::OnRender()
{
	SetupMatrix();

	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	m_pd3dDevice->SetIndices(m_pIB);

	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(CUSTOMVERTEX));
	m_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	m_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 6*2);
}

void CRect::OnRelease()
{
	if (m_pVB != NULL)
		m_pVB->Release();
	if (m_pIB != NULL)
		m_pIB->Release();
}

void CRect::SetupMatrix()
{
	// 월드 변환, 회전변환
	D3DXMATRIX m_matWorld;
	UINT iTime = timeGetTime() % 1000;
	FLOAT fAngle = iTime * (2.0f * D3DX_PI) / 1000.0f;
	float angle = 45;
	D3DXMatrixRotationY(&m_matWorld, fAngle);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &m_matWorld);

	// 뷰 변환
	D3DXVECTOR3 vEyePt(0.0f, 3.0f, -10.0f);
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	m_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);

	// 투영 변환
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.5f, 1.0f, 100.0f);
	m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}