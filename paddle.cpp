#include  "paddle.h"
#include "GameObject.h"

paddle::paddle(exEngineInterface* pEngine,  exVector2 p1, exVector2 p2 )
	: GameObject(mEngine)
{
	pos1 = p1;
	pos2 = p2;
	c.mColor[0] = 204;
	c.mColor[1] = 204;
	c.mColor[2] = 255;
	c.mColor[3] = 255;
	mEngine = pEngine;
	
};

void paddle::UserInput(bool mUp, bool mDown)
{

		if (mUp)
		{
			pos1.y -= 20.0f ;
			pos2.y -= 20.0f ;
		}
		else if (mDown)
		{
			pos1.y += 20.0f ;
			pos2.y += 20.0f ;
		}
	}
	void paddle::update (float fDeltat)
	{
		mEngine->DrawBox(pos1, pos2, c, 1);
		
	}
