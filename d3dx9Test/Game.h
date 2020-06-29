#pragma once
#include"D3DApp.h"
#include"Triangle.h"
#include"Rect.h"

class CGame : public CD3DApp 
{
private:
	CTriangle m_Triangle;
	CRect m_Rect;

private:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	CGame();
	~CGame();
};