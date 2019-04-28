#include "CommonHeader.h"

Target::Target()
{
	m_Position = Vector2(0.9f, -0.9f);
	m_Scale = Vector2(0.1f, 0.1f);
	m_Color = Vector3(1, 1, 1);
}

Target::~Target()
{
}

void Target::Update(double TimePassed)
{
    GameObject::Update( TimePassed );
}

void Target::Draw(Vector2 campos)
{
    GameObject::Draw( campos );

    GLuint shaderprogram = g_pGame->GetShaderProgram();


	GLint ChangePosition = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ChangePosition");
	if (ChangePosition != -1)
	{
		glUniform2f(ChangePosition, m_Position.x, m_Position.y);
	}

	GLint ObjectScale = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ObjectScale");
	if (ObjectScale != -1)
	{
		glUniform2f(ObjectScale, m_Scale.x, m_Scale.y);
	}

	GLint Color = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_Color");
	if (Color != -1)
	{
		glUniform3f(Color, m_Color.x, m_Color.y, m_Color.z);
	}

    DrawTriangle( shaderprogram );
}


Vector2 Target::ObjectPosition()
{
	return m_Position;
}

Vector2 Target::ObjectScale()
{
	return m_Scale;
}
