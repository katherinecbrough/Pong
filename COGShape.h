#pragma once
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "Component.h"

// COGShape - our baseclass for shapes
class COGShape : public Component
{
public:

	static std::vector<COGShape*> mShapeComponents;

public:

	COGShape(GameObject* pGO)
		: Component(pGO)
	{
	}

	virtual void Initialize() override
	{
		AddToComponentVector(mShapeComponents);
	}

	virtual void Destroy() override
	{
		RemoveFromComponentVector(mShapeComponents);
	}

	virtual void Render() = 0;

private:

	// TODO - add a color variable here!

};
