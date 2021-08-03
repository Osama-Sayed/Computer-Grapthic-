#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#define DEG2RAD 3.14159265 / 180;


void InitGraphics(int argc, char *argv[]);

/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations();

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay();
//position and rotation
float fXPos, fYPos, fRot, fXp, fYp, fR;
//flags
bool fg = false;
//color
float R1 = 0, G1 = 0, B1 = 1, R2 = 0, G2 = 1, B2 = 0;

int main(int argc, char* argv[])
{
	fXPos = fYPos = fRot = 0;
	InitGraphics(argc, argv);
	return 0;
}

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL Lab");
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	// here is the setting of the idle function
	glutIdleFunc(OnDisplay);

	SetTransformations();

	glutMainLoop();
}

/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations() {
	//set up the logical coordinate system of the window: [-100, 100] x [-100, 100]
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay()
{

	// clear the transformation matrix
	glLoadIdentity();
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1,0,0);
	glVertex2f(50, 50);
	glVertex2f(-50, 50);
	glVertex2f(-50, -50);
	glVertex2f(50, -50);
	glEnd();

	glPushMatrix();
	glTranslatef(fXPos, fYPos, 0);
	glBegin(GL_POLYGON);
	glColor3f(R1, G1, B1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-40 + 10 * cos(rad),  10 * sin(rad));
	}
	glEnd();
	glPopMatrix();

		glPushMatrix();
		glTranslatef(fXp, fYp, 0);
		glBegin(GL_POLYGON);
		glColor3f(R2, G2, B2);
		for (int i = 0; i<360; i++)
		{
			float rad = i*DEG2RAD;
			glVertex2f(40 + 10 * cos(rad), 10 * sin(rad));
		}
		glEnd();
		glPopMatrix();
		cout << fXPos << endl;
		if(fg ==false)
		{
			fXPos += .05;
			fXp -= .05;
			if (fXPos >= 30)
			{
				R1 = 0; R2 = 0; G1 = 1; G2 = 0; B1 = 0; B2 = 1;
				fg = true;
			}
		}
		if(fg == true)
		{
			fXPos -= .05;
			fXp += .05;
			if (fXPos <= .05)
			{
				fg = false;
				R1 = 0; R2 = 0; G1 = 0; G2 = 1; B1 = 1; B2 = 0;
			}
		}
	glutSwapBuffers();

}


