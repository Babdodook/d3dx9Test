#pragma once
#include"D3DApp.h"
#include"Triangle.h"

class CGame : public CD3DApp 
{
private:
	CTriangle m_Triangle;

private:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	CGame();
	~CGame();
};