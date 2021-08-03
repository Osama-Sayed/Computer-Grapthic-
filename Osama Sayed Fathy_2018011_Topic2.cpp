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

void burger();
void juise();
void ear();
void eye();
/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay();
//position and rotation
float fx1, fy1, fr1, fx2, fy2, fr2;
int main(int argc, char* argv[])
{
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
	glutCreateWindow("Competition");
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
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
// background

// ********************  background mid ***********************************//

	glBegin(GL_QUADS);
	glColor3f(0.568627450980392, 0.674509803921569, 0.756862745098039);
	glVertex2f(-100, 23.2);
	glVertex2f(-100, -69.9);
	glVertex2f(-24, -69.9);
	glVertex2f(-24, 23.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.635294117647059, 0.76078431372549, 0.850980392156863);
	glVertex2f(-71.9, 23.2);
	glVertex2f(-24.4, 23.2);
	glVertex2f(-24.4, -41.8);
	glVertex2f(-71.9, -41.8);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.568627450980392, 0.674509803921569, 0.756862745098039);
	glVertex2f(16, 23.2);
	glVertex2f(100, 23.2);
	glVertex2f(100, -69.9);
	glVertex2f(16, -69.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.635294117647059, 0.76078431372549, 0.850980392156863);
	glVertex2f(60, 23.2);
	glVertex2f(100, 23.2);
	glVertex2f(100, -41.8);
	glVertex2f(60, -41.8);
	glEnd();
	//belong to mid 
	glBegin(GL_POLYGON);
	glColor3f(0.474509803921569, 0.584313725490196, 0.67843137254902);
	//glColor3f(0.525490196078431, 0.666666666666667, 0.768627450980392);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-6.95 + 31 * cos(rad), -36 + 50 * sin(rad));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.474509803921569, 0.584313725490196, 0.67843137254902);
	glVertex2f(-26.9, 23.2);
	glVertex2f(-24.7, -2.9);
	glVertex2f(16, -2.9);
	glVertex2f(18.5, 23.2);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.474509803921569, 0.584313725490196, 0.67843137254902);
	glVertex2f(-75.4, -46.6);
	glVertex2f(-35, -46.6);
	glVertex2f(-35, -57.5);
	glVertex2f(-73.1, -57.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.474509803921569, 0.584313725490196, 0.67843137254902);
	glVertex2f(-81.6, -51.5);
	glVertex2f(-81.6, -57.5);
	glVertex2f(-73, -57.5);
	glVertex2f(-73, -51.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.474509803921569, 0.584313725490196, 0.67843137254902);
	glVertex2f(-39.8, -57.5);
	glVertex2f(-38, -69.9);
	glVertex2f(-24.4, -69.9);
	glVertex2f(-24.4, -57.5);
	glEnd();



	//footer

	glBegin(GL_QUADS);
	glColor3f(0.811764705882353, 0.901960784313726, 0.956862745098039);
	glVertex2f(-100,-100);
	glVertex2f(-100,-75.6);
	glVertex2f(100,-75.6);
	glVertex2f(100,-100);
	glEnd();
	//white
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-100, -75.6);
	glVertex2f(-100, -69.9);
	glVertex2f(100, -69.9);
	glVertex2f(100, -75.6);
	glEnd();

	//header
	glBegin(GL_QUADS);
	glColor3f(0.305882352941176, 0.419607843137255, 0.474509803921569);
	glVertex2f(-100, 23.3);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, 23.3);
	glEnd();
		//inner head
	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(-90.4,93.7);
	glVertex2f(-50.1, 93.7);
	glVertex2f(-50.1, 31);
	glVertex2f(-90.4, 31);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(-41.9, 93.7);
	glVertex2f(-2.6, 93.7);
	glVertex2f(-2.6, 31);
	glVertex2f(-41.9, 31);
	glEnd();

			// lines
	//yellow
	glBegin(GL_QUADS);
	glColor3f(0.976470588235294, 0.733333333333333, 0.0627450980392157);
	glVertex2f(4.8, 92.6);
	glVertex2f(46.8, 92.6);
	glVertex2f(46.8, 88.3);
	glVertex2f(4.8, 88.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.976470588235294, 0.733333333333333, 0.0627450980392157);
	glVertex2f(52.8, 93.1);
	glVertex2f(94.9, 93.1);
	glVertex2f(94.9, 88.8);
	glVertex2f(52.8, 88.8);
	glEnd();

	//under yallow
	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(4.8, 84.5);
	glVertex2f(32.9, 84.5);
	glVertex2f(32.9, 80);
	glVertex2f(4.8, 80);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(4.8, 76.5);
	glVertex2f(32.9, 76.5);
	glVertex2f(32.9, 72.3);
	glVertex2f(4.8, 72.3);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(40.6, 84.5);
	glVertex2f(46.8, 84.5);
	glVertex2f(46.8, 80.1);
	glVertex2f(40.6, 80.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(40.6, 76.5);
	glVertex2f(46.8, 76.5);
	glVertex2f(46.8, 72.3);
	glVertex2f(40.6, 72.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(52.8, 84.8);
	glVertex2f(80.9, 84.8);
	glVertex2f(80.9, 80.6);
	glVertex2f(52.8, 80.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(52.8, 76.9);
	glVertex2f(80.9, 76.9);
	glVertex2f(80.9, 72.6);
	glVertex2f(52.8, 72.6);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(88.5, 84.8);
	glVertex2f(94.9, 84.8);
	glVertex2f(94.9, 80.6);
	glVertex2f(88.5, 80.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(88.5, 76.9);
	glVertex2f(94.9, 76.9);
	glVertex2f(94.9, 72.6);
	glVertex2f(88.5, 72.6);
	glEnd();

	///////////////////////////////////////////////////////////////////////////

	//light yellow
	glBegin(GL_QUADS);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(4.8, 69.1);
	glVertex2f(46.8, 69.1);
	glVertex2f(46.8, 64);
	glVertex2f(4.8, 64);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(52.8, 69.4);
	glVertex2f(94.9, 69.4);
	glVertex2f(94.9, 65.2);
	glVertex2f(52.8, 65.2);
	glEnd();

	//under yallow
	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(4.8, 60.1);
	glVertex2f(32.9, 60.1);
	glVertex2f(32.9, 55.8);
	glVertex2f(4.8, 55.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(4.8, 52.2);
	glVertex2f(32.9, 52.2);
	glVertex2f(32.9, 48);
	glVertex2f(4.8, 48);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(40.6, 60.1);
	glVertex2f(46.8, 60.1);
	glVertex2f(46.8, 55.8);
	glVertex2f(40.6, 55.8);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(40.6, 52.2);
	glVertex2f(46.8, 52.2);
	glVertex2f(46.8, 48);
	glVertex2f(40.6, 48);
	glEnd();


	////////////////////////////////////////////////////////
	glBegin(GL_QUADS);
	glColor3f(0.670588235294118, 0.811764705882353, 0.874509803921569);
	glVertex2f(4.8, 43.8);
	glVertex2f(46.8, 43.8);
	glVertex2f(46.8, 39.5);
	glVertex2f(4.8, 39.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(4.8, 35.9);
	glVertex2f(32.9, 35.9);
	glVertex2f(32.9, 31.6);
	glVertex2f(4.8, 31.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(40.6, 35.9);
	glVertex2f(46.8, 35.9);
	glVertex2f(46.8, 31.6);
	glVertex2f(40.6, 31.6);
	glEnd();

	//////////////////////////////////////////////////


	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(52.8, 60.4);
	glVertex2f(80.9, 60.4);
	glVertex2f(80.9, 56.3);
	glVertex2f(52.8, 56.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(52.8, 52.5);
	glVertex2f(80.9, 52.5);
	glVertex2f(80.9, 48.3);
	glVertex2f(52.8, 48.3);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(88.5, 60.4);
	glVertex2f(94.9, 60.4);
	glVertex2f(94.9, 56.3);
	glVertex2f(88.5, 56.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(88.5, 52.5);
	glVertex2f(94.9, 52.5);
	glVertex2f(94.9, 48.3);
	glVertex2f(88.5, 48.3);
	glEnd();

	/////////////////////////////////////////////////

	glBegin(GL_QUADS);
	glColor3f(0.670588235294118, 0.811764705882353, 0.874509803921569);
	glVertex2f(52.8, 45.1);
	glVertex2f(94.9, 45.1);
	glVertex2f(94.9, 39.9);
	glVertex2f(52.8, 39.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(52.8, 37.1);
	glVertex2f(80.9, 37.1);
	glVertex2f(80.9, 32);
	glVertex2f(52.8, 32);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(88.5, 37.1);
	glVertex2f(94.9, 37.1);
	glVertex2f(94.9, 32);
	glVertex2f(88.5, 32);

	//////////////////////////////////////////////////////////////////////////////////
	// juice
	glBegin(GL_QUADS);
	glColor3f(0.796078431372549, 0.866666666666667, 0.956862745098039);
	glVertex2f(-53.8,85.1);
	glVertex2f(-53.8,83.7);
	glVertex2f(-58.8, 83.5);
	glVertex2f(-59.6,85);

	glVertex2f(-58.8, 83.5);
	glVertex2f(-59.6, 85);
	glVertex2f(-61.5,81.9);
	glVertex2f(-60.2, 81.4);

	glVertex2f(-61.5, 81.9);
	glVertex2f(-60.2, 81.4);
	glVertex2f(-61.3, 74.6);
	glVertex2f(-62.8, 74.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.894117647058824, 0.96078431372549, 0.992156862745098);
	glVertex2f(-57.9, 74.5);
	glVertex2f(-57.4, 71.5);
	glVertex2f(-72.9, 71.5);
	glVertex2f(-72.4, 74.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.929411764705882, 0.313725490196078, 0.349019607843137);
	glVertex2f(-58.6, 71.6);
	glVertex2f(-60.4,49.2);
	glVertex2f(-68.9, 49.2);
	glVertex2f(-71.2, 71.6);
	glEnd();

	// burger //

	glBegin(GL_POLYGON);
	glColor3f(1, 0.823529411764706, 0.466666666666667);
	for (int i = -23; i<202; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-74.8 + -10.2 * cos(rad), 48.1 + 6.1 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0.823529411764706, 0.466666666666667);
	for (int i = -23; i<202; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-74.8 + -10.2 * cos(rad), 39+ 6.1 * sin(rad));
	}
	glEnd();

	// red 
	glBegin(GL_POLYGON);
	glColor3f(0.815686274509804, 0.509803921568627, 0.368627450980392);
	glVertex2f(-84.8, 43.7);
	glVertex2f(-85, 43);
	glVertex2f(-84.8, 42.5);
	glVertex2f(-83.4, 41.3);
	glVertex2f(-83.1, 41.3);
	glVertex2f(-83.1, 43.7);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.815686274509804, 0.509803921568627, 0.368627450980392);
	glVertex2f(-83.1, 43.7);
	glVertex2f(-83.1, 41.3);
	glVertex2f(-82.3, 40.8);
	glVertex2f(-68.4, 40.8);
	glVertex2f(-67.6, 41.1);
	glVertex2f(-67.6, 44.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.815686274509804, 0.509803921568627, 0.368627450980392);
	glVertex2f(-67.6, 44.1);
	glVertex2f(-67.6, 41.1);
	glVertex2f(-67.3, 41.3);
	glVertex2f(-66.3, 41.3);
	glVertex2f(-65.8, 41.7);
	glVertex2f(-65.8, 44.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.815686274509804, 0.509803921568627, 0.368627450980392);
	glVertex2f(-65.8, 44.1);
	glVertex2f(-65.8, 41.7);
	glVertex2f(-65.3, 41.7);
	glVertex2f(-66.3, 41.3);
	glVertex2f(-64.7, 42.3);
	glVertex2f(-64.7, 44.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.815686274509804, 0.509803921568627, 0.368627450980392);
	glVertex2f(-64.7, 44.1);
	glVertex2f(-64.7, 42.3);
	glVertex2f(-64.6, 42.8);
	glVertex2f(-64.6, 43.6);
	glVertex2f(-64.7, 44);
	glVertex2f(-64.7, 44.1);
	glEnd();
	// green 
	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-64.7,46.4);
	glVertex2f(-63.1,45.6);
	glVertex2f(-63.1,44.9);
	glVertex2f(-64.7,44.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-64.7, 46.4);
	glVertex2f(-84.5, 45.7);
	glVertex2f(-84.5, 43.6);
	glVertex2f(-64.7, 44.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-84.5, 45.7);
	glVertex2f(-85.3, 45.1);
	glVertex2f(-85.5, 44.8);
	glVertex2f(-85.5, 44.2);
	glVertex2f(-84.9, 43.7);
	glVertex2f(-84.5, 43.6);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-80.5, 44);
	glVertex2f(-78.8, 43.2);
	glVertex2f(-77.9, 42.8);
	glVertex2f(-77.6, 44.2);
	glVertex2f(-77.1, 42.2);
	glVertex2f(-77.1, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-77.1, 44);
	glVertex2f(-77.1, 42.2);
	glVertex2f(-76.5, 42.2);
	glVertex2f(-76.5, 42);
	glVertex2f(-74.3, 42);
	glVertex2f(-74.3, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-74.3, 44);
	glVertex2f(-74.3, 42);
	glVertex2f(-73.6, 42.2);
	glVertex2f(-72.5, 42.2);
	glVertex2f(-71.8, 42.8);
	glVertex2f(-71.8, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-71.8, 44);
	glVertex2f(-71.8, 42.8);
	glVertex2f(-71.4, 42.8);
	glVertex2f(-70.5, 43.2);
	glVertex2f(-69.8, 43.2);
	glVertex2f(-69.8, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.803921568627451, 0.4);
	glVertex2f(-69.8, 44);
	glVertex2f(-69.8, 43.2);
	glVertex2f(-69.1, 44);
	glEnd();

	//*************************************************************************//

	//second juse 

	glBegin(GL_POLYGON);
	glColor3f(0.83921568627451, 0.882352941176471, 0.905882352941176);
	for (int i = 0; i<180.1; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-18.4 + 7.4 * cos(rad), 72.4 + 4.9 * sin(rad));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.894117647058824, 0.96078431372549, 0.992156862745098);
	glVertex2f(-10.1,73.6);
	glVertex2f(-26.6, 73.6);
	glVertex2f(-26.2, 70.9);
	glVertex2f(-10.7, 70.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.83921568627451, 0.882352941176471, 0.905882352941176);
	glVertex2f(-11.7, 70.9);
	glVertex2f(-25.2, 70.9);
	glVertex2f(-23.5, 49.1);
	glVertex2f(-14, 49.1);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.972549019607843, 0.682352941176471, 0.733333333333333);
	glVertex2f(-13.7, 67.8);
	glVertex2f(-23.5, 67.8);
	glVertex2f(-21.9, 51.5);
	glVertex2f(-15.7, 51.5);
	glEnd();

	// shalemo
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-10.8, 84.9);
	glVertex2f(-10.5, 83.5);
	glVertex2f(-15.8, 83);
	glVertex2f(-16.5, 84.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-15.8, 83);
	glVertex2f(-16.5, 84.5);
	glVertex2f(-18.4, 81.4);
	glVertex2f(-17.15, 81.05);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-17.15, 81.05);
	glVertex2f(-18.4, 81.4);
	glVertex2f(-18.6, 80.6);
	glVertex2f(-17.2, 80.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-18.6, 80.6);
	glVertex2f(-17.2, 80.6);
	glVertex2f(-17.6, 77.2);
	glVertex2f(-19, 77.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.945098039215686, 0.96078431372549, 0.984313725490196);
	glVertex2f(-17.6, 77.2);
	glVertex2f(-19, 77.2);
	glVertex2f(-19.4, 73.6);
	glVertex2f(-18.2, 73.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.925490196078431, 0.949019607843137, 0.972549019607843);
	glVertex2f(-20.1, 70.9);
	glVertex2f(-18.5, 70.9);
	glVertex2f(-18.9, 67.9);
	glVertex2f(-20.4, 67.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.976470588235294, 0.780392156862745, 0.792156862745098);
	glVertex2f(-20.4, 67.9);
	glVertex2f(-18.9, 67.9);
	glVertex2f(-20.2, 59);
	glVertex2f(-21.7, 59.2);
	glEnd();
//**************************************************************************************//

	//cake

	glBegin(GL_POLYGON);
	glColor3f(0.988235294117647, 0.72156862745098, 0.466666666666667);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-30.2 + 6 * cos(rad), 51.9 + 6.1 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.988235294117647, 0.72156862745098, 0.466666666666667);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-26.1 + 4.8 * cos(rad), 47.4 + 6.1 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.988235294117647, 0.72156862745098, 0.466666666666667);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-35.4 + 4.5 * cos(rad), 47 + 5.4 * sin(rad));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.862745098039216, 0.596078431372549);
	glVertex2f(-36.2,42.7);
	glVertex2f(-24.8,42.7);
	glVertex2f(-25.8,36.8);
	glVertex2f(-34.8,36.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.988235294117647, 0.72156862745098, 0.466666666666667);
	glVertex2f(-36.2, 42.7);
	glVertex2f(-24.8, 42.7);
	glVertex2f(-24.8, 46.6);
	glVertex2f(-36.2, 46.6);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.988235294117647, 0.72156862745098, 0.466666666666667);

	glVertex2f(-36.2, 42.7);
	glVertex2f(-35.2, 41.8);
	glVertex2f(-34.4, 42.7);

	glVertex2f(-34.4, 42.7);
	glVertex2f(-33.3, 41.8);
	glVertex2f(-32.5, 42.7);

	glVertex2f(-32.5, 42.7);
	glVertex2f(-31.2, 41.8);
	glVertex2f(-30.4, 42.7);

	glVertex2f(-30.4, 42.7);
	glVertex2f(-29.4, 41.8);
	glVertex2f(-28.6, 42.7);

	glVertex2f(-28.6, 42.7);
	glVertex2f(-27.7, 41.8);
	glVertex2f(-26.7, 42.7);

	glVertex2f(-26.7, 42.7);
	glVertex2f(-25.8, 41.8);
	glVertex2f(-24.9, 42.7);
	glEnd();

	


	// ****************************************************//

	//**************  character  *********************//

	// el kom el4mal
	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-6.9,-5.3);
	glVertex2f(-7.3, -5.3);
	glVertex2f(-7.8, -5.6);
	glVertex2f(-8.2, -5.85);
	glVertex2f(-8.5, -6.05);
	glVertex2f(-8.5, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-8.5, -10);
	glVertex2f(-8.5, -6.05);
	glVertex2f(-8.95, -6.32);
	glVertex2f(-9.3, -6.52);
	glVertex2f(-9.75, -6.8);
	glVertex2f(-10.12, -7.05);
	glVertex2f(-10.55, -7.3);
	glVertex2f(-10.55, -13.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-10.55, -13.1);
	glVertex2f(-10.55, -7.3);
	glVertex2f(-10.9, -7.5);
	glVertex2f(-11.3, -7.8);
	glVertex2f(-11.6, -8);
	glVertex2f(-12, -8.3);
	glVertex2f(-12.25, -8.5);
	glVertex2f(-12.25, -15.8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-12.25, -15.8);
	glVertex2f(-12.25, -8.5);
	glVertex2f(-12.6, -8.72);
	glVertex2f(-12.5, -9);
	glVertex2f(-13.3, -9.25);
	glVertex2f(-13.6, -9.5);
	glVertex2f(-13.8, -9.72);
	glVertex2f(-13.8, -18.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-13.8, -18.2);
	glVertex2f(-13.8, -9.72);
	glVertex2f(-14.4, -10.38);
	glVertex2f(-15.32, -11.4);
	glVertex2f(-16.2, -12.6);
	glVertex2f(-16.55, -13.29);
	glVertex2f(-17, -14.1);
	glVertex2f(-17, -23);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-17, -23);
	glVertex2f(-17, -14.1);
	glVertex2f(-17.6, -15.43);
	glVertex2f(-17.9, -16.29);
	glVertex2f(-18.39, -17.29);
	glVertex2f(-18.95, -18.85);
	glVertex2f(-19.78, -21.25);
	glVertex2f(-19.78, -27.3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-19.78, -27.3);
	glVertex2f(-19.78, -21.25);
	glVertex2f(-20, -22);
	glVertex2f(-20.4, -23.4);
	glVertex2f(-20.7, -24.5);
	glVertex2f(-20.95, -25.2);
	glVertex2f(-21.28, -26.1);
	glVertex2f(-21.28, -29.6);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-21.28, -29.6);
	glVertex2f(-21.28, -26.1);
	glVertex2f(-21.58, -27.13);
	glVertex2f(-21.77, -28.02);
	glVertex2f(-22.01, -29.2);
	glVertex2f(-22.28, -30.3);
	glVertex2f(-22.25, -31.5);
	glVertex2f(-22.25, -31.8);
	glEnd();

	// el kom elymen

	glBegin(GL_POLYGON);
	glColor3f(0.929411764705882, 0.105882352941176, 0.141176470588235);
	glVertex2f(14.09, -4.9);
	glVertex2f(15.58, -5.8);
	glVertex2f(17.59, -7.3);
	glVertex2f(19.2, -8.45);
	glVertex2f(20.36, -9.5);
	glVertex2f(21.61, -10.7);
	glVertex2f(22.7, -11.8);
	glVertex2f(19.4, -11.8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.929411764705882, 0.105882352941176, 0.141176470588235);
	glVertex2f(19.4, -11.8);
	glVertex2f(22.7, -11.8);
	glVertex2f(23.52, -12.8);
	glVertex2f(27.21, -18.2);
	glVertex2f(28.7, -20.5);
	glVertex2f(30.45, -23.54);
	glVertex2f(32.7, -26.9);
	glVertex2f(32.73, -28.32);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.929411764705882, 0.105882352941176, 0.141176470588235);
	glVertex2f(32.73, -28.32);
	glVertex2f(31.4, -29.81);
	glVertex2f(29.91, -31.29);
	glVertex2f(28.5, -32.6);
	glVertex2f(26.63, -34.3);
	glVertex2f(25.12, -35.5);
	glVertex2f(22.4, -31.2);
	glVertex2f(14.1, -5);
	glEnd();

	//t-shirt

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(22.4, -31.2);
	glVertex2f(14.1, -5);
	glVertex2f(-6.9, -5.3);
	glVertex2f(-22.25, -31.8);
	glVertex2f(-15, -38.5);
	glVertex2f(-13.57, -69.9);
	glVertex2f(20.4, -69.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-19.5, -20.7);
	glVertex2f(-8.25, -20.7);
	glVertex2f(-8.25, -33.6);
	glVertex2f(-22.25, -31.8);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0.929411764705882, 0.105882352941176, 0.141176470588235);
	for (int i = -234; i<-84; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(18.8 + 26.9* cos(rad), -29.3 + 29.28 * sin(rad));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.929411764705882, 0.105882352941176, 0.141176470588235);
	glVertex2f(21.1, -58.49);
	glVertex2f(22.4, -31.2);
	glVertex2f(14.1, -5);
	glVertex2f(2.8, -5);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(1.6, -7.6);
	glVertex2f(-3.68,-17.4);
	glVertex2f(-8.4, -10.8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.929411764705882, 0.105882352941176, 0.141176470588235);
	glVertex2f(-8.1, -29.25);
	glVertex2f(-8.45, -22.17);
	glVertex2f(-8.38, -13.72);
	glVertex2f(-8.25, -10.9);
	glVertex2f(-3.68, -17.52);
	glVertex2f(-3.18, -24.3);
	glEnd();

	//ya2a 
	glBegin(GL_QUADS);
	glColor3f(0.92156862745098, 0.109803921568627, 0.149019607843137);
	glVertex2f(1.89, -7.5);
	glVertex2f(-3.61, -13.32);
	glVertex2f(-7.4, -3.72);
	glVertex2f(-2.95, -1.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(5.32, -7.65);
	glVertex2f(14, -5);
	glVertex2f(15.63, -6);
	glVertex2f(11.1, -17.53);
	glVertex2f(5.32, -8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.92156862745098, 0.109803921568627, 0.149019607843137);
	glVertex2f(10.3, -1.45);
	glVertex2f(14.31, -3.98);
	glVertex2f(11.18, -13.53);
	glVertex2f(4.9, -7.2);
	glEnd();

	//body

	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.568627450980392, 0.325490196078431);
	glVertex2f(8.35, -2.39);
	glVertex2f(8.35, 1.45);
	glVertex2f(-1.1, 1.45);
	glVertex2f(-1.1, -2.49);
	glVertex2f(-1.86, -2.6);
	glVertex2f(1.80, -7.35);
	glVertex2f(4.9, -7.35);
	glVertex2f(9.3, -2.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.968627450980392, 0.568627450980392, 0.317647058823529);
	glVertex2f(1.77, -7.35);
	glVertex2f(4.9, -7.35);
	glVertex2f(3.6, -17.5);
	glEnd();
	/**********/
	//******* right hand ****************//

	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(32.5, -28.75);
	glVertex2f(33.12, -30.3);
	glVertex2f(33.99, -32.5);
	glVertex2f(34.36, -33.61);
	glVertex2f(34.76, -34.8);
	glVertex2f(35, -35.68);
	glVertex2f(35.13, -36.5);
	glVertex2f(35.4, -36.91);
	glVertex2f(35.52, -37.35);
	glVertex2f(35.79, -38.23);
	glVertex2f(35, -35.68);
	glVertex2f(35.92, -39.05);
	glVertex2f(29.93, -39.05);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(29.93, -39.05);
	glVertex2f(35.92, -39.05);
	glVertex2f(35.9, -41.48);
	glVertex2f(35.87, -41.8);
	glVertex2f(35.81, -42.39);
	glVertex2f(35.79, -42.49);
	glVertex2f(35.71, -42.7);
	glVertex2f(35.6, -43.05);
	glVertex2f(35.5, -43.37);
	glVertex2f(35.32, -43.9);
	glVertex2f(35.05, -44.85);
	glVertex2f(34.77, -45.8);
	glVertex2f(34.31, -46.92);
	glVertex2f(32, -46.92);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(32, -46.92);
	glVertex2f(34.31, -46.92);
	glVertex2f(34.02, -47.85);
	glVertex2f(33.8, -48.35);
	glVertex2f(33.51, -49);
	glVertex2f(33.23, -49.65);
	glVertex2f(33.07, -49.98);
	glVertex2f(32.82, -50.3);
	glVertex2f(32.61, -50.51);
	glVertex2f(32.38, -49.3);
	glVertex2f(32.2, -48.23);
	glVertex2f(31.98, -46.96);
	glVertex2f(31.71, -45.8);
	glVertex2f(34.61, -45.8);	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(34.61, -45.8);
	glVertex2f(31.71, -45.8);
	glVertex2f(31.51, -44.69);
	glVertex2f(31.22, -43.55);
	glVertex2f(30.84, -41.87);
	glVertex2f(30.39, -40.5);
	glVertex2f(29.91, -39.01);
	glVertex2f(29.3, -37);
	glVertex2f(28.61, -35.31);
	glVertex2f(28.2, -34.05);
	glVertex2f(28, -33.51);
	glVertex2f(27.95, -33.3);
	glVertex2f(32.5, -28.75);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(32.61, -50.51);
	glVertex2f(32.82, -50.3);
	glVertex2f(33.07, -49.98);
	glVertex2f(33.23, -49.65);
	glVertex2f(33.51, -49);
	glVertex2f(33.8, -48.35);
	glVertex2f(34.02, -47.85);
	glVertex2f(34.31, -46.92);
	glVertex2f(34.77, -45.8);
	glVertex2f(35.32, -43.9);
	glVertex2f(35.5, -43.37);
	glVertex2f(35.6, -43.05);
	glVertex2f(35.71, -42.7);
	glVertex2f(35.79, -42.49);
	glVertex2f(35.81, -42.39);
	glVertex2f(35.87, -41.8);
	glVertex2f(35.9, -41.48);
	glVertex2f(35.92, -39.05);
	glVertex2f(36, -39.05);
	glVertex2f(36, -50.51);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(36, -39.05);
	glVertex2f(36, -61.21);
	glVertex2f(37.21, -62.3);
	glVertex2f(36.85, -63.3);
	glVertex2f(36.55, -64);
	glVertex2f(36.23, -64.65);
	glVertex2f(36.05, -65.05);
	glVertex2f(35.78, -65.45);
	glVertex2f(35.32, -66.1);
	glVertex2f(35.1, -66.43);
	glVertex2f(34.54, -67.1);
	glVertex2f(34.1, -67.6);
	glVertex2f(33.53, -68.2);
	glVertex2f(32.61, -69.05);
	glVertex2f(32.42, -69.2);
	glVertex2f(32.2, -69.4);
	glVertex2f(31.95, -69.52);
	glVertex2f(31.71, -69.71);
	glVertex2f(31.5, -69.9);
	glVertex2f(30.8, -69.9); // start
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(30.8, -69.9); // start
	glVertex2f(30.8, -69.58);
	glVertex2f(30.73, -61.05);
	glVertex2f(30.57, -68.38);
	glVertex2f(30.41, -68.11);
	glVertex2f(30.3, -67.82);
	glVertex2f(30.25, -67.63);
	glVertex2f(30.07, -67.35);
	glVertex2f(29.81, -67.05);
	glVertex2f(29.55, -66.7);
	glVertex2f(29.27, -66.4);
	glVertex2f(28.89, -66.12);
	glVertex2f(28.5, -65.85);
	glVertex2f(28.2, -65.62);
	glVertex2f(27.9, -65.45);
	glVertex2f(27.68, -65.29);
	glVertex2f(27.5, -65.15); // end
	glVertex2f(27.85, -65.05);
	glVertex2f(28.23, -64.9);
	glVertex2f(28.38, -64.75);
	glVertex2f(28.55, -64.6);
	glVertex2f(28.9, -64.4);
	glVertex2f(29.15, -64.21);
	glVertex2f(29.57, -63.9);
	glVertex2f(30.22, -63.27);
	glVertex2f(30.88, -62.6);
	glVertex2f(31.38, -61.9);
	glVertex2f(32.1, -60.4);
	glVertex2f(32.48, -59.1);
	glVertex2f(32.71, -58.15);
	glVertex2f(32.79, -56.77);
	glVertex2f(32.79, -53.62);
	glVertex2f(32.68, -50.8);
	glVertex2f(32.62, -50.62);
	glVertex2f(32.6, -50.51);
	glVertex2f(36, -50.51);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(30.8, -69.9); // start
	glVertex2f(30.8, -69.58);
	glVertex2f(30.57, -68.38);
	glVertex2f(30.41, -68.11);
	glVertex2f(30.3, -67.82);
	glVertex2f(30.25, -67.63);
	glVertex2f(30.07, -67.35);
	glVertex2f(29.81, -67.05);
	glVertex2f(29.55, -66.7);
	glVertex2f(29.27, -66.4);
	glVertex2f(28.89, -66.12);
	glVertex2f(28.5, -65.85);
	glVertex2f(28.2, -65.62);
	glVertex2f(27.9, -65.45);
	glVertex2f(27.68, -65.29);
	glVertex2f(27.5, -65.15); // end
	glVertex2f(26.61, -64.89); // start
	glVertex2f(26.1, -64.59);
	glVertex2f(25.17, -64.31);
	glVertex2f(23.9, -63.97);
	glVertex2f(23.22, -63.8);
	glVertex2f(22.55, -63.64);
	glVertex2f(22.12, -63.6);
	glVertex2f(21.74, -63.7);
	glVertex2f(21.19, -63.8);
	glVertex2f(20.48, -64);
	glVertex2f(19.84, -64.2);
	glVertex2f(18.45, -64.6);
	glVertex2f(17.38, -65.12);
	glVertex2f(16.33, -65.6);
	glVertex2f(15.6, -66.1);
	glVertex2f(15.1, -66.32);
	glVertex2f(15.1, -69.9); // end
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(15.1, -69.9); // end
	glVertex2f(15.1, -66.32);
	glVertex2f(14.72, -66.62);
	glVertex2f(13.55, -67.51);
	glVertex2f(13.1, -68.03);
	glVertex2f(12.68, -68.6);
	glVertex2f(12.22, -69.34);
	glVertex2f(12.15, -69.55);
	glVertex2f(12.08, -69.9);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.972549019607843, 0.603921568627451, 0.419607843137255);
	glVertex2f(14.24,-69.9);
	glVertex2f(16.34, -69.9);
	glVertex2f(18.4, -65.8);
	glVertex2f(18.65, -69.9);
	glVertex2f(20.28, -69.9);
	glVertex2f(21.07, -67);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.972549019607843, 0.603921568627451, 0.419607843137255);
	glVertex2f(22.44, -69.9);
	glVertex2f(26.75, -69.9);
	glVertex2f(25.57, -69);
	glVertex2f(23.4, -69);
	glEnd();

	// right hand 
	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(-21.08, -33); 
	glVertex2f(-21.37, -33.74);
	glVertex2f(-21.68, -34.51);
	glVertex2f(-21.97, -35.3);
	glVertex2f(-22.49, -36.47);
	glVertex2f(-22.8, -37.12);
	glVertex2f(-23.2, -37.87);
	glVertex2f(-23.7, -38.8);
	glVertex2f(-24.36, -39.78);
	glVertex2f(-24.93, -40.62);
	glVertex2f(-25.45, -41.39);
	glVertex2f(-25.56, -41.57);
	glVertex2f(-18.14, -41.6);
	glVertex2f(-17.91, -41.20);
	glVertex2f(-17.52, -40.38);
	glVertex2f(-17.12, -39.5); 
	glVertex2f(-16.78, -38.65); 
	glVertex2f(-16.46, -37.9);
	glVertex2f(-16.29, -37.40);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(-21.75, -47.15); 
	glVertex2f(-21.86, -47.57);
	glVertex2f(-22.2, -48.07);
	glVertex2f(-22.6, -48.53);
	glVertex2f(-23.02, -49.03);
	glVertex2f(-23.45, -49.48);
	glVertex2f(-23.79, -49.83);
	glVertex2f(-24.22, -50.26);
	glVertex2f(-24.54, -50.5);
	glVertex2f(-24.82, -50.74); //start
	glVertex2f(-25.63, -50.6);
	glVertex2f(-26.12, -50.57);
	glVertex2f(-27.29, -50.55);
	glVertex2f(-29.3, -50.54);
	glVertex2f(-30.57, -50.50);
	glVertex2f(-30.81, -50.53); 
	glVertex2f(-32.82, -50.50); 
	glVertex2f(-34.59, -50.50);
	glVertex2f(-35.27, -50.57);
	glVertex2f(-35.57, -50.61);
	glVertex2f(-35.97, -50.68);
	glVertex2f(-36.39, -50.74);
	glVertex2f(-36.75, -50.92);
	glVertex2f(-37.88, -50.99);
	glVertex2f(-38.55, -50.99);
	glVertex2f(-39.15, -51.03);
	glVertex2f(-39.43, -51.14);
	glVertex2f(-40.49, -51.42);
	glVertex2f(-40.98, -51.49);
	glVertex2f(-41.64, -51.56);
	glVertex2f(-41.97, -51.6);
	glVertex2f(-42.25, -51.69);
	glVertex2f(-42.25, -49.51); 
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(-42.25, -49.51); 
	glVertex2f(-42.25, -51.69);
	glVertex2f(-42.5, -51.88);
	glVertex2f(-42.64, -52.12);
	glVertex2f(-42.64, -52.44);//end
	glVertex2f(-42.81, -52.41);
	glVertex2f(-43.02, -52.23);
	glVertex2f(-43.37, -51.91);
	glVertex2f(-43.65, -51.62);
	glVertex2f(-43.93, -51.32);
	glVertex2f(-44.18, -50.96);
	glVertex2f(-44.54, -50.57);
	glVertex2f(-44.64, -50.43); // s start
	glVertex2f(-44.04, -50.22);
	glVertex2f(-43.13, -49.76);
	glVertex2f(-42.64, -49.54);
	glVertex2f(-42.27, -49.51);
	glVertex2f(-42.03, -49.41);
	glVertex2f(-40.76, -48.78);
	glVertex2f(-40.2, -48.45);
	glVertex2f(-39.25, -48.1);
	glVertex2f(-38.65, -47.86);
	glVertex2f(-37.7, -47.29); 
	glVertex2f(-37.88, -47.15);//s end
	glVertex2f(-21.75, -47.15);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(-37.88, -47.15);
	glVertex2f(-37.7, -47.29);
	glVertex2f(-38.65, -47.86);
	glVertex2f(-39.25, -48.1);
	glVertex2f(-40.2, -48.45);
	glVertex2f(-40.76, -48.78);
	glVertex2f(-42.03, -49.41);
	glVertex2f(-42.27, -49.51);
	glVertex2f(-42.64, -49.54);
	glVertex2f(-43.13, -49.76);
	glVertex2f(-44.04, -50.22);
	glVertex2f(-44.64, -50.43);
	glVertex2f(-45.43, -50.79); // s start
	glVertex2f(-46.93, -51.4);
	glVertex2f(-47.82, -51.7);
	glVertex2f(-48.53, -51.95);
	glVertex2f(-48.95, -51.99);
	glVertex2f(-49.52, -52.01);
	glVertex2f(-50.43, -52.01);
	glVertex2f(-50.68, -51.99);
	glVertex2f(-53.32, -51.24);
	glVertex2f(-54.06, -50.96);
	glVertex2f(-55.05, -50.47);
	glVertex2f(-56.22, -49.97);//s end
	glVertex2f(-57.14, -49.52);
	glVertex2f(-58.16, -48.95);
	glVertex2f(-59.82, -48.07);
	glVertex2f(-60.7, -47.53);
	glVertex2f(-61.32, -47.15);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(-42.64, -52.44);//end
	glVertex2f(-42.64, -52.12);
	glVertex2f(-42.5, -51.88);
	glVertex2f(-42.25, -51.69);
	glVertex2f(-41.97, -51.6);
	glVertex2f(-41.64, -51.56);
	glVertex2f(-40.98, -51.49);
	glVertex2f(-40.49, -51.42);
	glVertex2f(-39.43, -51.14);
	glVertex2f(-39.15, -51.03);
	glVertex2f(-38.55, -50.99);
	glVertex2f(-37.88, -50.99);
	glVertex2f(-36.75, -50.92);
	glVertex2f(-36.39, -50.74);
	glVertex2f(-35.97, -50.68);
	glVertex2f(-35.57, -50.61);
	glVertex2f(-35.27, -50.57);
	glVertex2f(-34.59, -50.50);
	glVertex2f(-32.82, -50.50);
	glVertex2f(-30.81, -50.53);
	glVertex2f(-30.57, -50.50);
	glVertex2f(-29.3, -50.54);
	glVertex2f(-27.29, -50.55);
	glVertex2f(-26.12, -50.57);
	glVertex2f(-25.63, -50.6);
	glVertex2f(-24.82, -50.74); //start
	glVertex2f(-25, -50.93);
	glVertex2f(-26.16, -51.92);
	glVertex2f(-27.57, -52.94);
	glVertex2f(-29.41, -53.93);
	glVertex2f(-31.14, -54.67);
	glVertex2f(-31.88, -54.87);
	glVertex2f(-33.43, -55.16);
	glVertex2f(-34.28, -55.3);
	glVertex2f(-35.23, -55.33);
	glVertex2f(-36.18, -55.72);
	glVertex2f(-37.06, -55.09);
	glVertex2f(-38.33, -54.85);
	glVertex2f(-40.17, -54.09);
	glVertex2f(-42.64, -52.65);
	glVertex2f(-43.45, -51.95);
	glVertex2f(-44.68, -50.48);
	glEnd();

	//******************** Face ***********************************//
	//ear
	glPushMatrix();
	glRotatef(-5, 0, 0, 1);
	glTranslatef(-1, 0, 0);
	//glScalef(1.15, 1.15, 0);
	ear();
	glPopMatrix();

	glPushMatrix();
	glRotatef(5, 0, 0, 1);
	glTranslatef(-25, 0, 0);
	//glScalef(1.15, 1.15, 0);
	ear();
	glPopMatrix();
	//

	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.607843137254902, 0.423529411764706);
	glVertex2f(-9.76, 22.06);//end
	glVertex2f(-9.36, 18.46);
	glVertex2f(-8.98, 14.79);
	glVertex2f(-8.51, 12.53);
	glVertex2f(-8.05, 10.74);
	glVertex2f(-6.97, 7.63);
	glVertex2f(-6.22, 6.29);
	glVertex2f(-5.7, 5.2);
	glVertex2f(-4.81, 4.04);
	glVertex2f(-3.93, 3.08);
	glVertex2f(-4.47, 4);
	glVertex2f(-4.96, 4.84);
	glVertex2f(-5.51, 6.15);
	glVertex2f(-6.54, 9.3);
	glVertex2f(-6.9, 11.52);
	glVertex2f(-7.29, 13.8);
	glVertex2f(-7.42, 16.36);
	glVertex2f(-7.56, 21.15);
	glVertex2f(-7.56, 23.08);
	glVertex2f(-6.71, 23.75);
	glVertex2f(-5.63, 23.96);
	glVertex2f(-5.2, 24.18);
	glVertex2f(-1.75, 24.75);
	glVertex2f(0.37, 25.2);
	glVertex2f(5.8, 25.2);
	glVertex2f(9.78, 24.63); //start
	glVertex2f(11.8, 24.32);
	glVertex2f(13.03, 23.79);
	glVertex2f(15.63, 22.73);
	glVertex2f(16.17, 22.25);
	glVertex2f(16.38, 21.05);
	glVertex2f(16.24, 28.56);
	glVertex2f(15.92, 28.49);
	glVertex2f(13.91, 27.63); // s rm4 ymen
	glVertex2f(13.91, 25.67); 
	glVertex2f(12.92, 25.9);
	glVertex2f(12.3, 26.05);
	glVertex2f(11.6, 26.08);
	glVertex2f(7.88, 26.08);
	glVertex2f(7.29, 25.85);
	glVertex2f(7.29, 26.19); // e rm4 ymen
	glVertex2f(5.4, 25.98);
	glVertex2f(4.32, 25.92); //start
	glVertex2f(3.01, 25.85);
	glVertex2f(1.78, 25.87);
	glVertex2f(0.22, 25.98);
	glVertex2f(-0.59, 26.08);
	glVertex2f(-1.32, 26.23);
	glVertex2f(-1.85, 26.36); // s rm4 4mal
	glVertex2f(-4.04, 26.12);
	glVertex2f(-4.71, 25.98); 
	glVertex2f(-5.41, 25.73);
	glVertex2f(-5.77, 27.67);
	glVertex2f(-8.02, 28.73);
	glVertex2f(-8.74, 21.3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.749019607843137, 0.392156862745098, 0.0980392156862745);
	glVertex2f(13.91, 27.63); // s rm4 ymen
	glVertex2f(13.91, 25.67);
	glVertex2f(12.92, 25.9);
	glVertex2f(12.3, 26.05);
	glVertex2f(11.6, 26.08);
	glVertex2f(7.88, 26.08);
	glVertex2f(7.29, 25.85);
	glVertex2f(7.29, 26.19); // e rm4 ymen
	glVertex2f(12.18, 26.15);
	glVertex2f(13.29, 25.95);
	glVertex2f(13.91, 25.7);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.749019607843137, 0.392156862745098, 0.0980392156862745);
	glVertex2f(-1.5, 26.36); // s rm4 4mal
	glVertex2f(-4.04, 26.12);
	glVertex2f(-4.71, 25.98);
	glVertex2f(-5.41, 25.73);
	glVertex2f(-5.77, 27.67);
	glVertex2f(-1.85, 27.67);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.352941176470588, 0.180392156862745, 0.0666666666666667);
	glVertex2f(-8.74, 21.3);
	glVertex2f(-10.55,22.67);
	glVertex2f(-11.36, 30.8);
	glVertex2f(-8.1, 28.84);
	glVertex2f(16.35, 22);
	glVertex2f(16.12, 28.63);
	glVertex2f(19.15, 30.8);
	glVertex2f(17.9, 22.88);
	glEnd();
	
		glBegin(GL_POLYGON);
	glColor3f(0.984313725490196, 0.698039215686274, 0.431372549019608);
	glVertex2f(-3.93, 3.08); //start
	glVertex2f(-4.47, 4);
	glVertex2f(-4.96, 4.84);
	glVertex2f(-5.51, 6.15);
	glVertex2f(-6.54, 9.3);
	glVertex2f(-6.9, 11.52);
	glVertex2f(-7.29, 13.8);
	glVertex2f(-7.42, 16.36);
	glVertex2f(-7.56, 21.15);
	glVertex2f(-7.56, 23.08);
	glVertex2f(-6.71, 23.75);
	glVertex2f(-5.63, 23.96);
	glVertex2f(-5.2, 24.18);
	glVertex2f(-1.75, 24.75);
	glVertex2f(0.37, 25.2);
	glVertex2f(5.8, 25.2);
	glVertex2f(9.78, 24.63); 
	glVertex2f(11.8, 24.32);
	glVertex2f(13.03, 23.79);
	glVertex2f(15.63, 22.73);
	glVertex2f(16.17, 22.25);
	glVertex2f(16.38, 21.05);//end
	glVertex2f(16.70, 21.95);
	glVertex2f(17.05, 19.69);
	glVertex2f(16.7, 16.66);
	glVertex2f(16.3, 14.3);
	glVertex2f(15.85, 12.69);
	glVertex2f(15.08, 9.97);
	glVertex2f(13.84, 6.76);
	glVertex2f(12.7, 4.7);
	glVertex2f(11.83, 3.5);
	glVertex2f(10.24, 2.02);
	glVertex2f(8.23, 0.71);
	glVertex2f(6.19,0.1); 
	glVertex2f(4.67, 0);
	glVertex2f(1.95, 0);
	glVertex2f(.56, .22);
	glVertex2f(.38, .48);
	glVertex2f(1.36, 1.03);
	glVertex2f(2.83,2);
	glVertex2f(3.69, 2.65);
	glEnd();


	//eyes
	eye();

	glPushMatrix();
	glTranslatef(-12.49, 0, 0);
	eye();
	glPopMatrix();

	//mouse 

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = -180; i<0; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(3.98 + 5.59 * cos(rad), 12.32 + 5.84 * sin(rad));
	}
	glEnd();

	//nose
	glBegin(GL_POLYGON);
	glColor3f(0.952941176470588, 0.552941176470588, 0.305882352941176);
	glVertex2f(2.02, 17.87); //start
	glVertex2f(1.92, 17.2);
	glVertex2f(1.92, 16.78);
	glVertex2f(1.95, 16.39);
	glVertex2f(2.13, 16.03);
	glVertex2f(2.31, 15.76);
	glVertex2f(2.56, 15.54);
	glVertex2f(2.8, 15.32);
	glVertex2f(3.3, 15.19);
	glVertex2f(3.3, 13.64);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.952941176470588, 0.552941176470588, 0.305882352941176);
	glVertex2f(3.3, 13.64);
	glVertex2f(3.3, 15.19);
	glVertex2f(4.11, 15.15);
	glVertex2f(4.78	, 15.26);
	glVertex2f(5.16, 15.33);
	glVertex2f(5.55, 15.47);
	glVertex2f(6.08, 15.64);
	glVertex2f(6.4, 16.07);
	glVertex2f(6.61, 16.25);
	glVertex2f(6.68, 15.78);
	glVertex2f(6.51, 15.29);
	glVertex2f(6.33, 14.76);
	glVertex2f(5.97, 14.24);
	glVertex2f(5.59, 13.99);
	glVertex2f(4.95, 13.64);//end
	glVertex2f(2.8, 13.57);

	glVertex2f(2.38, 13.7);
	glVertex2f(2.02,13.94);
	glVertex2f(1.64, 14.3);
	glVertex2f(1.39, 14.48);
	glVertex2f(1.25, 14.84);
	glVertex2f(1.18, 15.29);
	glVertex2f(1.25, 15.68);
	glVertex2f(1.35, 16);
	glVertex2f(1.53, 16.67);
	glVertex2f(1.67,17.27);
	glVertex2f(1.81, 17.65);
	glVertex2f(1.95, 17.87);
	glEnd();


	// ******************* hire **********************//

	glBegin(GL_POLYGON);
	glColor3f(0.615686274509804, 0.305882352941176, 0.0352941176470588);
	glVertex2f(18.33, 43.1);//start second
	glVertex2f(17.72, 42.7);
	glVertex2f(17.51, 42.31);
	glVertex2f(17.37, 42.18);
	glVertex2f(17.12, 41.72);
	glVertex2f(16.88, 41.3);
	glVertex2f(16.6, 40.84);
	glVertex2f(16.17, 40.38);
	glVertex2f(15.89, 40.23);
	glVertex2f(15.75, 40.09);
	glVertex2f(15.68, 39.95);
	glVertex2f(15.72, 39.85);
	glVertex2f(1.88, 33.96);
	glVertex2f(5.23, 33.96);
	glVertex2f(9.89, 33.64);
	glVertex2f(13.77, 33.17);
	glVertex2f(17.02, 32.62);
	glVertex2f(18.82, 32.29);
	glVertex2f(19.6, 32.13); //end
	glVertex2f(9.47, 40.8);//end
	glVertex2f(9.64, 41.23);
	glVertex2f(10, 41.76);
	glVertex2f(10.68, 42.24);
	glVertex2f(11.17, 42.35);
	glVertex2f(11.72, 42.77);
	glVertex2f(12.57, 43.79);
	glVertex2f(12.99, 44.4);
	glVertex2f(13.31, 45.49);
	glVertex2f(13.49, 46.15);
	glVertex2f(13.46, 47.18);
	glVertex2f(13.49, 48.21);
	glVertex2f(13.38, 48.7);
	glVertex2f(13.25, 50.84);
	glVertex2f(12.82, 50.04);
	glVertex2f(12.33, 50.75);
	glVertex2f(12.12, 50.85);
	glVertex2f(15.36, 50.85);
	glVertex2f(15.36, 39.9);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.615686274509804, 0.305882352941176, 0.0352941176470588);
	glVertex2f(15.36, 39.9);
	glVertex2f(15.36, 50.85);
	glVertex2f(17.37, 50.83);
	glVertex2f(18.43, 50.99);
	glVertex2f(19.39, 51.6); //end
	glVertex2f(19.8, 51.94);//end
	glVertex2f(19.94, 51.94);
	glVertex2f(20.3, 50.89);
	glVertex2f(20.4, 47.97);
	glVertex2f(20.3, 46.4);
	glVertex2f(20.16, 45.7);
	glVertex2f(19.88, 45.03);
	glVertex2f(19.45, 44.18);
	glVertex2f(19.04, 43.75);
	glVertex2f(18.71, 43.48);
	glVertex2f(18.5, 43.3);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0.352941176470588, 0.180392156862745, 0.0666666666666667);
	glVertex2f(19.77, 38.48);//end
	glVertex2f(20.37, 39.32);
	glVertex2f(20.33, 41.69);
	glVertex2f(20.16, 42.14);
	glVertex2f(19.92, 42.5);
	glVertex2f(19.73, 42.71);
	glVertex2f(19.49, 42.96);
	glVertex2f(19.2, 43.13);
	glVertex2f(18.71, 43.13);
	glVertex2f(18.33, 43.1);//start second
	glVertex2f(17.72, 42.7);
	glVertex2f(17.51, 42.31);
	glVertex2f(17.37, 42.18);
	glVertex2f(17.12, 41.72);
	glVertex2f(16.88, 41.3);
	glVertex2f(16.6, 40.84);
	glVertex2f(16.17, 40.38);
	glVertex2f(15.89, 40.23);
	glVertex2f(15.75, 40.09);
	glVertex2f(15.68, 39.95);
	glVertex2f(15.72, 39.85);
	glVertex2f(1.88, 33.96);
	glVertex2f(5.23, 33.96);
	glVertex2f(9.89, 33.64);
	glVertex2f(13.77, 33.17);
	glVertex2f(17.02, 32.62);
	glVertex2f(18.82, 32.29);
	glVertex2f(19.6, 32.13); //end
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.454901960784314, 0.223529411764706, 0.00392156862745098);
	glVertex2f(9.47, 40.8);//end
	glVertex2f(9.64, 41.23);
	glVertex2f(10, 41.76);
	glVertex2f(10.68, 42.24);
	glVertex2f(11.17, 42.35);
	glVertex2f(11.72, 42.77);
	glVertex2f(12.57, 43.79);
	glVertex2f(12.99, 44.4);
	glVertex2f(13.31, 45.49);
	glVertex2f(13.49, 46.15);
	glVertex2f(13.46, 47.18);
	glVertex2f(13.49, 48.21);
	glVertex2f(13.38, 48.7);
	glVertex2f(13.25, 50.84);
	glVertex2f(12.82, 50.04);
	glVertex2f(12.33, 50.75);
	glVertex2f(12.12, 50.85);
	glVertex2f(11.81, 50.85);//end
	glVertex2f(11.13, 50.67);
	glVertex2f(10.31, 50.22);
	glVertex2f(10.31, 50);
	glVertex2f(9.85, 50);
	glVertex2f(9.86, 50.25);
	glVertex2f(8.44, 50.92);
	glVertex2f(7, 51.42);
	glVertex2f(5.09, 51.45);
	glVertex2f(4.03, 50.96);
	glVertex2f(2.8, 50.15);
	glVertex2f(2.74, 50.04);
	glVertex2f(1.75, 50.07);
	glVertex2f(0.97, 50.43);
	glVertex2f(-2.67, 50.5);
	glVertex2f(-3.76, 50);
	glVertex2f(-4.5, 49.47);
	glVertex2f(-4.93, 48.95);
	glVertex2f(-5.17, 48.45);
	glVertex2f(-5.27, 48.14);
	glVertex2f(-5.3, 47.79);
	glVertex2f(-6.48, 47.8);
	glVertex2f(-7.68, 47);
	glVertex2f(-8.14, 46.55);
	glVertex2f(-8.44, 46.23); 
	glVertex2f(-8.73, 45.92);
	glVertex2f(-9.27, 44.89);
	glVertex2f(-9.57, 44.15); /*/*/
	glVertex2f(-9.79, 43.62);
	glVertex2f(-8.97, 42.95);
	glVertex2f(-8.45, 42.66);
	glVertex2f(-8, 42.29);
	glVertex2f(-7.68, 42.17);
	glVertex2f(-7.25, 42.17);
	glVertex2f(-7.04, 42.17);
	glVertex2f(-6.86, 42);
	glVertex2f(-6.58, 41.85);
	glVertex2f(-6.06, 41.72);
	glVertex2f(-5.66, 41.75);
	glVertex2f(-5.09, 41.08);
	glVertex2f(-4.79, 40.51);//end
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.454901960784314, 0.223529411764706, 0.00392156862745098);
	glVertex2f(9.47, 40.8);//end
	glVertex2f(9.64, 41.23);
	glVertex2f(10, 41.76);
	glVertex2f(10.68, 42.24);
	glVertex2f(11.17, 42.35);
	glVertex2f(11.72, 42.77);
	glVertex2f(12.57, 43.79);
	glVertex2f(12.99, 44.4);
	glVertex2f(13.31, 45.49);
	glVertex2f(13.49, 46.15);
	glVertex2f(13.46, 47.18);
	glVertex2f(13.49, 48.21);
	glVertex2f(13.38, 48.7);
	glVertex2f(13.25, 50.84);
	glVertex2f(12.82, 50.04);
	glVertex2f(12.33, 50.75);
	glVertex2f(12.12, 50.85);
	glVertex2f(11.81, 50.85);//end
	glVertex2f(11.13, 50.67);
	glVertex2f(10.31, 50.22);
	glVertex2f(10.31, 50);
	glVertex2f(9.85, 50);
	glVertex2f(9.86, 50.25);
	glVertex2f(8.44, 50.92);
	glVertex2f(7, 51.42);
	glVertex2f(5.09, 51.45);
	glVertex2f(4.03, 50.96);
	glVertex2f(2.8, 50.15);
	glVertex2f(2.74, 50.04);
	glVertex2f(1.75, 50.07);
	glVertex2f(0.97, 50.43);
	glVertex2f(-2.67, 50.5);
	glVertex2f(-3.76, 50);
	glVertex2f(-4.5, 49.47);
	glVertex2f(-4.93, 48.95);
	glVertex2f(-5.17, 48.45);
	glVertex2f(-5.27, 48.14);
	glVertex2f(-5.3, 47.79);
	glVertex2f(-6.48, 47.8);
	glVertex2f(-7.68, 47);
	glVertex2f(-8.14, 46.55);
	glVertex2f(-8.44, 46.23);//start
	glVertex2f(-8.73, 45.92);
	glVertex2f(-9.27, 44.89);
	glVertex2f(-9.57, 44.15); /*/*/
	glVertex2f(-9.79, 43.62);
	glVertex2f(-8.97, 42.95);
	glVertex2f(-8.45, 42.66);
	glVertex2f(-8, 42.29);
	glVertex2f(-7.68, 42.17);
	glVertex2f(-7.25, 42.17);
	glVertex2f(-7.04, 42.17);
	glVertex2f(-6.86, 42);
	glVertex2f(-6.58, 41.85);
	glVertex2f(-6.06, 41.72);
	glVertex2f(-5.66, 41.75);
	glVertex2f(-5.09, 41.08);
	glVertex2f(-4.79, 40.51);//end
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.352941176470588, 0.180392156862745, 0.0666666666666667);
	glVertex2f(-8.44, 46.23);//start
	glVertex2f(-8.73, 45.92);
	glVertex2f(-9.27, 44.89);
	glVertex2f(-9.57, 44.15); /*/*/
	glVertex2f(-9.79, 43.62);
	glVertex2f(-8.97, 42.95);
	glVertex2f(-8.45, 42.66);
	glVertex2f(-8, 42.29);
	glVertex2f(-7.68, 42.17);
	glVertex2f(-7.25, 42.17);
	glVertex2f(-7.04, 42.17);
	glVertex2f(-6.86, 42);
	glVertex2f(-6.58, 41.85);
	glVertex2f(-6.06, 41.72);
	glVertex2f(-5.66, 41.75);
	glVertex2f(-5.09, 41.08);
	glVertex2f(-4.79, 40.51);//end
	glVertex2f(-4.54, 40.31);//end
	glVertex2f(-11.94, 38.32);
	glVertex2f(-12.48, 38.58);
	glVertex2f(-12.93, 39.15);
	glVertex2f(-13.14, 39.91);
	glVertex2f(-13.25, 40.56);
	glVertex2f(-13.15, 41.05);
	glVertex2f(-12.93, 41.65);
	glVertex2f(-12.54, 41.97);
	glVertex2f(-12.19,42.28);
	glVertex2f(-11.87, 42.45);
	glVertex2f(-11.56, 42.53);
	glVertex2f(-11.59, 42.88);
	glVertex2f(-11.59,43.6);
	glVertex2f(-11.45, 44.23);
	glVertex2f(-11.06, 45.07);
	glVertex2f(-10.5, 45.62);
	glVertex2f(-10, 46.12);
	glVertex2f(-9.54, 46.34);
	glVertex2f(-8.88, 46.41);
	glEnd();


	// cap

	glBegin(GL_POLYGON);
	glColor3f(0.858823529411765, 0.0980392156862745, 0.129411764705882);
	glVertex2f(19.8, 32.01);//end
	glVertex2f(19.49, 31.27);
	glVertex2f(18.5, 30.17);
	glVertex2f(17.05, 29.08);
	glVertex2f(16.17, 28.63);
	glVertex2f(14.19, 27.75);
	glVertex2f(10.56, 26.65);
	glVertex2f(7.53, 26.22);
	glVertex2f(3.4, 25.92);
	glVertex2f(1.15, 26.12);
	glVertex2f(-.13, 26.36);
	glVertex2f(-4,27);
	glVertex2f(-6.85,28.13 );
	glVertex2f(-10.11, 30.07);
	glVertex2f(-11.77, 31.56);
	glVertex2f(-11.7, 32); //start under curve
	glVertex2f(-11.34, 32.02);
	glVertex2f(-9.83, 32.48);
	glVertex2f(-8, 32.83);
	glVertex2f(-5.7, 33.25);
	glVertex2f(-2.3, 33.71);
	glVertex2f(1.88, 33.96);
	glVertex2f(5.23, 33.96);
	glVertex2f(9.89, 33.64);
	glVertex2f(13.77, 33.17);
	glVertex2f(17.02, 32.62);
	glVertex2f(18.82, 32.29);
	glVertex2f(19.6, 32.13); //end
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.129411764705882, 0.207843137254902);
	glVertex2f(-11.7, 32); //start under curve
	glVertex2f(-11.34, 32.02);
	glVertex2f(-9.83, 32.48);
	glVertex2f(-8, 32.83);
	glVertex2f(-5.7, 33.25);
	glVertex2f(-2.3, 33.71);
	glVertex2f(1.88, 33.96);
	glVertex2f(5.23, 33.96);
	glVertex2f(9.89, 33.64);
	glVertex2f(13.77, 33.17);
	glVertex2f(17.02, 32.62);
	glVertex2f(18.82, 32.29);
	glVertex2f(19.6, 32.13); //end
	glVertex2f(19.96, 32.01);//end
	glVertex2f(19.75, 38.55);
	glVertex2f(18.6, 39.25);
	glVertex2f(17.8, 39.53);
	glVertex2f(17.03, 39.77);
	glVertex2f(15.65, 40);
	glVertex2f(13.12, 40.42);
	glVertex2f(11.05, 40.73);
	glVertex2f(8.37, 40.87);
	glVertex2f(5.3, 40.98);
	glVertex2f(1.67, 41.03);
	glVertex2f(-2.51, 40.79);
	glVertex2f(-5.81, 40.45);
	glVertex2f(-9.74, 39.25);
	glVertex2f(-11.77, 38.5);
	glEnd();





	// t-shirt logo

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(14.4 + 5.25* cos(rad), -23.6 + 4.2* sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.976470588235294, 0.733333333333333, 0.0627450980392157);
	glVertex2f(10.82, -22.46);//end
	glVertex2f(10.71, -23.03);
	glVertex2f(10.71, -23.68);
	glVertex2f(10.77, -24.3);
	glVertex2f(11.2, -24.75);
	glVertex2f(17.86, -24.75);
	glVertex2f(18.29, -24.26);
	glVertex2f(18.39, -23.75);
	glVertex2f(18.39, -23.24);
	glVertex2f(18.33, -22.64);
	glVertex2f(17.83, -21.93);
	glVertex2f(11.3, -21.93);
	glEnd();


	// ****************** Meal  ******************************************//
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-86.6, -41.6);
	glVertex2f(-18.1, -41.6);
	glVertex2f(-18.1, -47.1);
	glVertex2f(-86.6, -47.1);
	glEnd();


	//poteto
	
	glBegin(GL_QUADS);
	glColor3f(0.964705882352941, 0.752941176470588, 0.329411764705882);
	glVertex2f(-74.3, -15.5);
	glVertex2f(-71.8, -14.7);
	glVertex2f(-71.5, -18.8);
	glVertex2f(-73.7, -18.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.996078431372549, 0.866666666666667, 0.384313725490196);
	glVertex2f(-71.9, -12.6);
	glVertex2f(-69.4, -12.2);
	glVertex2f(-69.4, -20.1);
	glVertex2f(-71.6, -18.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.96078431372549, 0.752941176470588, 0.333333333333333);
	glVertex2f(-69.4, -12.2);
	glVertex2f(-69.4, -20.1);
	glVertex2f(-67.8, -20.9);
	glVertex2f(-67.7, -13);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1, 0.866666666666667, 0.384313725490196);
	glVertex2f(-66.5, -11.6);
	glVertex2f(-64, -11.9);
	glVertex2f(-65.4, -22.3);
	glVertex2f(-67.4, -22.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.972549019607843, 0.749019607843137, 0.329411764705882);
	glVertex2f(-64, -11.9);
	glVertex2f(-65.6, -22.7);
	glVertex2f(-64.8, -23);
	glVertex2f(-63.5, -13);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.964705882352941, 0.752941176470588, 0.329411764705882);
	glVertex2f(-62.6, -7.7);
	glVertex2f(-60.3, -8.4);
	glVertex2f(-64, -24.9);
	glVertex2f(-65.4, -24.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.913725490196078, 0.615686274509804, 0.274509803921569);
	glVertex2f(-60.5, -8.4);
	glVertex2f(-59.1, -9.8);
	glVertex2f(-59.5, -12.1);
	glVertex2f(-61, -11.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.866666666666667, 0.380392156862745);
	glVertex2f(-61, -11.4);
	glVertex2f(-58.6, -12.6);
	glVertex2f(-62.3, -24.8);
	glVertex2f(-64, -24.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.980392156862745, 0.745098039215686, 0.337254901960784);
	glVertex2f(-58.6, -12.6);
	glVertex2f(-57.6, -14.2);
	glVertex2f(-59.6, -19.5);
	glVertex2f(-60.8, -19.6);
	glEnd();



	// packet potetos


	glBegin(GL_QUADS);
	glColor3f(0.92156862745098, 0.105882352941176, 0.145098039215686);
	glVertex2f(-74, -41.8);
	glVertex2f(-76.4, -24.5);
	glVertex2f(-74.3, -24.5);
	glVertex2f(-72.8, -41.8);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-74.3, -24.5);
	glVertex2f(-72.8, -41.8);
	glVertex2f(-70.7, -41.8);
	glVertex2f(-72.3, -24.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.92156862745098, 0.105882352941176, 0.145098039215686);
	glVertex2f(-70.7, -41.8);
	glVertex2f(-72.3, -24.5);
	glVertex2f(-69.4, -24.5);
	glVertex2f(-68.7, -41.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-69.4, -24.5);
	glVertex2f(-68.7, -41.8);
	glVertex2f(-66.6, -41.8);
	glVertex2f(-67.1, -24.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.92156862745098, 0.105882352941176, 0.145098039215686);
	glVertex2f(-66.6, -41.8);
	glVertex2f(-67.1, -24.5);
	glVertex2f(-64, -24.5);
	glVertex2f(-65, -41.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.823529411764706, 0.0941176470588235, 0.113725490196078);
	glVertex2f(-64, -24.5);
	glVertex2f(-65, -41.8);
	glVertex2f(-64.3, -41.8);
	glVertex2f(-62.8, -24.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.901960784313726, 0.815686274509804, 0.847058823529412);
	glVertex2f(-64.3, -41.8);
	glVertex2f(-62.8, -24.5);
	glVertex2f(-61.9, -24.5);
	glVertex2f(-63.4, -41.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.823529411764706, 0.0941176470588235, 0.113725490196078);
	glVertex2f(-61.9, -24.5);
	glVertex2f(-63.4, -41.8);
	glVertex2f(-62.3, -41.8);
	glVertex2f(-60.8, -24.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.901960784313726, 0.815686274509804, 0.847058823529412);
	glVertex2f(-62.3, -41.8);
	glVertex2f(-60.8, -24.5);
	glVertex2f(-59.9, -24.5);
	glVertex2f(-61.5, -41.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.823529411764706, 0.0941176470588235, 0.113725490196078);
	glVertex2f(-59.9, -24.5);
	glVertex2f(-61.5, -41.8);
	glVertex2f(-60.8, -41.8);
	glVertex2f(-59, -24.5);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-76.4, -25);
	glVertex2f(-77.1, -23.1);
	glVertex2f(-75, -18.8);
	glVertex2f(-71.6, -18.8);
	glVertex2f(-65.7, -22.2);
	glVertex2f(-64, -25);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.819607843137255, 0.0941176470588235, 0.125490196078431);
	glVertex2f(-64, -25);
	glVertex2f(-62.3, -21.9);
	glVertex2f(-59.6, -18.5);
	glVertex2f(-57.4, -18.5);
	glVertex2f(-57.4, -22.3);
	glVertex2f(-59, -25);
	glEnd();

	glPushMatrix();
	glTranslatef(-8, -101, 0);
	//glRotatef(fr2, 0, 0, -0.5);
	glScalef(1.2, 1.2, 0);
	juise();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(39, -84, 0);
	//glRotatef(fr1, 0, 0, -0.5);
	glScalef(1.15,1.15, 0);
	burger();
	glPopMatrix();

