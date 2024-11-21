/*////////////////////////////////////////////
	The objects here are just placeholders
	to test the functionality of the mouse
	and keyboard
*/////////////////////////////////////////////

#include "myengine.h"

GameObject player, enemy;

float startingPosition = -1.0f; // Circle default position

// Default box color
float r = 1;
float g = 1;
float b = 1;

void Initialize() {
	//Do whatever you want here for the initialization
	player.SetPosition(startingPosition, 0.0f, 0.0f);
	player.SetScale(0.25f, 0.25f, 0.25f);
	player.SetColor(1, 0, 1);
	enemy.SetPosition(0.5f, -1.0f, 0.0f);
	enemy.SetScale(1.0f, 1.25f, 0.25f);
}

// Circle movement for left mouse buton (LMB) click test
void moveForward(void) {
	startingPosition += 0.001f;
	glutPostRedisplay();
}

void moveBackward(void) {
	if (startingPosition > -1.0f) startingPosition -= 0.01f;
	glutPostRedisplay();
}

void OnLMBClick(int button, int state, int mouseX, int mouseY) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glutIdleFunc(moveForward);
		}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		glutIdleFunc(moveBackward);
		}
	}

// Box color for menu toggle test
void MenuToggle(unsigned char key, int mouseX, int mouseY) {
	switch (key) {
	case 27: // ESC key (for closing window)
		r = 1;		g = 1;		b = 1;
		break;

	case 'a':
		r = 1;		g = 0;		b = 0;
		break;

	case 's':
		r = 0;		g = 1;		b = 0;
		break;

	case 'd':
		r = 0;		g = 0;		b = 1;
		
		break;
	}

	glutPostRedisplay();
}

// Updates objects real-time
void Update() {
	glutMouseFunc(OnLMBClick);
	glutKeyboardFunc(MenuToggle);

	player.SetPosition(startingPosition, 0.0f, 0.0f);
	player.DrawSphere(1, 12, 12);
	enemy.DrawCube();
	enemy.SetColor(r, g, b);
}

int main(int argc, char** argv) {
	PrepareEngine(&argc, argv);
}