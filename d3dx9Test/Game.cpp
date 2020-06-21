#include"Game.h"

CGame::CGame()
{

}

CGame::~CGame()
{

}

void CGame::OnInit()
{
    m_Triangle.OnInit(m_pd3dDevice);
}

void CGame::OnUpdate()
{
}

void CGame::OnRender()
{
    m_Triangle.OnRender();
}

void CGame::OnRelease()
{
    m_Triangle.OnRelease();
}