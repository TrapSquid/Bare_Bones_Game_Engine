#ifndef __Game_H__
#define __Game_H__

#include "Camera.h"

class Game;

extern Game* g_pGame;

class ShaderProgram;

class Game
{
public:
    static const int MAX_ENEMIES = 100;

protected:
    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;

    ShaderProgram* m_pShader;

    Player* m_pPlayer;

    Enemy m_Enemy[MAX_ENEMIES];
	int m_EnemyCount;

	Target* m_WinArea;


    LevelTile* m_Level;
	LevelTile* m_MiniMap;

	//Handles the loading screen from going to the next stage.
	bool m_LoadingScreen;
	//holds the time to calculate through the time.
	float m_LoadingScreenTiming;

	//How long will the screen display for?
	float m_LoadingScreenWaitTime;



public:
    Game();
    virtual ~Game();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    virtual void Update(double TimePassed);
    virtual void Draw();

    void Reset();

    GLuint GetShaderProgram() { return m_pShader->m_Program; }
    
    GameObject* GetEnemy(int i) { return &m_Enemy[i]; }
    GameObject* GetPlayer() { return m_pPlayer; }
    int GetEnemyCount() { return m_EnemyCount; }
};

#endif //__Game_H__