// Computer


	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex2f(36, -20.9);
	glVertex2f(37.6, -23);
	glVertex2f(83.3, -23);
	glVertex2f(81.3, -20.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.764705882352941, 0.874509803921569, 0.929411764705882);
	glVertex2f(83.3, -23);
	glVertex2f(37.6, -23);
	glVertex2f(37.6, -61.7);
	glVertex2f(83.3, -61.7);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.882352941176471, 0.96078431372549, 0.996078431372549);
	glVertex2f(37.6, -61.7);
	glVertex2f(36, -61.1);
	glVertex2f(36, -20.9);
	glVertex2f(37.6, -23);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.670588235294118, 0.811764705882353, 0.874509803921569);
	glVertex2f(58.1, -41.6);
	glVertex2f(59.4, -50.1);
	glVertex2f(68.8, -50.1);
	glVertex2f(67.3, -41.6);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(58.1, -41.6);
	glVertex2f(59.4, -50.1);
	glVertex2f(58.1, -50.1);
	glEnd();


	//first layer
	glBegin(GL_QUADS);
	glColor3f(0.650980392156863, 0.764705882352941, 0.827450980392157);
	glVertex2f(52.4, -69.9);
	glVertex2f(53.6, -69.9);
	glVertex2f(53.6, -54.5);
	glVertex2f(52.4, -54.5);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.650980392156863, 0.764705882352941, 0.819607843137255);
	glVertex2f(56.2, -50.1);
	glVertex2f(57, -52.5);
	glVertex2f(85.4, -52.5);
	glVertex2f(83.5, -50.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647058823529412, 0.76078431372549, 0.815686274509804);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(57.7 +  4.8* cos(rad), -54.1 + 4 * sin(rad));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.647058823529412, 0.76078431372549, 0.815686274509804);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(83.3 + 5.42 * cos(rad), -58.05 + 7.95 * sin(rad));
	}
	glEnd();

	//second layer

	glBegin(GL_POLYGON);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(57.8 + 4 * cos(rad), -56.6 + 4.1 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(84.48 + 4.52 * cos(rad), -58.63 + 6.18 * sin(rad));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(84.5,-52.4);
	glVertex2f(89, -69.9);
	glVertex2f(53.6, -69.9);
	glVertex2f(57.8, -52.4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(53.6, -56.6);
	glVertex2f(58.05, -56.6);
	glVertex2f(58.05, -69.9);
	glVertex2f(53.6, -69.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.537254901960784, 0.647058823529412, 0.701960784313725);
	glVertex2f(89, -56.6);
	glVertex2f(84.5, -56.6);
	glVertex2f(84.5, -69.9);
	glVertex2f(89, -69.9);
	glEnd();

	//third layer 

	glBegin(GL_POLYGON);
	glColor3f(0.325490196078431, 0.43921568627451, 0.501960784313725);
	glVertex2f(58.1,-56.9);
	glVertex2f(59, -55.9);
	glVertex2f(80.95, -55.9);
	glVertex2f(82.1, -56.9);
	glVertex2f(82.1, -65.1);
	glVertex2f(80.95, -66.6);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.325490196078431, 0.43921568627451, 0.501960784313725);
	glVertex2f(80.95, -66.6);
	glVertex2f(59, -66.6);
	glVertex2f(58.1,-65.1);
	glVertex2f(58.1, -56.9);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.352941176470588, 0.47843137254902, 0.537254901960784);
	glVertex2f(58.8, -59.1);
	glVertex2f(59.6, -58.1);
	glVertex2f(81.5, -58.1);
	glVertex2f(82.1, -58.4);
	glVertex2f(82.1, -65.1);
	glVertex2f(80.95, -66.6);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.352941176470588, 0.47843137254902, 0.537254901960784);
	glVertex2f(80.95, -66.6);
	glVertex2f(59.62, -66.6);
	glVertex2f(58.8, -65.6);
	glVertex2f(58.8, -59.1);
	glEnd();

	//***********************************************************************//


	glutSwapBuffers();

}


