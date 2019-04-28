#include "CommonHeader.h"
#include "LevelTile.h"


LevelTile::LevelTile()
{
    m_TilePosition = Vector2(0,0);
    m_TileColor = Vector3(1, 1, 1);
    m_TileScale = Vector2(1, 1);
    
    m_CameraPosition = Vector2(0,0);
    m_CameraScale = Vector2(1,1);

    m_Camera = new Camera();
}


LevelTile::~LevelTile()
{
    m_Camera = nullptr;
    delete m_Camera;
}

void LevelTile::Update(double TimePassed)
{

}

void LevelTile::Draw(Vector2 campos)
{

    GameObject::Draw(campos);
    GLuint shaderprogram = g_pGame->GetShaderProgram();
    m_Camera->Draw();

    GLint ChangePosition = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ChangePosition");
    if (ChangePosition != -1)
    {
        glUniform2f(ChangePosition, m_TilePosition.x, m_TilePosition.y);
    }

    GLint ObjectScale = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_ObjectScale");
    if (ObjectScale != -1)
    {
        glUniform2f(ObjectScale, m_TileScale.x, m_TileScale.y);
    }

    GLint Color = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_Color");
    if (Color != -1)
    {
        glUniform3f(Color, m_TileColor.x, m_TileColor.y, m_TileColor.z);
    }

    GLint CameraPosition = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_CameraPosition");
    if (CameraPosition != -1)
    {
        glUniform2f(CameraPosition, m_CameraPosition.x, m_CameraPosition.y);
    }

    GLint CameraScale = glGetUniformLocation(g_pGame->GetShaderProgram(), "u_CameraScale");
    if (CameraScale != -1)
    {
        glUniform2f(CameraScale, m_CameraScale.x, m_CameraScale.y);
    }

    DrawSquare(shaderprogram);
}

void LevelTile::SetCameraPosition(Vector2 pos)
{
    m_CameraPosition = pos;
}

void LevelTile::SetCameraScale(Vector2 scale)
{
    m_CameraScale = scale;
}

void LevelTile::SetTileColor(Vector3 color)
{
    m_TileColor = color;
}

void LevelTile::SetPosition(Vector2 Pos)
{
    m_TilePosition = Pos;
}

void LevelTile::SetTileScale(Vector2 scale)
{
    m_TileScale = scale;
}


void LevelTile::CameraLoadcontent(Vector2 CameraWidthnHeight, Vector2 CameraPosition)
{
    m_Camera->SetCameraHeightWidth(CameraWidthnHeight.x, CameraWidthnHeight.y);
    m_Camera->SetCameraPosition(CameraPosition);
}