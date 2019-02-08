#include "spriteRenderer.h"
#include "glErrorCheck.h"

SpriteRenderer::SpriteRenderer(Shader& shader)
{
	mShader = shader;
	initData();
}

void SpriteRenderer::drawSprite(Texture& texture, Vector2 position, float rotate, Vector2 size, Vector3 color)
{
	mShader.bind();
	Matrix4 model;
	model.translate(Vector3(position, 0.0f));

	model.translate(Vector3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model.rotate(rotate, Vector3(0.0f, 0.0f, 1.0f));
	model.translate(Vector3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	model.scale(Vector3(size, 1.0f));

	mShader.setUniformMatrix4fv("uModel", model);
	mShader.setUniformVector3f("uColor", color);

	texture.bind(0);

	GLCall(glBindVertexArray(mQuadVAO));
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
	GLCall(glBindVertexArray(0));
}

void SpriteRenderer::initData()
{
	float verticies[] =
	{
		//position		//texture
		0.0f, 0.0f,		0.0f, 0.0f,
		1.0f, 0.0f,		1.0f, 0.0f,
		1.0f, 1.0f,		1.0f, 1.0f,

		1.0f, 1.0f,		1.0f, 1.0f,
		0.0f, 1.0f,		0.0f, 1.0f,
		0.0f, 0.0f,		0.0f, 0.0f
	};

	GLCall(glGenVertexArrays(1, &mQuadVAO));
	GLCall(glBindVertexArray(mQuadVAO));

	unsigned int vbo;
	GLCall(glGenBuffers(1, &vbo));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 4 * sizeof(float), verticies, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCall(glBindVertexArray(0));
}
