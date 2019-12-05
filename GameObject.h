#pragma once
#include "Engine/Public/EngineTypes.h"

class exEngineInterface;


class GameObject
{
public:
	GameObject(exEngineInterface* pEngine)
	{
		exEngineInterface* mEngine;
		mEngine = pEngine;
		exVector2 mPosition;
		
	};
	~GameObject() {};
protected:
	exVector2 p1;
	exVector2 p2;
	 exVector2 mVelocity;
	 exEngineInterface* pEngine;
	 exColor c;


 };

class Factory
{

};