#ifndef ENGINE_H
#define ENGINE_H

void createWindow(int* argc, char** argv);

using namespace std;


////all time related variables should be declared publicly
////lets do fps
//int frames = 0;
//
////current time
//int c_time = 0.0f;
//
////previous
//int timebase = 0;
//
////currentFPS
//int fps = 0;
//
//float deltaTime = 0.0f;

//first we need to indicate all the components
class Vector3 {
public:

	float x, y, z;

	//Constructor
	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}


	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}



	void SetValue(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}


	//void Print() {
	//	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	//}



	Vector3 Add(const Vector3& other) {
		Vector3 sum;
		sum.x = this->x + other.x;
		sum.y = this->y + other.y;
		sum.z = this->z + other.z;
		return sum;
	}


	Vector3 operator+(const Vector3& other) {
		Vector3 sum;
		sum.x = this->x + other.x;
		sum.y = this->y + other.y;
		sum.z = this->z + other.z;
		return sum;
	}


	Vector3 operator+=(const Vector3& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}
};

//add the collider class
class Collider {
	Vector3 position;
	Vector3 scale;
public:
	/*void DrawCollider(Vector3 position, Vector3 scale)
	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.5f);
		glTranslatef(position.x, position.y, position.z);
		glScalef(scale.x, scale.y, scale.z);
		glBegin(GL_LINE_STRIP);
		glVertex3f(-0.5f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);
		glEnd();
		glPopMatrix();
	}*/
	void SetDimension(Vector3 position, Vector3 scale) {
		this->position = position;
		this->scale = scale;
	}
	bool CheckCollision(Collider other) {
		//First, set up the actual bounding box
		//Assume that the pivot is at the center of the gameobject
		float xSize = scale.x / 2;
		float ySize = scale.y / 2;
		float zSize = scale.z / 2;

		//Setup the bounding box of the other collider
		float xSizeOther = other.scale.x / 2;
		float ySizeOther = other.scale.y / 2;
		float zSizeOther = other.scale.z / 2;

		//Collision checking: Perform an overlap test for each axis

		//a.minX <= b.maxX && a.maxX >= b.minX
		//a.minX <= b.maxX &&
		bool xCollision = position.x - xSize <= other.position.x + xSizeOther &&
			position.x + xSize >= other.position.x - xSizeOther;
		// a.maxX >= b.maxX

		bool yCollision = position.y - ySize <= other.position.y + ySizeOther &&
			position.y + ySize >= other.position.y - ySizeOther;

		bool zCollision = position.z - zSize <= other.position.z + zSizeOther &&
			position.z + zSize >= other.position.z - zSizeOther;

		//cout << xCollision << " | " << yCollision << " | " << zCollision << endl;

		if (xCollision && yCollision && zCollision)
			return true;
		else
			return false;
	}
};

//Platform Class with Collider
class Platform : public Collider
{
public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	float angle;

	Platform()
	{
		position = Vector3(0, 0, 0);
		rotation = Vector3(0, 0, 0);
		scale = Vector3(1, 1, 1);
		angle = 0;
		Collider::SetDimension(position, scale);
	}


	void SetDimension(Vector3 Position, Vector3 Scale, Vector3 Rotation, float Angle)
	{
		angle = Angle;
		position = Position;
		rotation = Rotation;
		scale = Scale;
		Collider::SetDimension(position, scale);
	}

	//void DrawPlatform()
	//{
	//	glPushMatrix();
	//	glColor3f(0.0f, 0.5f, 0.0f);
	//	glTranslatef(position.x, position.y, position.z);
	//	glRotatef(angle, rotation.x, rotation.y, rotation.z);
	//	glScalef(scale.x, scale.y, scale.z);
	//	glBegin(GL_QUADS);
	//	glVertex3f(-0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	glEnd();
	//	glPopMatrix();
	//	Collider::SetDimension(position, scale);

	//	//uncomment me to see the collider
	//	//DrawCollider(position, scale);
	//}

};

#endif
