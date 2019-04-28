#ifndef __Player_H__
#define __Player_H__

class Player : public GameObject
{
protected:
	//Stores the players positioning and scaling
	Vector2 m_PlayerPosition;
	Vector2 m_PlayerScale;

	//This holds on to where the players spawn point will be (default area when start game)
	Vector2 m_PlayerSpawnPoint;

	//allows to set the players speed for future things
	float m_Speed;

	//Flags the player that he/she has been hit.
	bool m_Hitmarked;

	//This stores the player color.
	Vector3 m_PlayerColor;

	//This bool holds onto wether or not the players movement is turned on or off.
	bool m_PlayerCanMove;

public:
    Player();
    virtual ~Player();

    virtual void Update(double TimePassed);
    virtual void Draw(Vector2 CamPos);

    //returns the players position in the world.
	virtual Vector2 ObjectPosition();

	//returns the players scale.
	virtual Vector2 ObjectScale();

	//This allows to set the objects position if want to if not it will defaulty be 0,0
	virtual void SetPosition(Vector2 Pos);

	//Resets the player to its original position;
	virtual void ResetObject();

	//Returns wether or not the player is colliding with an enemy or not.
	bool PlayerHitmarked();

	//This function sets wether or not the player can move or not.
	void SetMovementEnabled(bool OnOff);
};

#endif //__Game_H__
