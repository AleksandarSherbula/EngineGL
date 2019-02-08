#pragma once

#include "window.h"

class Game
{
private:
	bool mKeys[1024];
	const char* mTitle;
	float mWidth, mHeight;
	Window mGameWindow;

	void init();
	void initResources();
	void processInput(float dt);
	void update(float dt);
	void render();
public:
	Game(const char* title, int width, int height);
	~Game();
	void start();
};