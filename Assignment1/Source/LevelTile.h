#ifndef __LevelTile_H__
#define __LevelTile_H__

class Camera;

class LevelTile : public GameObject
{
public:
    LevelTile();
    virtual ~LevelTile();

    virtual void Update(double TimePassed);
    virtual void Draw(Vector2 CamPos);

    //Runs through the camera loadcontent which will only be called once.
    void CameraLoadcontent(Vector2 CameraHeightnWidth, Vector2 CameraPosition);

    //Sets up the tiles translations
    void SetTileColor(Vector3 Color);
    void SetTileScale(Vector2 scale);
	virtual void SetPosition(Vector2 Pos);

    //Sets up the Camera Positioning.
    void SetCameraPosition(Vector2 Position);
    void SetCameraScale(Vector2 Scale);

protected:

    //This is the camera that is set onto the player.
    Camera* m_Camera;

    //Holds how the tile will act
    Vector2 m_TilePosition;
    Vector2 m_TileScale;
    Vector3 m_TileColor;

    //Holds how the camera acts
    Vector2 m_CameraPosition;
    Vector2 m_CameraScale;
};

#endif //__LevelTile_H__