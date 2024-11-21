#include "myengine.h"

void PrepareEngine(int *argc, char** argv)
{
	//initialize GLUT and create a window
	glutInit(argc, argv);
	//window creation
	int screenH = glutGet(GLUT_SCREEN_HEIGHT);
	int screenW = (screenH / 3) * 4;

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-screenW)/2, (glutGet(GLUT_SCREEN_HEIGHT)-screenH)/2);
	glutInitWindowSize(screenW, screenH);
	glutCreateWindow("OpenGL Window");

	//Call the Initialize function to run once
	Initialize();

	//register event callbacks
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(RenderScene);

	//enter GLUT event processing cycle

	//enables depth
	glEnable(GL_DEPTH_TEST);
	//enables transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//Set the blend mode to blend our current RGBA with what is already in the buffer

	glutMainLoop();
}