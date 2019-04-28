#include "CommonHeader.h"

Player::Player()
{
	//Sets up player movment.
	m_PlayerPosition = Vector2(0, 0);
	m_PlayerScale = Vector2(0.05f, 0.05f);
	m_Speed = 1;
	m_PlayerSpawnPoint = Vector2(0, 0);
	m_Hitmarked = false;
	m_PlayerCanMove = true;

	m_PlayerColor = Vector3(0, 1, 0);
}

Player::~Player()
{
}

void Player::Update(double TimePassed)
{
    GameObject::Update( TimePassed );

	if (m_PlayerCanMove)
	{
		if (g_KeyStates[VK_UP] && m_PlayerPosition.y < 1 - m_PlayerScale.y)
		{
			m_PlayerPosition.y += m_Speed * TimePassed;
		}
		else if (g_KeyStates[VK_DOWN] && m_PlayerPosition.y > -1 + m_PlayerScale.y)
		{
			m_PlayerPosition.y -= m_Speed * TimePassed;
		}

		if (g_KeyStates[VK_LEFT] && m_PlayerPosition.x > -1 + m_PlayerScale.x)
		{
			m_PlayerPosition.x -= m_Speed * TimePassed;
		}

		else if (g_KeyStates[VK_RIGHT] && m_PlayerPosition.x < 1 - m_PlayerScale.x)
		{
			m_PlayerPosition.x += m_Speed * TimePassed;
		}
	}

    // check if we're colliding with any enemies.
    bool touching = false;
    for( int i=0; i< g_pGame->GetEnemyCount(); i++ )
    {
        GameObject* pEnemy = g_pGame->GetEnemy( i );

		float Distance = sqrtf((pEnemy->ObjectPosition().x - m_PlayerPosition.x) * (pEnemy->ObjectPosition().x - m_PlayerPosition.x) +
							   (pEnemy->ObjectPosition().y - m_PlayerPosition.y) * (pEnemy->ObjectPosition().y - m_PlayerPosition.y));

		if (Distance < (m_PlayerScale.x + pEnemy->ObjectScale().x))
		{
			m_Hitmarked = true;
		}
        
    }
}

void Player::Draw(Vector2 campos)
{
    GameObject::Draw( campos );

    GLuint shaderprogram = g_pGame->GetShaderProgram();

	GLint ChangePosition = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ChangePosition");
	if (ChangePosition != -1)
	{
		glUniform2f(ChangePosition, m_PlayerPosition.x, m_PlayerPosition.y);
	}

	GLint ObjectScale = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ObjectScale");
	if (ObjectScale != -1)
	{
		glUniform2f(ObjectScale, m_PlayerScale.x, m_PlayerScale.y);
	}

	GLint Color = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_Color");
	if (Color != -1)
	{
		glUniform3f(Color, m_PlayerColor.x, m_PlayerColor.y, m_PlayerColor.z);
	}


    DrawCircle( shaderprogram );
}


void Player::SetPosition(Vector2 Pos)
{
	m_PlayerPosition = Pos;
	m_PlayerSpawnPoint = Pos;
}

void Player::ResetObject()
{
	m_PlayerPosition = m_PlayerSpawnPoint;
	m_Hitmarked = false;
}

Vector2 Player::ObjectPosition()
{
    return m_PlayerPosition;
}

Vector2 Player::ObjectScale()
{
	return m_PlayerScale;
}

bool Player::PlayerHitmarked()
{
	return m_Hitmarked;
}

void Player::SetMovementEnabled(bool OnOff)
{
	m_PlayerCanMove = OnOff;
}

