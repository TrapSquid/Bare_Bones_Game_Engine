#include "CommonHeader.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(double TimePassed)
{
}

void GameObject::Draw(Vector2 campos)
{
    GLuint shaderprogram = g_pGame->GetShaderProgram();

    // use our shader.
    glUseProgram( shaderprogram );
}


void GameObject::SetPosition(Vector2 Pos)
{

}

void GameObject::SetScale(Vector2 Scale)
{

}

void GameObject::ResetObject()
{

}

Vector2 GameObject::ObjectPosition()
{
	return Vector2(1, 1);
}

Vector2 GameObject::ObjectScale()
{
	return Vector2(1, 1);
}

