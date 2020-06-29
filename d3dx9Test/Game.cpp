#include"Game.h"

CGame::CGame()
{

}

CGame::~CGame()
{

}

void CGame::OnInit()
{
    m_Rect.OnInit(m_pd3dDevice);
    m_Triangle.OnInit(m_pd3dDevice);
}

void CGame::OnUpdate()
{
}

void CGame::OnRender()
{
    m_Rect.OnRender();
    m_Triangle.OnRender();
}

void CGame::OnRelease()
{
    m_Rect.OnRelease();
    m_Triangle.OnRelease();
}