void burger()
{

	glBegin(GL_POLYGON);
	glColor3f(1, 0.811764705882353, 0.309803921568627);
	for (int i = -23; i<202; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-74.8 + -10.2 * cos(rad), 48.1 + 6.1 * sin(rad));
	}
	glEnd();

	// 3eesh
	glBegin(GL_POLYGON);
	glColor3f(0.992156862745098, 0.717647058823529, 0.282352941176471);
	for (int i = 20; i<160; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-74.8 + -10.2 * cos(rad), 48.1 + 6.1 * sin(rad));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-74.8 + .5 * cos(rad), 52 + 1 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-78 + .7 * cos(rad), 52 + .7 * sin(rad));
	}
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-82 + .5 * cos(rad), 51.5 + .7 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-70 + .5 * cos(rad), 51.5 + .7 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-67 + .3 * cos(rad), 51.1 + .5 * sin(rad));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-72 + .8 * cos(rad), 52 + .8 * sin(rad));
	}
	glEnd();


	/*******************************************/


	glBegin(GL_POLYGON);
	glColor3f(1, 0.811764705882353, 0.309803921568627);
	for (int i = -23; i<202; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-74.8 + -10.2 * cos(rad), 39 + 6.1 * sin(rad));
	}
	glEnd();

	// red 
	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.309803921568627, 0.164705882352941);
	glVertex2f(-84.8, 43.7);
	glVertex2f(-85, 43);
	glVertex2f(-84.8, 42.5);
	glVertex2f(-83.4, 41.3);
	glVertex2f(-83.1, 41.3);
	glVertex2f(-83.1, 43.7);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.309803921568627, 0.164705882352941);
	glVertex2f(-83.1, 43.7);
	glVertex2f(-83.1, 41.3);
	glVertex2f(-82.3, 40.8);
	glVertex2f(-68.4, 40.8);
	glVertex2f(-67.6, 41.1);
	glVertex2f(-67.6, 44.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.309803921568627, 0.164705882352941);
	glVertex2f(-67.6, 44.1);
	glVertex2f(-67.6, 41.1);
	glVertex2f(-67.3, 41.3);
	glVertex2f(-66.3, 41.3);
	glVertex2f(-65.8, 41.7);
	glVertex2f(-65.8, 44.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.309803921568627, 0.164705882352941);
	glVertex2f(-65.8, 44.1);
	glVertex2f(-65.8, 41.7);
	glVertex2f(-65.3, 41.7);
	glVertex2f(-66.3, 41.3);
	glVertex2f(-64.7, 42.3);
	glVertex2f(-64.7, 44.1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.713725490196078, 0.309803921568627, 0.164705882352941);
	glVertex2f(-64.7, 44.1);
	glVertex2f(-64.7, 42.3);
	glVertex2f(-64.6, 42.8);
	glVertex2f(-64.6, 43.6);
	glVertex2f(-64.7, 44);
	glVertex2f(-64.7, 44.1);
	glEnd();
	// green 
	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-64.7, 46.4);
	glVertex2f(-63.1, 45.6);
	glVertex2f(-63.1, 44.9);
	glVertex2f(-64.7, 44.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-64.7, 46.4);
	glVertex2f(-84.5, 45.7);
	glVertex2f(-84.5, 43.6);
	glVertex2f(-64.7, 44.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-84.5, 45.7);
	glVertex2f(-85.3, 45.1);
	glVertex2f(-85.5, 44.8);
	glVertex2f(-85.5, 44.2);
	glVertex2f(-84.9, 43.7);
	glVertex2f(-84.5, 43.6);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-80.5, 44);
	glVertex2f(-78.8, 43.2);
	glVertex2f(-77.9, 42.8);
	glVertex2f(-77.6, 44.2);
	glVertex2f(-77.1, 42.2);
	glVertex2f(-77.1, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-77.1, 44);
	glVertex2f(-77.1, 42.2);
	glVertex2f(-76.5, 42.2);
	glVertex2f(-76.5, 42);
	glVertex2f(-74.3, 42);
	glVertex2f(-74.3, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-74.3, 44);
	glVertex2f(-74.3, 42);
	glVertex2f(-73.6, 42.2);
	glVertex2f(-72.5, 42.2);
	glVertex2f(-71.8, 42.8);
	glVertex2f(-71.8, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-71.8, 44);
	glVertex2f(-71.8, 42.8);
	glVertex2f(-71.4, 42.8);
	glVertex2f(-70.5, 43.2);
	glVertex2f(-69.8, 43.2);
	glVertex2f(-69.8, 44);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.729411764705882, 0.796078431372549, 0.192156862745098);
	glVertex2f(-69.8, 44);
	glVertex2f(-69.8, 43.2);
	glVertex2f(-69.1, 44);
	glEnd();
}

