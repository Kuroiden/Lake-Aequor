#include "gameobject.h"

//Default values
GameObject::GameObject() {
	xPos = 0;
	yPos = 0;
	zPos = 0;
	xSize = 1;
	ySize = 1;
	zSize = 1;
	red = 1;
	green = 1;
	blue = 1;
}

void GameObject::SetPosition(float x, float y, float z) {
	xPos = x;
	yPos = y;
	zPos = z;
}

void GameObject::SetScale(float x, float y, float z) {
	xSize = x;
	ySize = y;
	zSize = z;
}

void GameObject::SetColor(float r, float g, float b) {
	red = r;
	green = g;
	blue = b;
}

void GameObject::DrawCube() {
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glScalef(xSize, ySize, zSize);
	glColor3f(red, green, blue);
	glutSolidCube(1);
	glPopMatrix();
}

void GameObject::DrawSphere(float radius, float slices, float stacks) {

	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glScalef(xSize, ySize, zSize);
	glColor3f(red, green, blue);
	glutSolidSphere(radius, slices, stacks);
	glPopMatrix();

}