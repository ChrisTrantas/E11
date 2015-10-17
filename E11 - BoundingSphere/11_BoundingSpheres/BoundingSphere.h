#pragma once
#include "RE\ReEngAppClass.h"

class BoundingSphere
{
public:
	vector3 v3Position;	// Center of the bounding sphere
	float fRadius;		// Radius of the bounding sphere

	BoundingSphere();	// Default constructor
	BoundingSphere(std::vector<vector3>listofVertex);	// Constructs bounding sphere out of list of vector3s
	~BoundingSphere();

	bool IsColliding(BoundingSphere* pOther);	// Checks for collisions with other bounding sphere

	void UpdatePosition(vector3 v3Input);	// Changes the position of the bounding sphere
};

