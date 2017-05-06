#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Game.h"

#define MILI_SECONS_FRAME 17.3

void ReSizeGLScene(GLsizei, GLsizei);
void DrawGLScene(GLvoid);								
void OnTimer(int);
int InitGL(void);										
Game *game;
int window;
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);				
	glutInitWindowSize(640,480);					
	
	window=glutCreateWindow("Projekt_0.3");				
	InitGL();										
	
	glutDisplayFunc(DrawGLScene);					
	glutIdleFunc(DrawGLScene);						
	glutReshapeFunc(ReSizeGLScene);
	glutKeyboardFunc(Keyboard::OnKeyPress);
	glutKeyboardUpFunc(Keyboard::OnKeyUp);
	glutMotionFunc(Mouse::CallBackDrag);
	glutMouseFunc(Mouse::CallBack);
	glutTimerFunc(MILI_SECONS_FRAME, OnTimer, 0);

	glutMainLoop();
	return 0;									
}

void ReSizeGLScene(GLsizei width, GLsizei height)	
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int InitGL(void)										
{
	float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);
	glEnable(GL_LIGHTING); // Wlaczenie oswietlenia

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations				
	

	glEnable(GL_TEXTURE_2D);
    game = new Game();
	return true;										// Initialization Went OK
}

void DrawGLScene(GLvoid)								
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();

	Mouse::Update();
	game->Update();


	if(Keyboard::GetKey() == 'k'){
		Camera::Delete();
		glutDestroyWindow(window);
	}

	Keyboard::Update();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void OnTimer(int id) {
	glutTimerFunc(MILI_SECONS_FRAME, OnTimer, 0);
}