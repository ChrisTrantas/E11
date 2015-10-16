#pragma once
#include "RE\ReEngAppClass.h"

class BoundingSphere
{
public:
	vector3 v3Position;
	float fRadius;

	BoundingSphere();
	BoundingSphere(std::vector<vector3>listofVertex);
	~BoundingSphere();

	bool IsColliding(BoundingSphere* pOther);

	void UpdatePosition(vector3 v3Input);
};

