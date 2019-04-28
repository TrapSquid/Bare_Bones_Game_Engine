#include "CommonHeader.h"
#include "RandomCodeFiles\functions.h"

Enemy::Enemy()
{
    m_EnemyPosition.x = CreateRandomNumber(-1000, 1000) * 0.001f;
    m_EnemyPosition.y = CreateRandomNumber(-1000, 1000) * 0.001f;

    m_EnemyScale = Vector2(0.1f, 0.1f);

	m_EnemyColor = Vector3(1, 0, 0);
}

Enemy::~Enemy()
{
}

void Enemy::Update(double TimePassed)
{
    GameObject::Update( TimePassed );
}

void Enemy::Draw(Vector2 campos)
{
    GameObject::Draw( campos );

    GLuint shaderprogram = g_pGame->GetShaderProgram();

	GLint ChangePosition = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ChangePosition");
	if (ChangePosition != -1)
	{
		glUniform2f(ChangePosition, m_EnemyPosition.x, m_EnemyPosition.y);
	}

	GLint ObjectScale = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ObjectScale");
	if (ObjectScale != -1)
	{
		glUniform2f(ObjectScale, m_EnemyScale.x, m_EnemyScale.y);
	}

	GLint Color = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_Color");
	if (Color != -1)
	{
		glUniform3f(Color, m_EnemyColor.x, m_EnemyColor.y, m_EnemyColor.z);
	}

    DrawTriangle( shaderprogram );
}



Vector2 Enemy::ObjectPosition()
{
	return m_EnemyPosition;
}


Vector2 Enemy::ObjectScale()
{
	return m_EnemyScale;
}

void Enemy::ResetObject()
{
    m_EnemyPosition.x = CreateRandomNumber(-1000, 1000) * 0.001f;
    m_EnemyPosition.y = CreateRandomNumber(-1000, 1000) * 0.001f;

    m_EnemyScale = Vector2(0.1f, 0.1f);
}