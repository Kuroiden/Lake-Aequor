#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glut.h>
class GameObject 
{
private:
	//position of the game object
	float xPos, yPos, zPos;
	//scale of the game object
	float xSize, ySize, zSize;
	//color
	float red, green, blue;
public:
	//constructor
	GameObject();
	//setters
	void SetPosition(float x, float y, float z);
	void SetScale(float x, float y, float z);
	void SetColor(float r, float g, float b);
	//render primitives
	void DrawCube();
	void DrawSphere(float radius, float slices, float stacks);
};
#endif
