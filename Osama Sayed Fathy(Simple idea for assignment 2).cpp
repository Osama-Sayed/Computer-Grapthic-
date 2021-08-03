#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#define DEG2RAD 3.14159265 / 180;

void car();
void car2();
void fish();
void fish2();
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
float fxc1, fyc1, frc1, fxf1, fyf1, frf1,fxc2,fyc2,frc2,fxf2,fyf2,frf2;
//flags
bool p1=false,sf1=true,sf2=true,p2=false,finl=false;

int main(int argc, char* argv[])
{
	fxc1 = -120;
	fyc1 = -40;

	frc2 = 180;
	fyc2 = -80;
	fxc2 = 120;

	fxf1 = 110;
	fyf1 = 50;
	
	fxf2 = 200;
	fyf2 = 50;

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

	//Road
	glBegin(GL_QUADS);
	glColor3f(0.43921568627451, 0.43921568627451, 0.43921568627451);
	glVertex2f(-100,-7);
	glVertex2f(-100,-100);
	glVertex2f(100,-100);
	glVertex2f(100,-7);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-98, -60.5);
	glVertex2f(-98, -63);
	glVertex2f(-76.5, -63);
	glVertex2f(-76.5, -60.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-63.5, -60.5);
	glVertex2f(-63.5, -63);
	glVertex2f(-42, -63);
	glVertex2f(-42, -60.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-29, -60.5);
	glVertex2f(-29, -63);
	glVertex2f(-7.5, -63);
	glVertex2f(-7.5, -60.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(5.5, -60.5);
	glVertex2f(5.5, -63);
	glVertex2f(27, -63);
	glVertex2f(27, -60.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(40, -60.5);
	glVertex2f(40, -63);
	glVertex2f(61.5, -63);
	glVertex2f(61.5, -60.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(74.5, -60.5);
	glVertex2f(74.5, -63);
	glVertex2f(96, -63);
	glVertex2f(96, -60.5);
	glEnd();
	/////////////////////////////////////////////////
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-100, -7.5);
	glVertex2f(-100, -20.5);
	glVertex2f(-72.5, -20.5);
	glVertex2f(-72.5, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-72.5, -7.5);
	glVertex2f(-72.5, -20.5);
	glVertex2f(-45, -20.5);
	glVertex2f(-45, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-45, -7.5);
	glVertex2f(-45, -20.5);
	glVertex2f(-17.5, -20.5);
	glVertex2f(-17.5, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-17.5, -7.5);
	glVertex2f(-17.5, -20.5);
	glVertex2f(10, -20.5);
	glVertex2f(10, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(10, -7.5);
	glVertex2f(10, -20.5);
	glVertex2f(37.5, -20.5);
	glVertex2f(37.5, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(37.5, -7.5);
	glVertex2f(37.5, -20.5);
	glVertex2f(65, -20.5);
	glVertex2f(65, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(65, -7.5);
	glVertex2f(65, -20.5);
	glVertex2f(92.5, -20.5);
	glVertex2f(92.5, -7.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(92.5, -7.5);
	glVertex2f(92.5, -20.5);
	glVertex2f(120, -20.5);
	glVertex2f(120, -7.5);
	glEnd();


	//sand
	glBegin(GL_QUADS);
	glColor3f(0.862745098039216, 0.768627450980392, 0.517647058823529);
	glVertex2f(-100, -7.5);
	glVertex2f(-100, 46);
	glVertex2f(100, 46);
	glVertex2f(100, -7.5);
	glEnd();

	//see
	glBegin(GL_QUADS);
	glColor3f(0.356862745098039, 0.384313725490196, 0.870588235294118);
	glVertex2f(-100, 46);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, 46);
	glEnd();

	//waves
	glBegin(GL_POLYGON);
	glColor3f(0.356862745098039, 0.384313725490196, 0.870588235294118);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f( 100 * cos(rad), 46 + 12 * sin(rad*10));
	}
	glEnd();
	/////////////////////////////////////////////////////////////////////////////

	if (p1 == false)
	{
		fxc2 -= .08;
		fxc1 += .08;
		fxf1 -= .05;
		fyf1 += .00005;
		frf1 -= .01;
		fxf2 -= .1;
		fyf2 += .005;
		frf2 -= .01;

		if (fxf1 <= 32.7)
			sf1 = false;
		if (fxf2 <= -25)
			sf2 = false;

		if (fxc1 >= 120)
		{
			fxc1 = -120;
			fyc1 = -40;

			frc2 = 180;
			fyc2 = -80;
			fxc2 = 120;
			p2 = true;
		}
	}

	if (p2 == true)
	{
		fyc2 += .01;
		frc2 +=.015 ;
		cout << "frc2: " << frc2 << endl;
		if (frc2 >= 202.1)
		{
			finl = true;
			p2 = false;
			p1 = true;
		}
	}
	
	//// Car 1 /////////////////
	glPushMatrix();
	glTranslatef(fxc1, fyc1, 0);
	glRotatef(frc1, 0, 0, -0.5);
	glScalef(.5, .5, 0);
	car();
	glPopMatrix();
	

	//Car 2 /////////////////////

	glPushMatrix();
	glTranslatef(fxc2, fyc2, 0);
	glRotatef(frc2, 0, 0, -0.5);
	glScalef(.5, .5, 0);
	car2();
	glPopMatrix();


	//////////////// fish1 /////////////////////
	if (sf1)
	{
		glPushMatrix();
		glRotatef(frf1, 0, 0, -0.5);
		glTranslatef(fxf1, fyf1, 0);
		glScalef(.25, .25, 0);
		fish();
		glPopMatrix();
	}

		//////////////// fish 2 /////////////////////
		if (sf2)
		{
			glPushMatrix();
			glRotatef(frf2, 0, 0, -0.5);
			glTranslatef(fxf2, fyf2, 0);
			glScalef(.5, .5, 0);
			fish2();
			glPopMatrix();
		}

		if (finl == true)
		{
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);

			glVertex2f(-37, -27.2);
			glVertex2f(-18.8, -53.5);
			glVertex2f(-13.8, -46.7);

			glVertex2f(-13.8, -46.7);
			glVertex2f(-24, -16.7);
			glVertex2f(-8.3, -40);

			glVertex2f(-8.3, -40);
			glVertex2f(-4.4, -24.8);
			glVertex2f(0, -40.8);

			glVertex2f(0, -40.8);
			glVertex2f(9.9, -34.5);
			glVertex2f(8.2, -46.7);

			glVertex2f(8.2, -46.7);
			glVertex2f(19.6, -50.5);
			glVertex2f(8.2, -56);

			glVertex2f(8.2, -56);
			glVertex2f(18, -70.4);
			glVertex2f(3.4, -61);

			glVertex2f(3.4, -61);
			glVertex2f(4, -83.5);
			glVertex2f(-6.5, -65.7);

			glVertex2f(-6.5, -65.7);
			glVertex2f(-15.8, -87.7);
			glVertex2f(-13.3, -67);

			glVertex2f(-13.3, -67);
			glVertex2f(-25.6, -72.5);
			glVertex2f(-16.7, -62.4);

			glVertex2f(-16.7, -62.4);
			glVertex2f(-34.5, -63.6);
			glVertex2f(-19.3, -53.5);
			glEnd();

			glBegin(GL_POLYGON);
			glColor3f(0, 0, 0);
			glVertex2f(-18.8, -53.5);
			glVertex2f(-13.8, -46.7);
			glVertex2f(-8.3, -40);
			glVertex2f(0, -40.8);
			glVertex2f(8.2, -46.7);
			glVertex2f(8.2, -56);
			glVertex2f(3.4, -61);
			glVertex2f(4, -83.5);
			glVertex2f(-6.5, -65.7);
			glVertex2f(-13.3, -67);
			glVertex2f(-25.6, -72.5);
			glVertex2f(-16.7, -62.4);
			glEnd();
		}
	glutSwapBuffers();

}



void car()
{

	float tha;

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(20 + 11 * sin(tha), 25 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-25 - 6 * sin(tha), 25 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-25, 25);
	glVertex2f(-26, -25);
	glVertex2f(21, -25);
	glVertex2f(20, 25);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.580392156862745, 0.647058823524412, 0.674509803921569);
	for (int i = -5; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-25.5 - 5 * sin(tha), 24 * cos(tha));
	}
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-25 - 3.5 * sin(tha), 24 * cos(tha));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0.0352441176470588, 0.0352441176470588);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-24.5 - 3.5 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.580392156862745, 0.647058823524412, 0.674509803921569);
	for (int i = -5; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(20.5 + 10 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(22 + 6 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0.0352441176470588, 0.0352441176470588);
	for (int i = -5; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(21.5 + 6 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.0352441176470588, 0.0352441176470588);
	glVertex2f(-25, 24);
	glVertex2f(-25, -24);
	glVertex2f(22, -24);
	glVertex2f(22, 24);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 135; i < 295; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4.5 * sin(tha), 22 + 5.5 * cos(tha));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = 135; i < 295; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4 * sin(tha), 22 + 5 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = -15; i < 89; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(21.5 + 5.4 * sin(tha), 18.1 + 5.9 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 245; i < 410; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4.5 * sin(tha), -22 + 5.5 * cos(tha));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = 245; i < 405; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4 * sin(tha), -22 + 5 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = 80; i < 200; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(21.7 + 4.9* sin(tha), -19.1 + 4.9 * cos(tha));
	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(21, 17);
	glVertex2f(10, 15.5);
	glVertex2f(10, 15);
	glVertex2f(21, 16.5);

	glVertex2f(21, -17);
	glVertex2f(10, -15.5);
	glVertex2f(10, -15);
	glVertex2f(21, -16.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(5.4 + 5 * sin(tha), 17 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);
	for (int i = 0; i < 185; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(5 + 5 * sin(tha), 17 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(1.7, 15.2);
	glVertex2f(5, 17.2);
	glVertex2f(5, -17.2);
	glVertex2f(1.7, -15.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);
	glVertex2f(2, 15);
	glVertex2f(5, 17);
	glVertex2f(5, -17);
	glVertex2f(2, -15);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(1.5, 14);
	glVertex2f(-10.5, 13.7);
	glVertex2f(-10.5, 13.2);
	glVertex2f(1.5, 13.5);

	glVertex2f(-10.5, 13.5);
	glVertex2f(-10.1, 13.5);
	glVertex2f(-10.1, -13.5);
	glVertex2f(-10.5, -13.5);

	glVertex2f(1.5, -14);
	glVertex2f(-10.5, -13.7);
	glVertex2f(-10.5, -13.2);
	glVertex2f(1.5, -13.5);

	glVertex2f(-13.5, 23);
	glVertex2f(-10.3, 13.5);
	glVertex2f(-10.5, 13);
	glVertex2f(-13.7, 22.5);

	glVertex2f(-13.5, -21);
	glVertex2f(-11, -15);
	glVertex2f(-11.2, -14.5);
	glVertex2f(-13.7, -20.5);

	glVertex2f(-10.6, 11.4);
	glVertex2f(-17.4, 10.4);
	glVertex2f(-17.4, -10.4);
	glVertex2f(-10.6, -11.4);

	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);

	glVertex2f(-11, 11);
	glVertex2f(-17, 10);
	glVertex2f(-17, -10);
	glVertex2f(-11, -11);

	glColor3f(0, 0, 0);

	glVertex2f(2, 20.3);
	glVertex2f(-12.3, 19.8);
	glVertex2f(-10.1, 14);
	glVertex2f(0.2, 14);

	glVertex2f(1.9, -20.3);
	glVertex2f(-12.5, -20);
	glVertex2f(-9.7, -14.1);
	glVertex2f(.2, -14.3);


	glVertex2f(1.7, 25);
	glVertex2f(5.3, 25);
	glVertex2f(3.7, 28.3);
	glVertex2f(1.7, 27.8);

	glVertex2f(1.7, -25);
	glVertex2f(5.3, -25);
	glVertex2f(3.7, -28.3);
	glVertex2f(1.7, -27.8);

	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);

	glVertex2f(1.7, 20);
	glVertex2f(-12, 19.5);
	glVertex2f(-9.8, 14.4);
	glVertex2f(0, 14.5);


	glVertex2f(1.6, -20);
	glVertex2f(-12, -19.5);
	glVertex2f(-9.5, -14.4);
	glVertex2f(0, -14.5);

	glColor3f(1, 0.0352441176470588, 0.0352441176470588);

	glVertex2f(2, 25);
	glVertex2f(5, 25);
	glVertex2f(3.5, 28);
	glVertex2f(2, 27.5);


	glVertex2f(2, -25);
	glVertex2f(5, -25);
	glVertex2f(3.5, -28);
	glVertex2f(2, -27.5);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(18 + sin(tha), 25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(10 + -1 * sin(tha), 25.3 + -1 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(18 + sin(tha), -25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(10 + -1 * sin(tha), -25.3 + -1 * cos(tha));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-9 + sin(tha), 25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-17 + -1 * sin(tha), 25.3 + -1 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-9 + sin(tha), -25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-17 + -1 * sin(tha), -25.3 + -1 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-25, 22);
	glVertex2f(-19, 13);
	glVertex2f(-19, 12.5);
	glVertex2f(-25, 21.5);


	glVertex2f(-25, -22);
	glVertex2f(-19, -13);
	glVertex2f(-19, -12.5);
	glVertex2f(-25, -21.5);

	glEnd();
}
void car2()
{


	float tha;

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(20 + 11 * sin(tha), 25 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-25 - 6 * sin(tha), 25 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-25, 25);
	glVertex2f(-26, -25);
	glVertex2f(21, -25);
	glVertex2f(20, 25);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.580392156862745, 0.647058823524412, 0.674509803921569);
	for (int i = -5; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-25.5 - 5 * sin(tha), 24 * cos(tha));
	}
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-25 - 3.5 * sin(tha), 24 * cos(tha));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.898039215686275, 0.0509803921568627, 0.807843137254902);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-24.5 - 3.5 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.580392156862745, 0.647058823524412, 0.674509803921569);
	for (int i = -5; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(20.5 + 10 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(22 + 6 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.898039215686275, 0.0509803921568627, 0.807843137254902);
	for (int i = -5; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(21.5 + 6 * sin(tha), 24 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.898039215686275, 0.0509803921568627, 0.807843137254902);
	glVertex2f(-25, 24);
	glVertex2f(-25, -24);
	glVertex2f(22, -24);
	glVertex2f(22, 24);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 135; i < 295; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4.5 * sin(tha), 22 + 5.5 * cos(tha));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = 135; i < 295; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4 * sin(tha), 22 + 5 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = -15; i < 89; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(21.5 + 5.4 * sin(tha), 18.1 + 5.9 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 245; i < 410; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4.5 * sin(tha), -22 + 5.5 * cos(tha));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = 245; i < 405; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(24 + 4 * sin(tha), -22 + 5 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.956862745098039, 0.909803921568627, 0.164705882352441);
	for (int i = 80; i < 200; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(21.7 + 4.9* sin(tha), -19.1 + 4.9 * cos(tha));
	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(21, 17);
	glVertex2f(10, 15.5);
	glVertex2f(10, 15);
	glVertex2f(21, 16.5);

	glVertex2f(21, -17);
	glVertex2f(10, -15.5);
	glVertex2f(10, -15);
	glVertex2f(21, -16.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(5.4 + 5 * sin(tha), 17 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);
	for (int i = 0; i < 185; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(5 + 5 * sin(tha), 17 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(1.7, 15.2);
	glVertex2f(5, 17.2);
	glVertex2f(5, -17.2);
	glVertex2f(1.7, -15.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);
	glVertex2f(2, 15);
	glVertex2f(5, 17);
	glVertex2f(5, -17);
	glVertex2f(2, -15);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(1.5, 14);
	glVertex2f(-10.5, 13.7);
	glVertex2f(-10.5, 13.2);
	glVertex2f(1.5, 13.5);

	glVertex2f(-10.5, 13.5);
	glVertex2f(-10.1, 13.5);
	glVertex2f(-10.1, -13.5);
	glVertex2f(-10.5, -13.5);

	glVertex2f(1.5, -14);
	glVertex2f(-10.5, -13.7);
	glVertex2f(-10.5, -13.2);
	glVertex2f(1.5, -13.5);

	glVertex2f(-13.5, 23);
	glVertex2f(-10.3, 13.5);
	glVertex2f(-10.5, 13);
	glVertex2f(-13.7, 22.5);

	glVertex2f(-13.5, -21);
	glVertex2f(-11, -15);
	glVertex2f(-11.2, -14.5);
	glVertex2f(-13.7, -20.5);

	glVertex2f(-10.6, 11.4);
	glVertex2f(-17.4, 10.4);
	glVertex2f(-17.4, -10.4);
	glVertex2f(-10.6, -11.4);

	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);

	glVertex2f(-11, 11);
	glVertex2f(-17, 10);
	glVertex2f(-17, -10);
	glVertex2f(-11, -11);

	glColor3f(0, 0, 0);

	glVertex2f(2, 20.3);
	glVertex2f(-12.3, 19.8);
	glVertex2f(-10.1, 14);
	glVertex2f(0.2, 14);

	glVertex2f(1.9, -20.3);
	glVertex2f(-12.5, -20);
	glVertex2f(-9.7, -14.1);
	glVertex2f(.2, -14.3);


	glVertex2f(1.7, 25);
	glVertex2f(5.3, 25);
	glVertex2f(3.7, 28.3);
	glVertex2f(1.7, 27.8);

	glVertex2f(1.7, -25);
	glVertex2f(5.3, -25);
	glVertex2f(3.7, -28.3);
	glVertex2f(1.7, -27.8);

	glColor3f(0.188235294117647, 0.705882352941177, 0.956862745098039);

	glVertex2f(1.7, 20);
	glVertex2f(-12, 19.5);
	glVertex2f(-9.8, 14.4);
	glVertex2f(0, 14.5);


	glVertex2f(1.6, -20);
	glVertex2f(-12, -19.5);
	glVertex2f(-9.5, -14.4);
	glVertex2f(0, -14.5);

	glColor3f(0.898039215686275, 0.0509803921568627, 0.807843137254902);

	glVertex2f(2, 25);
	glVertex2f(5, 25);
	glVertex2f(3.5, 28);
	glVertex2f(2, 27.5);


	glVertex2f(2, -25);
	glVertex2f(5, -25);
	glVertex2f(3.5, -28);
	glVertex2f(2, -27.5);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(18 + sin(tha), 25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(10 + -1 * sin(tha), 25.3 + -1 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(18 + sin(tha), -25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(10 + -1 * sin(tha), -25.3 + -1 * cos(tha));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-9 + sin(tha), 25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-17 + -1 * sin(tha), 25.3 + -1 * cos(tha));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-9 + sin(tha), -25.5 + cos(tha));
	}

	for (int i = 0; i < 180; i++)
	{
		tha = i*3.142 / 180;
		glVertex2f(-17 + -1 * sin(tha), -25.3 + -1 * cos(tha));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-25, 22);
	glVertex2f(-19, 13);
	glVertex2f(-19, 12.5);
	glVertex2f(-25, 21.5);


	glVertex2f(-25, -22);
	glVertex2f(-19, -13);
	glVertex2f(-19, -12.5);
	glVertex2f(-25, -21.5);

	glEnd();
}

void fish()
{
	glBegin(GL_TRIANGLES);
	glColor3f(0.6, 0, 0);
	glVertex2f(-25, -6.25);
	glVertex2f(0, -18.75);
	glVertex2f(0, 18.75);

	glColor3f(1, 0, 0);
	glVertex2f(0, -18.75);
	glVertex2f(12.5, -12.5);
	glVertex2f(12.5, -25);

	glVertex2f(0, 18.75);
	glVertex2f(12.5, 18.75);
	glVertex2f(12.5, 25);


	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.501960784313725, 0, 0);
	glVertex2f(0, -18.75);
	glVertex2f(12.5, -12.5);
	glVertex2f(18.75, -6.25);
	glVertex2f(18.75, 0);
	glVertex2f(18.75, 6.25);
	glVertex2f(12.5, 18.75);
	glVertex2f(0, 18.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.250980392156863, 0, 0);
	glVertex2f(18.75, -6.25);
	glVertex2f(18.75, 0);
	glVertex2f(18.75, 6.25);
	glVertex2f(25, 12.5);
	glVertex2f(25, -12.5);


	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0.501960784313725);
	glVertex2f(-6.25, 0);
	glVertex2f(-12.5, 0);
	glVertex2f(-12.5, -6.25);
	glVertex2f(-6.25, -6.25);
	glEnd();
}
void fish2()
{
	glBegin(GL_TRIANGLES);
	glColor3f(0.36078431372549, 0.36078431372549, 0.36078431372549);
	glVertex2f(-25, -6.25);
	glVertex2f(0, -18.75);
	glVertex2f(0, 18.75);

	glColor3f(0.615686274509804, 0.0666666666666667, 0.0666666666666667);
	glVertex2f(0, -18.75);
	glVertex2f(12.5, -12.5);
	glVertex2f(12.5, -25);

	glVertex2f(0, 18.75);
	glVertex2f(12.5, 18.75);
	glVertex2f(12.5, 25);


	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.47843137254902, 0.470588235294118, 0.470588235294118);
	glVertex2f(0, -18.75);
	glVertex2f(12.5, -12.5);
	glVertex2f(18.75, -6.25);
	glVertex2f(18.75, 0);
	glVertex2f(18.75, 6.25);
	glVertex2f(12.5, 18.75);
	glVertex2f(0, 18.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.615686274509804, 0.0666666666666667, 0.0666666666666667);
	glVertex2f(18.75, -6.25);
	glVertex2f(18.75, 0);
	glVertex2f(18.75, 6.25);
	glVertex2f(25, 12.5);
	glVertex2f(25, -12.5);


	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.615686274509804, 0.0666666666666667, 0.0666666666666667);
	glVertex2f(-6.25, 0);
	glVertex2f(-12.5, 0);
	glVertex2f(-12.5, -6.25);
	glVertex2f(-6.25, -6.25);
	glEnd();


}