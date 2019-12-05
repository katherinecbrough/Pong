#pragma once
#include "Engine/Public/EngineInterface.h"
#include "GameObject.h"


class paddle : public GameObject
{
public:
	exEngineInterface* mEngine;
	paddle(exEngineInterface* pEngine, exVector2 p1, exVector2 p2);
	void UserInput(bool mUp, bool mDown);
	void update(float fDeltat);
	void Draw();

	exVector2 pos1;
	exVector2 pos2;




};
