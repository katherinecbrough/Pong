#pragma once
#include "score.h"
#include "GameObject.h"
#include <iostream>





score::score(exEngineInterface* pEngine, float x, float y) : GameObject(mEngine)
{
	
	mEngine = pEngine;
	c.mColor[0] = 204;
	c.mColor[1] = 255;
	c.mColor[2] = 204;
	c.mColor[3] = 255;

	mFontID = mEngine->LoadFont( "Cleptograph3D.ttf", 32 );

	pball->mPosition.x;
	pball->mPosition.y;
	player1 = 0;
	player2 = 0;

}

void score::add_score(bool isp1)
{
	if (isp1)
	{
	player1++;
	}
	else
	{
	player2++;
	}
}


void score::Update(float fDeltat, ball* mball)
{

	mEngine->DrawText(mFontID, { 200,50 }, std::to_string(player1).c_str(), c, 0);

	mEngine->DrawText(mFontID, {300,50}, "PONG", c, 0);

	mEngine->DrawText(mFontID, { 500,50 }, std::to_string(player2).c_str(), c, 0);
	




}
