#ifndef __Camera_H__
#define __Camera_H__

#include "CommonHeader.h"
class Camera;

class Camera
{
public:
    Camera();
    virtual ~Camera();

    //Sets Camera's height and width
    void SetCameraHeightWidth(int Width, int Height);

    //Sets and gets the cameras position.
    void SetCameraPosition(Vector2 xy);
    Vector2 GetCameraPosition();

    void Draw();

protected:



    //Stores the XY position for the camera's posiiton on the screen
    Vector2 CameraPos;
    //Holds the width and the height of the camera
    unsigned int CameraWidth;
    unsigned int CameraHeight;

};

#endif