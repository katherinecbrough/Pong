#pragma once
#include "Engine/Public/EngineInterface.h"
#include "GameObject.h"
//#include <cmath>
#include "paddle.h"
#include "Game/Private/ball.h"
#include <string>

class ball;

class exEngineInterface;

class score: public GameObject
{
public:
		exEngineInterface* mEngine;
		score(exEngineInterface* pEngine, float x, float y );
		void Update(float fDeltat, ball* mball);
		void add_score(bool isp1);
		void Draw();
		ball* pball;
	exVector2 mPosition;
	int player1;
	int player2;

		
	
	~score(); 

protected:
	exVector2 mTextPosition;
	int mFontID;

};


