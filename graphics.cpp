#include "graphics.h"

void ChangeSize(int w, int h) {
	//Prevent height from being 0 since we're going to divide this later
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;
	//Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	//Reset Matrix
	glLoadIdentity();
	//Set the viewport to the entire window
	glViewport(0, 0, w, h);
	//Set the correct perspective
	gluPerspective(45, ratio, 1, 1000);
	//Set the camera's position
	gluLookAt(
		0.0f, 0.0f, 5.0f, //camera position or the position of the eye point
		0.0f, 0.0f, 0.0f, //position of reference point
		0.0f, 1.0f, 0.0f //direction of up vector
	);
	//Get back to the modelview
	glMatrixMode(GL_MODELVIEW);
}

void RenderScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Update();

	glutSwapBuffers();
}