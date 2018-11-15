#pragma once
#include "SDL.h"
#include "LoaderParams.h"
#include <iostream>

class GameObject
{
public:
	void load(int x, int y, int width, int height,
		std::string textureID);
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams*pParams) {}
	virtual~GameObject() {}

	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};