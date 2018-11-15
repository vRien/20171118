#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
private:
	Game() {};
	// create the s_pInstance member variable
	static Game* s_pInstance;
	// create the typedef
public:
	~Game() {};

	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
private:

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_player;
	GameObject* m_enemy;

};
typedef Game TheGame;