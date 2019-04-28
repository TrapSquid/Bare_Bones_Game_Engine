#ifndef __GameObject_H__
#define __GameObject_H__

class GameObject
{
protected:

public:
    GameObject();
    virtual ~GameObject();

    virtual void Update(double TimePassed);
    virtual void Draw(Vector2 campos);



	//Mainly these are all objects that if something needs this function that you will allow you to polymorph the functions -- If unused wont do much but the default functions
	//this returns the position of the object
	virtual Vector2 ObjectPosition();

	//This returns the object scale for object
	virtual Vector2 ObjectScale();

	//This sets the objects position
	virtual void SetPosition(Vector2 Pos);

	//this sets the objects scaling
	virtual void SetScale(Vector2 Scale);

	//allows for the objects to get called to resetted
	virtual void ResetObject();
};

#endif //__Game_H__
