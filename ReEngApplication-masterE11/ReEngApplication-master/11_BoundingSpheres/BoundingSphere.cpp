#include "BoundingSphere.h"



BoundingSphere::BoundingSphere(std::vector<vector3>listofVertex)
{
	vector3 vMax;
	vector3 vMin = vMax = listofVertex[0];

	// for find our min and max value for xyz
	for (uint i = 1; i < listofVertex.size(); i++)
	{
		// X MIN AND MAX
		if (vMax.x < listofVertex[i].x)
			vMax.x = listofVertex[i].x;

		else if (vMin.x > listofVertex[i].x)
			vMin.x = listofVertex[i].x;

		// Y MIN AND MAX
		if (vMax.y < listofVertex[i].y)
			vMax.y = listofVertex[i].y;

		else if (vMin.y > listofVertex[i].y)
			vMin.y = listofVertex[i].y;

		// Z MIN AND MAX
		if (vMax.z < listofVertex[i].z)
			vMax.z = listofVertex[i].z;

		else if (vMin.z > listofVertex[i].z)
			vMin.z = listofVertex[i].z;
	}

	v3Position = (vMax + vMin) / 2.0f;

	fRadius = glm::distance(v3Position, listofVertex[0]);

	for (uint i = 1; i < listofVertex.size(); i++)
	{
		float fDistance = glm::distance(v3Position, listofVertex[i]);
		if (fRadius < fDistance)
			fRadius = fDistance;
	}
}

BoundingSphere::BoundingSphere()
{
}

BoundingSphere::~BoundingSphere()
{
}

bool BoundingSphere::IsColliding(BoundingSphere* pOther)
{
	return (fRadius + pOther->fRadius) > glm::distance(v3Position, pOther->v3Position);
}

void BoundingSphere::UpdatePosition(vector3 v3Input)
{
	v3Position = v3Input;
}
