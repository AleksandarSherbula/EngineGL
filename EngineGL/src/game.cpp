#include "game.h"
#include "gameObject.h"
#include "resourceManager.h"
#include "spriteRenderer.h"
#include "input.h"

SpriteRenderer* renderer;
GameObject* object;

Game::Game(const char* title, int width, int height)
	:mTitle(title), mWidth(width), mHeight(height)
{
	mGameWindow = Window(mTitle, mWidth, mHeight);
}

Game::~Game()
{
	delete renderer;
	glfwTerminate();
}

void Game::initResources()
{
	Matrix4 projection = Matrix4::orthographic(0.0f, (float)mWidth, (float)mHeight, 0.0f, -1.0f, 1.0f);

	ResourceManager::setShader("res/shaders/sprite.shader", "sprite");
	ResourceManager::setTexture("res/textures/block.png", "block", false);
	//ResourceManager::setTexture("res/textures/light_blue.jpg", false, "tetris_field");

	ResourceManager::getShader("sprite").bind();
	ResourceManager::getShader("sprite").setUniformMatrix4fv("uProjection", projection);
	ResourceManager::getShader("sprite").setUniformInteger("uImage", 0);

	renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
}

void Game::init()
{
	initResources();

	object = new GameObject(Vector2(300.0f, 200.0f), toRadians(45.0f),
		Vector2(200.0f, 200.0f), ResourceManager::getTexture("block"));
}

void Game::processInput(float dt)
{
	if (Input::Keys[GLFW_KEY_A])
	{
		object->mPosition.x -= 0.25f;
	}

	if (Input::Keys[GLFW_KEY_D])
	{
		object->mPosition.x += 0.25f;
	}

	if (Input::Keys[GLFW_KEY_A])
	{
		object->mPosition.x -= 0.25f;
	}

	if (Input::Keys[GLFW_KEY_S])
	{
		object->mPosition.y += 0.5f;
	}

	if (Input::Keys[GLFW_KEY_W])
	{
		object->mPosition.y -= 0.5f;
	}
	
}

void Game::update(float dt)
{
}

void Game::render()
{
	object->draw(*renderer);
}

void Game::start()
{
	init();

	while (!mGameWindow.closed())
	{
		processInput(0);

		mGameWindow.clear(0.0f, 0.8f, 1.0f, 1.0f);

		render();

		update(0);

		mGameWindow.update();
	}
}