void juise()
{

	glBegin(GL_POLYGON);
	glColor3f(0.83921568627451, 0.882352941176471, 0.905882352941176);
	for (int i = 0; i<180.1; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(-18.4 + 7.4 * cos(rad), 72.4 + 4.9 * sin(rad));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.894117647058824, 0.96078431372549, 0.992156862745098);
	glVertex2f(-10.1, 73.6);
	glVertex2f(-26.6, 73.6);
	glVertex2f(-26.2, 70.9);
	glVertex2f(-10.7, 70.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.83921568627451, 0.882352941176471, 0.905882352941176);
	glVertex2f(-11.7, 70.9);
	glVertex2f(-25.2, 70.9);
	glVertex2f(-23.5, 49.1);
	glVertex2f(-14, 49.1);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.972549019607843, 0.682352941176471, 0.733333333333333);
	glVertex2f(-13.7, 67.8);
	glVertex2f(-23.5, 67.8);
	glVertex2f(-21.9, 51.5);
	glVertex2f(-15.7, 51.5);
	glEnd();

	// shalemo
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-10.8, 84.9);
	glVertex2f(-10.5, 83.5);
	glVertex2f(-15.8, 83);
	glVertex2f(-16.5, 84.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-15.8, 83);
	glVertex2f(-16.5, 84.5);
	glVertex2f(-18.4, 81.4);
	glVertex2f(-17.15, 81.05);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-17.15, 81.05);
	glVertex2f(-18.4, 81.4);
	glVertex2f(-18.6, 80.6);
	glVertex2f(-17.2, 80.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.870588235294118, 0.956862745098039);
	glVertex2f(-18.6, 80.6);
	glVertex2f(-17.2, 80.6);
	glVertex2f(-17.6, 77.2);
	glVertex2f(-19, 77.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.945098039215686, 0.96078431372549, 0.984313725490196);
	glVertex2f(-17.6, 77.2);
	glVertex2f(-19, 77.2);
	glVertex2f(-19.4, 73.6);
	glVertex2f(-18.2, 73.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.925490196078431, 0.949019607843137, 0.972549019607843);
	glVertex2f(-20.1, 70.9);
	glVertex2f(-18.5, 70.9);
	glVertex2f(-18.9, 67.9);
	glVertex2f(-20.4, 67.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.976470588235294, 0.780392156862745, 0.792156862745098);
	glVertex2f(-20.4, 67.9);
	glVertex2f(-18.9, 67.9);
	glVertex2f(-20.2, 59);
	glVertex2f(-21.7, 59.2);
	glEnd();
}
void ear()
{
	glBegin(GL_POLYGON);
	glColor3f(0.968627450980392, 0.568627450980392, 0.325490196078431);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(17.33 + 3.67 * cos(rad), 19.94 + 6.47 * sin(rad));
	}
	glEnd();
}
void eye()
{
	glBegin(GL_POLYGON);
	glColor3f(0.509803921568627, 0.298039215686275, 0.156862745098039);
	for (int i = 0; i<360; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(10.33 + 1.68 * cos(rad), 21.63 + 2.63 * sin(rad));
	}
	glEnd();
}