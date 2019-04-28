#include "CommonHeader.h"


Camera::Camera()
{
    CameraPos = Vector2(0, 0);
    CameraWidth = 600;
    CameraHeight = 600;

}

Camera::~Camera()
{

}


//Sets up the camera height and with.
void Camera::SetCameraHeightWidth(int Width, int Height)
{
    CameraWidth = Width;
    CameraHeight = Height;
}


//Sets the camera's position in the world
void Camera::SetCameraPosition(Vector2 xy)
{
    CameraPos = xy;
}


//Returns where the cameras position is at
Vector2 Camera::GetCameraPosition()
{
    return CameraPos;
}


//Draws the camera
void Camera::Draw()
{
    glViewport(CameraPos.x, CameraPos.y, CameraWidth, CameraHeight);
}