#pragma once

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "Component.h"
#include "COGShape.h"
#include "Component.h"

// our interface that allows COGPhysics to talk to anyone
class COGPhysics;

class IPhysicsCollisionEvent
{
public:

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther) = 0;

};

// COGPhysics - lets move around
class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

public:

	COGPhysics(GameObject* pGO, bool bGenerateCollisionEvents)
		: Component(pGO)
		, mGenerateCollisionEvents(bGenerateCollisionEvents)
	{
	}

	virtual ComponentType GetType() const { return ComponentType::Physics; }

	virtual void Initialize() override
	{
		mTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
		mBoxShape = mGO->FindComponent<COGBoxShape>(ComponentType::BoxShape);
		mCircleShape = mGO->FindComponent<COGCircleShape>(ComponentType::CircleShape);

		AddToComponentVector(mPhysicsComponents);
	}

	virtual void Destroy() override
	{
		RemoveFromComponentVector(mPhysicsComponents);
	}

	virtual void Update(float fDeltaT)
	{
		// integrate velocity
		Vector2& myPosition = mTransform->GetPosition();

		myPosition.x += mVelocity.x * fDeltaT;
		myPosition.y += mVelocity.y * fDeltaT;

		// check collisions
		if (mGenerateCollisionEvents)
		{
			for (COGPhysics* pPhysicsOther : COGPhysics::mPhysicsComponents)
			{
				// do not collide with self
				if (pPhysicsOther == this)
				{
					continue;
				}

				// TODO - maybe have IsColliding produce a vector/struct that contains the normal and then pass that into OnCollision?
				const bool bResult = IsColliding(pPhysicsOther);

				if (bResult)
				{
					for (IPhysicsCollisionEvent* pCollisionEventListener : mCollisionEventListeners)
					{
						pCollisionEventListener->OnCollision(this, pPhysicsOther);
					}
				}
			}
		}
	}

	bool IsColliding(COGPhysics* pOther)
	{
		if (mCircleShape != nullptr && pOther->mBoxShape != nullptr)
		{
			// check a circle colliding with a box
		}

		// we don't cover the other cases
		// maybe assert here?

		return false;
	}

	void AddCollisionEventListener(IPhysicsCollisionEvent* pEvent)
	{
		mCollisionEventListeners.push_back(pEvent);
	}

private:

	COGTransform* mTransform;
	COGBoxShape* mBoxShape;
	COGCircleShape* mCircleShape;

	Vector2 mVelocity;

	bool mGenerateCollisionEvents;
	std::vector<IPhysicsCollisionEvent*> mCollisionEventListeners;

};