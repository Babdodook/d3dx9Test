#include"Triangle.h"

CTriangle::CTriangle()
{

}

CTriangle::~CTriangle()
{

}

void CTriangle::OnInit(LPDIRECT3DDEVICE9 _pd3dDevice)
{
    this->m_pd3dDevice = _pd3dDevice;

    // Initialize three vertices for rendering a triangle
    CUSTOMVERTEX vertices[] =
    {
        { 150.0f,  50.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
        { 250.0f, 250.0f, 0.5f, 1.0f, 0xff00ff00, },
        {  50.0f, 250.0f, 0.5f, 1.0f, 0xff00ffff, },
    };

    // Create the vertex buffer. Here we are allocating enough memory
    // (from the default pool) to hold all our 3 custom vertices. We also
    // specify the FVF, so the vertex buffer knows what data it contains.
    m_pd3dDevice->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &m_pVB, NULL);

    // Now we fill the vertex buffer. To do this, we need to Lock() the VB to
    // gain access to the vertices. This mechanism is required becuase vertex
    // buffers may be in device memory.
    VOID* pVertices;
    m_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0);
    memcpy(pVertices, vertices, sizeof(vertices));
    m_pVB->Unlock();
}

void CTriangle::OnRender()
{
    m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(CUSTOMVERTEX));
    m_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
    m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

void CTriangle::OnRelease()
{
    if (m_pVB != NULL)
        m_pVB->Release();
}