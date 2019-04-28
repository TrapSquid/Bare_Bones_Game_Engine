#include "CommonHeader.h"
#include <time.h>

Game* g_pGame = 0;

extern bool g_KeyStates[256];

float Test = 0;

Game::Game()
{
    g_pGame = this;

    m_WindowWidth = -1;
    m_WindowHeight = -1;

    m_pShader = 0;

    m_pPlayer = 0;

	m_EnemyCount = 1;

    m_Level = 0;

	m_MiniMap = 0;

	m_WinArea = 0;

	m_LoadingScreen = false;
	m_LoadingScreenTiming = 0;

	m_LoadingScreenWaitTime = 1;
}

Game::~Game()
{
    delete m_pShader;

    glDeleteBuffers( 1, &g_VBOSquare );
    glDeleteBuffers( 1, &g_VBOTriangle );
    glDeleteBuffers( 1, &g_VBOCircle );

    delete m_pPlayer;

    delete m_Level;

	delete m_MiniMap;

	delete m_WinArea;
}

void Game::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    m_WindowWidth = width;
    m_WindowHeight = height;
}

void Game::LoadContent()
{
    // turn on depth buffer testing.
    //glEnable( GL_DEPTH_TEST );
    //glDepthFunc( GL_LESS );
    // turn on alpha blending.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // create our shaders.
    m_pShader = new ShaderProgram( "Data/Shaders/white.vert", "Data/Shaders/white.frag" );

    m_pPlayer = new Player();
	m_pPlayer->SetPosition(Vector2(-0.75f, 0.75f));

	//sets up the level values
    m_Level = new LevelTile();
    m_Level->CameraLoadcontent( Vector2((float)m_WindowHeight, (float)m_WindowWidth), Vector2(0, 0));
	m_Level->SetCameraPosition(m_pPlayer->ObjectPosition());
    m_Level->SetCameraScale(Vector2(1, 1));
    m_Level->SetTileColor(Vector3(0.69f, 0.51f, 0.235f));
	m_Level->SetPosition(Vector2(0, 0));


	//sets up the minimap values
	m_MiniMap = new LevelTile();
    m_MiniMap->CameraLoadcontent(Vector2((float)m_WindowHeight, (float)m_WindowWidth), Vector2((float)m_WindowHeight * 0.375f, -(float)m_WindowWidth * 0.375f));
    m_MiniMap->SetCameraPosition(Vector2(0, 0));
	m_MiniMap->SetCameraScale(Vector2(5, 5));
	m_MiniMap->SetTileColor(Vector3(0, 0, 0));
	m_MiniMap->SetPosition(Vector2(0, 0));


	m_WinArea = new Target();

    CheckForGLErrors();

    Reset();

    GenerateSquare();
	GenerateCircle();
    GenerateTriangle();

    CheckForGLErrors();
}

void Game::Update(double TimePassed)
{
	m_pPlayer->Update(TimePassed);

	//Always offsetting so the player is in the middle of the screen
	m_Level->SetCameraPosition(m_pPlayer->ObjectPosition() * -1);

	//If palyer gets hit call reset with everything
	if (m_pPlayer->PlayerHitmarked())
	{
		Reset();
	}


	//Gets the distance from the win.
	float DistanceFromWin = sqrtf(powf(m_WinArea->ObjectPosition().x - m_pPlayer->ObjectPosition().x, 2) +
								  powf(m_WinArea->ObjectPosition().y - m_pPlayer->ObjectPosition().y, 2));

	//CHecks wether or not the player i touching the win area.
	if (DistanceFromWin <= m_WinArea->ObjectScale().x + m_pPlayer->ObjectScale().x)
    {
		m_LoadingScreen = true;
		m_LoadingScreenTiming += TimePassed;
		m_pPlayer->SetMovementEnabled(!m_LoadingScreen);

		if (m_LoadingScreenTiming > m_LoadingScreenWaitTime)
		{
			m_EnemyCount++;
			Reset();
		}
    }
}

void Game::Draw()
{
    // clear the screen to dark blue.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	if (!m_LoadingScreen)
	{

		//Draws the Level
		m_Level->Draw(Vector2(0.5, 0));
		for (int i = 0; i < m_EnemyCount; i++)
		{
			m_Enemy[i].Draw(Vector2(0.5, 0));
		}
		m_pPlayer->Draw(Vector2(0, 0));

		m_WinArea->Draw(Vector2(0, 0));

		//Draws the minimap
		m_MiniMap->Draw(Vector2(0, 0));

		for (int i = 0; i < m_EnemyCount; i++)
		{
			m_Enemy[i].Draw(Vector2(0.5, 0));
		}
		m_pPlayer->Draw(Vector2(0, 0));

		m_WinArea->Draw(Vector2(0, 0));
	}

    CheckForGLErrors();
}


//This function is called for when the level will reset
void Game::Reset()
{
	m_pPlayer->ResetObject();
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        m_Enemy[i].ResetObject();
    }

	m_LoadingScreenTiming = 0;
	m_LoadingScreen = false;
	//Sets the opposite of weither or not the loading screen is showing or not.
	m_pPlayer->SetMovementEnabled(!m_LoadingScreen);
}
