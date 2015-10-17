#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("Trantas, Christopher & Cooper, Michael - Bounding Spheres"); // Window Name

	// Set the clear color based on Microsoft's CornflowerBlue (default in XNA)
	//if this line is in Init Application it will depend on the .cfg file, if it
	//is on the InitVariables it will always force it regardless of the .cfg
	m_v4ClearColor = vector4(0.4f, 0.6f, 0.9f, 0.0f);
}
void AppClass::InitVariables(void)
{
	m_v3Torus = vector3(3.5f, 0.0f, 0.0f);
	m_v3Cone = vector3(0.0f, 0.0f, 0.0f);

	m_pTorus = new PrimitiveClass();
	m_pTorus->GenerateTorus(1.0f, 0.7f, 10, 10, REGREEN);

	m_pCone = new PrimitiveClass();
	m_pCone->GenerateCone(1.0f, 1.0f, 10, REGREEN);

	m_BoundCone = BoundingSphere(m_pCone->GetVertices());
	m_BoundTorus = BoundingSphere(m_pTorus->GetVertices());
}

void AppClass::Update(void)
{
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update(false);

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();
	
	// Updates the position of each bounding sphere to the position vector of each shape.
	m_BoundCone.UpdatePosition(m_v3Cone);
	m_BoundTorus.UpdatePosition(m_v3Torus);


	//Adds all loaded instance to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(); //renders the XY grid with a 100% scale

	m_pMeshMngr->Render(); //renders the render list

	m_pTorus->Render(glm::translate(matrix4(1.0f), m_v3Torus), REGREEN);

	m_pCone->Render(glm::translate(matrix4(1.0f), m_v3Cone), REBLUE);

	// Sets render color based on if the two bounding spheres are colliding.
	vector3 v3Color;
	m_BoundCone.IsColliding(&m_BoundTorus) ? v3Color = RERED : v3Color = REWHITE;

	// Renders the the bounding spheres of each shape.
	m_pMeshMngr->AddSphereToQueue(glm::translate(m_BoundCone.v3Position) * glm::scale(vector3(m_BoundCone.fRadius * 2)), v3Color, WIRE);
	m_pMeshMngr->AddSphereToQueue(glm::translate(m_BoundTorus.v3Position) * glm::scale(vector3(m_BoundTorus.fRadius * 2)), v3Color, WIRE);

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); //release the memory of the inherited fields
}
