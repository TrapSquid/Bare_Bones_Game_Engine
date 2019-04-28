#ifndef __Enemy_H__
#define __Enemy_H__


class Enemy : public GameObject
{
protected:

	Vector2 m_EnemyPosition;
	Vector2 m_EnemyScale;
	Vector3 m_EnemyColor;

public:
    Enemy();
    virtual ~Enemy();

    virtual void Update(double TimePassed);
    virtual void Draw(Vector2 campos);

	//returns the Enemys position in the world.
	virtual Vector2 ObjectPosition();

	//returns the Enemys scale.
	virtual Vector2 ObjectScale();

    //allows for the Enemy to get called to resetted
    virtual void ResetObject();
};

#endif //__Game_H__
