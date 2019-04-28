#ifndef __Target_H__
#define __Target_H__

class Target : public GameObject
{
protected:

	Vector2 m_Position;
	Vector2 m_Scale;
	Vector3 m_Color;

public:
    Target();
    virtual ~Target();

    virtual void Update(double TimePassed);
    virtual void Draw(Vector2 CamPos);
	virtual Vector2 ObjectPosition();

	//This returns the object scale for object
	virtual Vector2 ObjectScale();
};

#endif //__Game_H__
