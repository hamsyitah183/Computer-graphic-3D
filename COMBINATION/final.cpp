#define GL_SILENCE_DEPRECATION

#include <windows.h>
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>

GLboolean redFlag = true, fanSwitch = false;
double windowHeight = 800, windowWidth = 600;
double eyeX = -1.0, eyeY = 2.0, eyeZ = 14.0, refX = 5.0, refY = 0, refZ = 0;
//double theta = 180.0,  z = 7.97888, a = 2;
const int slices = 20;
const float PI = 3.14159265358979323846;
float m1x1, m1x2, m1x3;

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700
#define FPS 30
#define PI 3.141592653
int dx = 10;//velocity
int dy = 15;
int x = 30;
int y = 50;
float x_position = 0.0;
float x_position2 = 0.0;
int winWidth = 700, winHeight = 700, counter = 0;
time_t t;

static GLfloat v_cube[8][3] =
{
	{0.0, 0.0, 0.0}, //0
	{0.0, 0.0, 3.0}, //1
	{3.0, 0.0, 3.0}, //2
	{3.0, 0.0, 0.0}, //3
	{0.0, 3.0, 0.0}, //4
	{0.0, 3.0, 3.0}, //5
	{3.0, 3.0, 3.0}, //6
	{3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
	{0, 1, 2, 3}, //bottom
	{4, 5, 6, 7}, //top
	{5, 1, 2, 6}, //front
	{0, 4, 7, 3}, // back is clockwise
	{2, 3, 7, 6}, //right
	{1, 5, 4, 0}  //left is clockwise
};


static GLfloat colors[6][3] =
{
	{0.4, 0.1, 0.0}, //bottom
	{0.6, 0.0, 0.7}, //top
	{0.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{0.8, 0.0, 0.0},
	{0.3, 0.6, 0.7}
};

void drawCube()
{
	glBegin(GL_QUADS);
	for (GLint i = 0; i < 6; i++)
	{
		glVertex3fv(&v_cube[quadIndices[i][0]][0]);
		glVertex3fv(&v_cube[quadIndices[i][1]][0]);
		glVertex3fv(&v_cube[quadIndices[i][2]][0]);
		glVertex3fv(&v_cube[quadIndices[i][3]][0]);
	}
	glEnd();
}

static GLfloat v_pyramid[5][3] =
{
	{0.0, 0.0, 0.0},
	{0.0, 0.0, 2.0},
	{2.0, 0.0, 2.0},
	{2.0, 0.0, 0.0},
	{1.0, 4.0, 1.0}
};

static GLubyte p_Indices[4][3] =
{
	{4, 1, 2},
	{4, 2, 3},
	{4, 3, 0},
	{4, 0, 1}
};

static GLubyte PquadIndices[1][4] =
{
	{0, 3, 2, 1}
};

void drawpyramid()
{
	glBegin(GL_TRIANGLES);
	for (GLint i = 0; i < 4; i++)
	{
		glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
		glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
		glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (GLint i = 0; i < 1; i++)
	{
		glVertex3fv(&v_pyramid[PquadIndices[i][0]][0]);
		glVertex3fv(&v_pyramid[PquadIndices[i][1]][0]);
		glVertex3fv(&v_pyramid[PquadIndices[i][2]][0]);
		glVertex3fv(&v_pyramid[PquadIndices[i][3]][0]);
	}
	glEnd();

}

void polygon()
{
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(6, 0);
	glVertex2f(5.8, 1);
	glVertex2f(5.2, 2);
	glVertex2f(5, 2.2);
	glVertex2f(4, 2.8);
	glVertex2f(3, 3);
	glVertex2f(2, 2.8);
	glVertex2f(1, 2.2);
	glVertex2f(0.8, 2);
	glVertex2f(0.2, 1);
	//glVertex2f(0,0);

	glEnd();
}

void polygonLine()
{
	glBegin(GL_LINE_STRIP);
	//glVertex2f(0,0);
	glVertex2f(6, 0);
	glVertex2f(5.8, 1);
	glVertex2f(5.2, 2);
	glVertex2f(5, 2.2);
	glVertex2f(4, 2.8);
	glVertex2f(3, 3);
	glVertex2f(2, 2.8);
	glVertex2f(1, 2.2);
	glVertex2f(0.8, 2);
	glVertex2f(0.2, 1);
	glVertex2f(0, 0);

	glEnd();
}


//FUNCTION
//for scene 1
void bed()
{
	glNormal3f(0, 0, 1);
	//bed headboard
	glColor3f(0.627, 0.322, 0.176);
	glPushMatrix();
	glScalef(0.1, 0.5, 0.9);
	glTranslatef(-15, -0.5, 6);
	drawCube();
	glPopMatrix();

	//bed body
	glColor3f(0.0288, 0.0288, 0.32);
	glPushMatrix();
	glScalef(1, 0.2, 0.9); //1, 0.2, 0.9
	glTranslatef(-1.2, -0.5, 6.2);
	drawCube();
	glPopMatrix();

	//pillow right far
	glColor3f(0.9702, 0.98, 0.9735);
	glPushMatrix();
	glTranslatef(-1.0, 0.5, 6.5);
	glRotatef(20, 0, 0, 1);
	glScalef(0.1, 0.15, 0.28);
	drawCube();
	glPopMatrix();


	//blanket
	glColor3f(0.9702, 0.98, 0.9735);
	glPushMatrix();
	glTranslatef(-0.5, 0.45, 5.5);
	//glRotatef(22, 0,0,1);
	glScalef(0.5, 0.05, 0.95);
	drawCube();
	glPopMatrix();

	//blanket side left part
	glColor3f(0.9702, 0.98, 0.9735);
	glPushMatrix();
	glTranslatef(-0.5, -0.3, 8.15);
	//glRotatef(22, 0,0,1);
	glScalef(0.5, 0.25, 0.05);
	drawCube();
	glPopMatrix();

}
void bedRise()
{
	glNormal3f(0, 0, 1);
	//bed headboard
	glColor3f(0.627, 0.322, 0.176);
	glPushMatrix();
	glScalef(0.1, 0.5, 0.9);
	glTranslatef(-15, -0.5, 6);
	drawCube();
	glPopMatrix();

	//bed body
	glColor3f(0.0288, 0.0288, 0.32);
	glPushMatrix();
	glScalef(1, 0.2, 0.9); //1, 0.2, 0.9
	glTranslatef(-1.2, -0.5, 6.2);
	drawCube();
	glPopMatrix();

	//pillow right far
	glColor3f(0.9702, 0.98, 0.9735);
	glPushMatrix();
	glTranslatef(-1.0, 0.5, 6.5);
	glRotatef(20, 0, 0, 1);
	glScalef(0.1, 0.15, 0.28);
	drawCube();
	glPopMatrix();


	//blanket
	glColor3f(0.9702, 0.98, 0.9735);
	glPushMatrix();
	glTranslatef(-0.5, 1.0, 5.5);
	//glRotatef(22, 0,0,1);
	glScalef(0.5, 0.05, 0.95);
	drawCube();
	glPopMatrix();

	//blanket side left part
	glColor3f(0.9702, 0.98, 0.9735);
	glPushMatrix();
	glTranslatef(-0.5, -0.1, 8.15);
	//glRotatef(22, 0,0,1);
	glScalef(0.5, 0.40, 0.05);
	drawCube();
	glPopMatrix();

}

void lamp()
{

	glNormal3f(0, 0, 1);
	//lamp base
	//glColor3f(0.67, 0.35, 0.39);
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-1.3, 0.1, 5.1);
	glScalef(0.07, 0.01, 0.07);
	drawCube();
	glPopMatrix();

	//lamp stand
	//glColor3f(0.52, 0.36, 0.06);
	glColor3ub(108, 0, 0);
	glPushMatrix();
	glTranslatef(-1.1, 0.09, 5.2);
	glScalef(0.01, 0.4, 0.01);
	drawCube();
	glPopMatrix();

	//lamp shade
	//glColor3f(0.67, 0.35, 0.39);
	glNormal3f(0, 0, 1);
	glColor3ub(223, 157, 255);
	glPushMatrix();
	glTranslatef(-1.2, 1.20, 5.1);
	glScalef(0.08, 0.09, 0.08);
	drawCube();
	glPopMatrix();

}

void base()
{
	glNormal3f(0, 0, 1);
	// right wall
	//glColor3f(0.67, 0.67, 0.67);
	glColor3ub(10, 10, 10);
	glPushMatrix();
	glTranslatef(-1.5, -1, .5);
	glScalef(5, 2, 0.1);
	drawCube();
	glPopMatrix();


	// left wall
	glColor3f(0.70, 0.70, 0.70);
	glPushMatrix();
	glTranslatef(-4.5, -1, 0);
	glScalef(1, 2, 5);
	drawCube();
	glPopMatrix();

	// front wall
	glColor3f(0.60, 0.60, 0.60);
	glPushMatrix();
	glTranslatef(10.0, -1, 0);
	glScalef(1, 2, 5);
	drawCube();
	glPopMatrix();

	//ceiling
	glColor3f(0.65, 0.65, 0.65);
	glPushMatrix();
	//glScalef(5, 0.1, 7);
	glTranslatef(-2, 5.1, 0);
	glScalef(5, 0.1, 7);
	drawCube();
	glPopMatrix();

	// carpet
	glColor3f(0.51, 0.0204, 0.0204);
	glPushMatrix();
	//glScalef(5, 0.1, 7);
	glTranslatef(3, -0.2, 7);
	glScalef(1.3, 0.01, 1.7);
	drawCube();
	glPopMatrix();

	// floor
	glColor3f(0.27, 0.27, 0.27);
	glPushMatrix();
	glScalef(5, 0.1, 7);
	glTranslatef(-1, -5, 0); //-1,-5,.5
	//glScalef(5, 0.1, 7);
	drawCube();
	glPopMatrix();

}

void lightBase()
{
	glNormal3f(0, 0, 1);
	// right wall
	//glColor3f(0.67, 0.67, 0.67);
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glTranslatef(-1.5, -1, .5);
	glScalef(5, 2, 0.1);
	drawCube();
	glPopMatrix();


	// left wall
	glColor3f(0.90, 0.90, 0.90);
	glPushMatrix();
	glTranslatef(-4.5, -1, 0);
	glScalef(1, 2, 5);
	drawCube();
	glPopMatrix();

	// front wall
	glColor3f(0.80, 0.80, 0.80);
	glPushMatrix();
	glTranslatef(10.0, -1, 0);
	glScalef(1, 2, 5);
	drawCube();
	glPopMatrix();

	//ceiling
	glColor3f(0.85, 0.85, 0.85);
	glPushMatrix();
	//glScalef(5, 0.1, 7);
	glTranslatef(-2, 5.1, 0);
	glScalef(5, 0.1, 7);
	drawCube();
	glPopMatrix();

	// carpet
	glColor3f(0.51, 0.0204, 0.0204);
	glPushMatrix();
	//glScalef(5, 0.1, 7);
	glTranslatef(3, -0.2, 7);
	glScalef(1.3, 0.01, 1.7);
	drawCube();
	glPopMatrix();

	// floor
	glColor3f(0.27, 0.27, 0.27);
	glPushMatrix();
	glScalef(5, 0.1, 7);
	glTranslatef(-1, -5, 0); //-1,-5,.5
	//glScalef(5, 0.1, 7);
	drawCube();
	glPopMatrix();

}

void dressingtable()
{
	glNormal3f(0, 0, 1);
	//dressing table left body left front stripe
	glColor3f(0.2, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(5.9, 0, 5.2);
	//glRotatef(22, 0,0,1);
	glScalef(0.01, 0.5, 0.0001);
	drawCube();
	glPopMatrix();

	//dressing table left body left back stripe
	glColor3f(0.2, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(5.9, 0, 4.6);
	//glRotatef(22, 0,0,1);
	glScalef(0.01, 0.5, 0.0001);
	drawCube();
	glPopMatrix();

	//dressing table right body right front stripe
	glColor3f(0.2, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(7.6, 0, 5.2);
	//glRotatef(22, 0,0,1);
	glScalef(0.01, 0.5, 0.0001);
	drawCube();
	glPopMatrix();

	//dressing table right body right back stripe
	glColor3f(0.2, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(7.6, 0, 4.6);
	//glRotatef(22, 0,0,1);
	glScalef(0.01, 0.5, 0.0001);
	drawCube();
	glPopMatrix();


	//dressing table upper body
	glColor3f(0.545, 0.271, 0.075);
	glPushMatrix();
	glTranslatef(5.9, 1.2, 4.6);
	//glRotatef(22, 0,0,1);
	glScalef(0.57, 0.1, 0.2);
	drawCube();
	glPopMatrix();

	//dressing table upper body bottom stripe
	glColor3f(0.2, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(5.9, 1.2, 5.2);
	//glRotatef(22, 0,0,1);
	glScalef(0.57, 0.01, 0.0001);
	drawCube();
	glPopMatrix();

	//dressing table upper body upper stripe
	glColor3f(0.2, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(5.9, 1.5, 5.2);
	//glRotatef(22, 0,0,1);
	glScalef(0.57, 0.02, 0.0001);
	drawCube();
	glPopMatrix();


}
void pintu()
{
	glNormal3f(0, 0, 1);
	glColor3b(128, 0, 0);

	glPushMatrix();
	glTranslatef(-0.5, 0.45, 5.5);
	glBegin(GL_QUADS);
	glLineWidth(3);
	glVertex3f(3.0, 0.1, 0.0);
	glVertex3f(4.0, 0.1, 0.0);


	glVertex3f(4.0, 2.0, 0.0);


	glVertex3f(3.0, 2.0, 0.0);


	glVertex3f(3.0, 0.1, 0.0);



	glEnd();
	glPopMatrix();
}
void handTest2(float x1, float x2) {
	//2, 1.8, 2.1
	glNormal3f(0, 0, 1);

	glColor3ub(255, 128, 0);

	//right hand
	glBegin(GL_QUADS);
	glVertex3f(x1, 1.75, 5.6);
	glVertex3f(x1, 1.60, 5.6);

	//glVertex3f(2.8, 1.60, 5.6);
	glVertex3f(x1 - 0.25, 1.45, 5.6);

	//glVertex3f(2.55, 1.45, 5.6);
	glVertex3f(x1 - 0.25, 1.60, 5.6);

	//glVertex3f(2.55, 1.60, 5.6);
	glVertex3f(x1, 1.75, 5.6);

	glEnd();
	glPushMatrix();

	//left hand
	glPopMatrix();

	glBegin(GL_QUADS);
	glVertex3f(x2, 1.75, 5.6);
	glVertex3f(x2, 1.60, 5.6);


	glVertex3f(x2 - 0.25, 1.45, 5.65);

	glVertex3f(x2 - 0.25, 1.60, 5.65);



	glEnd();
	glPushMatrix();
	glPopMatrix();
}
//human
void handTest(float x2, float x3) {
	//right hand
	glBegin(GL_QUADS);
	glVertex3f(x2, 1.75, 5.6);
	glVertex3f(x2, 1.60, 5.6);
	glVertex3f(x2 - 0.25, 1.45, 5.6);
	glVertex3f(x2 - 0.25, 1.60, 5.6);

	glEnd();
	glPushMatrix();

	//left hand
	glPopMatrix();

	glBegin(GL_QUADS);
	glVertex3f(x3, 1.75, 5.6);
	glVertex3f(x3, 1.60, 5.6);
	glVertex3f(x3 + 0.25, 1.45, 5.6);
	glVertex3f(x3 + 0.25, 1.60, 5.6);


	glEnd();
	glPushMatrix();
	glPopMatrix();
}
void cuboid()
{
	// Draw horizontal cuboid here
	glPushMatrix();
	glTranslatef(-1.2, -0.5, 6.2);
	glBegin(GL_QUADS);
	// Front face
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back face
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	// Top face
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	// Bottom face
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// Left face
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// Right face
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glPopMatrix();
}
void roomorgTest(float x1, float x2, float x3) {
	glNormal3f(0, 0, 1);
	glColor3ub(255, 181, 114);
	glPushMatrix();
	glTranslatef(x1, 2, 5.5);
	glBegin(GL_LINES);
	glutSolidSphere(0.25, 50, 50);

	glPopMatrix();

	//body front
	glColor3ub(187, 187, 255);
	glNormal3f(0, 0, 1);
	glPushMatrix();
	//glTranslatef(3, 2, 6.5);
	glBegin(GL_QUADS);

	glVertex3f(x2, 1.75, 5.6);
	glVertex3f(x3, 1.75, 5.6);
	glVertex3f(x3, 0.7, 5.6);
	glVertex3f(x2, 0.7, 5.6);

	glEnd();
	glPopMatrix();

	//body back
	glColor3ub(128, 128, 255);
	glPushMatrix();
	//glTranslatef(3, 2, 6.5);
	glBegin(GL_QUADS);
	glVertex3f(x2, 0.7, 5.6);
	glVertex3f(x3, 0.7, 5.6);
	glVertex3f(x3 - 0.1, 0.5, 5.6);
	glVertex3f(x2 - 0.1, 0.5, 5.6);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//glTranslatef(3, 2, 6.5);
	glBegin(GL_QUADS);
	glVertex3f(x2, 0.5, 5.6);
	glVertex3f(x2 - 0.1, 0.5, 5.6);
	glVertex3f(x2 - 0.1, 1.70, 5.6);
	glVertex3f(x2, 1.75, 5.6);
	glEnd();
	glPopMatrix();
}
void roomlegTest(float x2, float x3) {

	glNormal3f(0, 0, 1);
	glColor3ub(255, 128, 0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(x2 + 0.05, .7, 5.6);
	glVertex3f(x2 + 0.15, .7, 5.6);

	glVertex3f(x2 + 0.15, .3, 5.6);
	glVertex3f(x2 + 0.05, .3, 5.6);

	glEnd();

	glPopMatrix();

	//right
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(x3 - 0.11, .7, 5.6);
	glVertex3f(x3 - 0.01, .7, 5.6);

	//glVertex3f(2.95, .7, 5.6);
	//glVertex3f(2.95, .3, 5.6);

	glVertex3f(x3 - 0.01, .3, 5.6);
	glVertex3f(x3 - 0.11, .3, 5.6);

	//glVertex3f(2.85, .3, 5.6);
	//glVertex3f(2.96, .7, 5.6);
	glEnd();

	glPopMatrix();
}
void org(float x1, float x2, float x3)
{
	//0.25, 0,2
	glNormal3f(0, 0, 1);
	glColor3ub(255, 181, 114);

	glPushMatrix();
	glTranslatef(-0.5, 0.85, 6.5);
	glBegin(GL_LINES);
	glutSolidSphere(x1, 50, 50);

	glPopMatrix();

	//body
	//front
	glColor3ub(187, 187, 255);
	glPushMatrix();
	glBegin(GL_QUADS);

	glVertex3f(x2, 0, 2);
	glVertex3f(x3, 0, 2);
	glVertex3f(x3 - 0.5, -.9, 2);
	glVertex3f(x2, -.9, 2);


	glEnd();
	glPopMatrix();



	glEnd();
	glPopMatrix();


}
void roomOrgHands(float x1, float x2)
{
	glNormal3f(0, 0, 1);
	glPushMatrix();

	//left roomOrgHands
	glColor3ub(50, 50, 60);
	glBegin(GL_QUADS);

	glVertex3f(x1 - 0.01, -0.2, 1);
	glVertex3f(x2, -0.2, 1);
	glVertex3f(x2, -1.1, 1);
	glVertex3f(x1 - 0.01, -1.1, 1);

	glEnd();
	glPopMatrix();

	glPushMatrix();

	//right roomOrgHands
	glColor3ub(50, 50, 60);
	glBegin(GL_QUADS);

	glVertex3f(x1 - 0.8, -0.2, 1);
	glVertex3f(x2 - 0.8, -0.2, 1);
	glVertex3f(x2 - 0.8, -1.1, 1);
	glVertex3f(x1 - 0.8, -1.1, 1);

	glEnd();
	glPopMatrix();

	////back square
	//glPushMatrix();
	//glBegin(GL_QUADS);
	//glColor3ub(255,255, 255);
	//glVertex3f(1, -0.8, 1);
	//glVertex3f(1.3, -0.8, 1);
	//glVertex3f(1.3 - 0.1, -0.8, 1);
	//glVertex3f(1 - 0.1, -0.8, 1);

	glEnd();
	glPopMatrix();

	//back square
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x1 - 0.1, -1.1, 0.8);
	glVertex3f(x1, -1.1, 0.8);
	glVertex3f(x1, 0.2, 0.8);
	glVertex3f(x1 - 0.1, 0.2, 0.8);
	glEnd();
	glPopMatrix();
}
void roomOrgLegs(float x1, float x2, float x3) {
	//glNormal3f(0, 0, 1);
	glPushMatrix();

	//left
	glColor3ub(50, 50, 60);
	glBegin(GL_QUADS);

	glVertex3f(x2 + 0.25, -1.25, 1.2);
	glVertex3f(x3, -1.25, 1.2);
	glVertex3f(x3, -2.6, 1.2);
	glVertex3f(x2 + 0.25, -2.6, 1.2);

	glEnd();
	glPopMatrix();

	//right
	glColor3ub(51, 51, 61);
	glBegin(GL_QUADS);

	glVertex3f(x2 - 0.1, -1.25, 1.2);
	glVertex3f(x3 - 0.35, -1.25, 1.2);
	glVertex3f(x3 - 0.35, -2.6, 1.2);
	glVertex3f(x2 - 0.1, -2.6, 1.2);

	glEnd();
	glPopMatrix();

	//side
	/*glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(60, 60, 70);
	glVertex3f(x2 - 0.2, -1.3, 2);
	glVertex3f(x3 - 0.55, -1.3, 2);
	glVertex3f(x3 - 0.55, -2.5, 2);
	glVertex3f(x2 - 0.2, -2.5, 2);*/

	glEnd();
	glPopMatrix();

	/*glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x2 , -3.5, 1);
	glVertex3f(x2, -3.3, 1);
	glVertex3f(x2, 3, 1);
	glVertex3f(x2 , 3, 1);
	glEnd();
	glPopMatrix();*/
}
void roomkiller(float x1, float x2, float x3)
{
	//0.25, 0,2
	glNormal3f(0, 0, 1);
	glColor3ub(255, 0, 0);

	glPushMatrix();
	glTranslatef(x1, 2.5, 6.5);
	glBegin(GL_LINES);
	glutSolidSphere(0.25, 50, 50);

	glPopMatrix();

	//body front
	glColor3ub(255, 0, 0);
	glNormal3f(0, 0, 1);
	glPushMatrix();
	//glTranslatef(3, 2, 6.5);
	glBegin(GL_QUADS);

	glVertex3f(x2, 2.3, 5.6);
	glVertex3f(x3, 2.3, 5.6);
	glVertex3f(x3, 0.7, 5.6);
	glVertex3f(x2, 0.7, 5.6);

	glEnd();
	glPopMatrix();

	

	glEnd();
	glPopMatrix();




}
void roomkillerHands(float x1, float x2)
{
	glNormal3f(0, 0, 1);
	glPushMatrix();

	//left roomkillerHands
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(x1 + 0.1, -0.2, 1);
	glVertex3f(x2, -0.2, 1);
	glVertex3f(x2, -1.1, 1);
	glVertex3f(x1 + 0.1, -1.1, 1);

	glEnd();
	glPopMatrix();

	glPushMatrix();

	//right roomkillerHands
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(x1 - 0.8, -0.2, 1);
	glVertex3f(x2 - 0.8, -0.2, 1);
	glVertex3f(x2 - 0.8, -1.1, 1);
	glVertex3f(x1 - 0.8, -1.1, 1);

	glEnd();
	glPopMatrix();

	////back square
	//glPushMatrix();
	//glBegin(GL_QUADS);
	//glColor3ub(255,255, 255);
	//glVertex3f(1, -0.8, 1);
	//glVertex3f(1.3, -0.8, 1);
	//glVertex3f(1.3 - 0.1, -0.8, 1);
	//glVertex3f(1 - 0.1, -0.8, 1);

	glEnd();
	glPopMatrix();

	//back square
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x1 - 0.1, -1.1, 0.8);
	glVertex3f(x1, -1.1, 0.8);
	glVertex3f(x1, 0.2, 0.8);
	glVertex3f(x1 - 0.1, 0.2, 0.8);
	glEnd();
	glPopMatrix();
}
void roomkillerLegs(float x1, float x2, float x3) {
	//glNormal3f(0, 0, 1);
	glPushMatrix();

	//left
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(x2 + 0.15, -1.25, 1.2);
	glVertex3f(x3, -1.25, 1.2);
	glVertex3f(x3, -2.6, 1.2);
	glVertex3f(x2 + 0.15, -2.6, 1.2);

	glEnd();
	glPopMatrix();

	//right
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(x2 - 0.20, -1.25, 1.2);
	glVertex3f(x3 - 0.40, -1.25, 1.2);
	glVertex3f(x3 - 0.40, -2.6, 1.2);
	glVertex3f(x2 - 0.20, -2.6, 1.2);

	glEnd();
	glPopMatrix();

	//side
	/*glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(60, 60, 70);
	glVertex3f(x2 - 0.2, -1.3, 2);
	glVertex3f(x3 - 0.55, -1.3, 2);
	glVertex3f(x3 - 0.55, -2.5, 2);
	glVertex3f(x2 - 0.2, -2.5, 2);*/

	glEnd();
	glPopMatrix();

	/*glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x2 , -3.5, 1);
	glVertex3f(x2, -3.3, 1);
	glVertex3f(x2, 3, 1);
	glVertex3f(x2 , 3, 1);
	glEnd();
	glPopMatrix();*/
}


void handss()
{
	//right hand
	glBegin(GL_QUADS);
	glVertex3f(2.8, 1.75, 5.6);
	glVertex3f(2.8, 1.20, 5.6);
	glVertex3f(2.65, 1.20, 5.6);
	glVertex3f(2.65, 1.75, 5.6);

	glEnd();
	glPushMatrix();

	//left hand
	glPopMatrix();

	glBegin(GL_QUADS);
	glVertex3f(3.1, 1.75, 5.6);
	glVertex3f(3.1, 1.20, 5.6);
	glVertex3f(3.25, 1.20, 5.6);
	glVertex3f(3.25, 1.75, 5.6);


	glEnd();
	glPushMatrix();
	glPopMatrix();
}
/*------------------function for scene 2------------*/
void lightBackground()
{
	glNormal3f(0, 0, 1);
	glColor3ub(135, 206, 235);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
}
void darkBackground()
{
	glColor3ub(0, 0, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
	glEnd();
	glPopMatrix();
}
void pinkBackground()
{
	glColor3ub(255, 0, 128);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
	glEnd();
	glPopMatrix();
}
void forest() {
	//sun
	glColor3ub(253, 184, 19);
	glPushMatrix();
	glTranslatef(4, 6, 0.5);
	glutSolidSphere(0.6, 50, 50);
	glPopMatrix();

	glColor4ub(253, 184, 19, 200);
	glPushMatrix();
	glTranslatef(4, 6, 0.5);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	//road
	glPushMatrix();
	glColor3ub(150, 200, 0);
	glBegin(GL_QUADS);
	glLineWidth(3.0);
	glVertex3f(-10, -1, 0.6);
	glVertex3f(30, -0.8, 0.6);

	glVertex3f(30, -2.8, 0.6);
	glVertex3f(-10, -3, 0.6);

	glEnd();
	glPopMatrix();
	//land
	glPushMatrix();
	glColor3ub(0, 255, 0);
	glBegin(GL_QUADS);
	glLineWidth(3.0);
	glVertex3f(-10, -3, 0.6);
	glVertex3f(30, -2.8, 0.6);

	glVertex3f(30, -20, 0.6);
	glVertex3f(-10, -20, 0.6);

	glEnd();
	glPopMatrix();
}
void Cloud(int x)
{
	glNormal3f(0, 0, 1);
	float a, b, c = 0;
	if (x == 1) { a = 255, b = 255, c = 255; }
	else if (x == 2) { a = 116, b = 116, c = 116; }

	glColor3ub(a, b, c);
	glPushMatrix();
	glTranslatef(0.2, 5.3, 5);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 5.3, 5);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 5, 5);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 5, 5);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, 5.1, 5);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 5.1, 5);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();
	//


	glPushMatrix();
	glTranslatef(5.9, 5.3, 5);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5, 5.3, 5);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.9, 5.3, 5);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.6, 5.7, 5);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.2, 5.7, 5);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

}
void mount(float x1, float x2, float x3) {
	glNormal3f(0, 0, 1);
	//mount 1
	glColor3ub(0, 138, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	glVertex3f(x1, -1, 0.5);
	glVertex3f(x2, 6, 0.5);

	glVertex3f(x3, -1, 0.5);

	glEnd();
	glPopMatrix();

	glColor3ub(0, 100, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	glVertex3f(x2, 6, 0.5);
	glVertex3f(x1 - 0.5, -1, 0.5);
	glVertex3f(x1, -1, 0.5);
	glEnd();
	glPopMatrix();
}

void mount2(float x1, float x2, float x3) {

	//mount2
	glColor3ub(0, 138, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);

	glVertex3f(x1, -1, 0.6);
	glVertex3f(x2, 6, 0.5);

	glVertex3f(x3, -1, 0.5);

	glEnd();
	glPopMatrix();

	glColor3ub(0, 100, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);

	glVertex3f(x2, 6, 0.5);
	glVertex3f(x1 - 0.5, -1, 0.6);
	glVertex3f(x1, -1, 0.6);
	glEnd();
	glPopMatrix();
}



void mount3(float x1, float x2, float x3)
{
	//mountain3
	glColor3ub(0, 138, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	//5,8,11
	glVertex3f(x1, -1, 0.4);
	glVertex3f(x2, 6, 0.5);

	glVertex3f(x3, -1, 0.5);

	//drawpyramid();
	glEnd();
	glPopMatrix();

	glColor3ub(0, 100, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	glVertex3f(x2, 6, 0.5);
	glVertex3f(x1 - 0.5, -1, 0.4);
	glVertex3f(x1, -1, 0.4);
	glEnd();
	glPopMatrix();

}

void mount4(float x1, float x2, float x3) {
	//mountain4
	glColor3ub(0, 138, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	//8,12,16
	glVertex3f(x1, -1, 0.4);
	glVertex3f(x2, 7, 0.5);

	glVertex3f(x3, -1, 0.5);

	//drawpyramid();
	glEnd();
	glPopMatrix();

	glColor3ub(0, 100, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	glVertex3f(x2, 7, 0.5);
	glVertex3f(x1 - 1, -1, 0.4);
	glVertex3f(x1, -1, 0.4);
	glEnd();
	glPopMatrix();
}

void mount5(float x1, float x2, float x3) {
	//mountain5
	glColor3ub(0, 138, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);

	//16,19,20
	glVertex3f(x1, -1, 0.4);
	glVertex3f(x2, 8, 0.5);

	glVertex3f(x3, -1, 0.5);

	//drawpyramid();
	glEnd();
	glPopMatrix();

	glColor3ub(0, 100, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glLineWidth(3.0);
	glVertex3f(x2, 8, 0.5);
	glVertex3f(x1 - 2, -1, 0.4);
	glVertex3f(x1, -1, 0.4);
	glEnd();
	glPopMatrix();
}
//cloud
void cloud() {
	glNormal3f(0, 0, 1);
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslated(0.5, 0.7, 2);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
}

void cloud2() {
	glNormal3f(0, 0, 1);
	glPushMatrix();
	glTranslated(0.7, 0.9, 2);
	glutSolidSphere(0.15, 50, 50);
	glPopMatrix();
}

void cloud3() {
	glNormal3f(0, 0, 1);
	glPushMatrix();
	glTranslated(1.1, 1.2, 2);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();
}

void cloud4() {
	glNormal3f(0, 0, 1);
	glPushMatrix();
	glTranslated(2, 1.5, 2);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
}
void whiteBackground()
{
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
	glEnd();
	glPopMatrix();
}
void orgThunder(float x1, float x2, float x3) {
	glColor3ub(255, 228, 204);
	glPushMatrix();
	glTranslatef(x1, 0.85, 6.5);
	glBegin(GL_LINES);
	glutSolidSphere(0.25, 50, 50);

	glPopMatrix();


	glPushMatrix();

	//front
	glColor3ub(239, 239, 239);
	glBegin(GL_QUADS);

	glVertex3f(x2, 0, 1);
	glVertex3f(x3, 0, 1);
	glVertex3f(x3, -1.3, 1);
	glVertex3f(x2, -1.3, 1);

	glEnd();
	glPopMatrix();

	//back
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x2, -1.3, 1);
	glVertex3f(x3, -1.3, 1);
	glVertex3f(x3 - 0.1, -1.5, 1);
	glVertex3f(x2 - 0.1, -1.5, 1);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x2 - 0.1, -1.5, 1);
	glVertex3f(x2, -1.3, 1);
	glVertex3f(x2, 0, 1);
	glVertex3f(x2 - 0.1, 0, 1);
	glEnd();
	glPopMatrix();
}
void knife(float x1, float x2) {
	glNormal3f(0, 0, 1);
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glBegin(GL_QUADS);
	/*glVertex3f(-0.6, 0.4, 4);
	glVertex3f(-0.6, -0.1, 4);

	glVertex3f(-0.6, 0.4, 4);
	glVertex3f(-0.3, 0.3, 4);

	glVertex3f(-0.3, 0.3, 4);
	glVertex3f(-0.6, -0.1, 4);*/
	glVertex3f(x1, 0.4, 4);
	glVertex3f(x1, -0.1, 4);

	glVertex3f(x2, 0.4, 4);
	glVertex3f(x2, 0.3, 4);

	glVertex3f(x1, 0.3, 4);
	glVertex3f(x1, -0.1, 4);
	glEnd();
	glPopMatrix();
}
void org4(float x1, float x2, float x3) {
	glColor3ub(255, 181, 114);
	glPushMatrix();
	glTranslatef(x1, 0.85, 6.5);
	glBegin(GL_LINES);
	glutSolidSphere(0.25, 50, 50);

	glPopMatrix();

	glPushMatrix();

	//front
	glColor3ub(207, 207, 255);
	glBegin(GL_QUADS);

	glVertex3f(x2, 0, 1);
	glVertex3f(x3, 0, 1);
	glVertex3f(x3, -1.3, 1);
	glVertex3f(x2, -1.3, 1);

	glEnd();
	glPopMatrix();

	//back
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x2, -1.3, 1);
	glVertex3f(x3, -1.3, 1);
	glVertex3f(x3 - 0.1, -1.5, 1);
	glVertex3f(x2 - 0.1, -1.5, 1);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(177, 177, 255);
	glVertex3f(x2 - 0.1, -1.5, 1);
	glVertex3f(x2, -1.3, 1);
	glVertex3f(x2, 0, 1);
	glVertex3f(x2 - 0.1, 0, 1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(177, 177, 177);
	glTranslatef(1.3, -1.3, 2);
	glPopMatrix();



}
void thunder()
{
	darkBackground();
	//kilat
	glColor3ub(255, 255, 0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(5, 8, 1);
	glVertex3f(9, 7.5, 1);

	//glVertex3f(9, 7.5, 1);
	glVertex3f(7, 7.3, 1);

	//glVertex3f(7, 7.3, 1);
	glVertex3f(8, 7.0, 1);

	//glVertex3f(8, 7.0, 1);
	glVertex3f(6, 5.0, 1);

	//glVertex3f(6, 5.0, 1);
	glVertex3f(7.5, 6.8, 1);

	//glVertex3f(7.5, 6.8, 1);
	glVertex3f(6.5, 7.3, 1);

	//glVertex3f(6.5, 7.3, 1);
	glVertex3f(7.5, 7.5, 1);

	//glVertex3f(7.5, 7.5, 1);
	glVertex3f(4, 8, 1);
	glEnd();
	glPopMatrix();
}

void killer(float x1, float x2, float x3) {
	glColor3ub(255, 0, 0);
	glPushMatrix();
	glTranslatef(x1, 0.85, 6.5);
	glBegin(GL_LINES);
	glutSolidSphere(0.25, 50, 50);

	glPopMatrix();

	glColor3ub(255, 0, 0);
	glPushMatrix();
	glBegin(GL_QUADS);

	glVertex3f(x2, 0, 1);
	glVertex3f(x3, 0, 1);
	glVertex3f(x3, -1.3, 1);
	glVertex3f(x2, -1.3, 1);

	glEnd();
	glPopMatrix();

	//back
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(220, 0, 0);
	glVertex3f(x2, -1.3, 1);
	glVertex3f(x3, -1.3, 1);
	glVertex3f(x3 - 0.1, -1.5, 1);
	glVertex3f(x2 - 0.1, -1.5, 1);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(220, 0, 0);
	glVertex3f(x2 - 0.1, -1.5, 1);
	glVertex3f(x2, -1.3, 1);
	glVertex3f(x2, 0, 1);
	glVertex3f(x2 - 0.1, 0, 1);
	glEnd();
	glPopMatrix();
}
float elapsedTime = 0, base_time = 0, fps = 0, frames;
void calcFPS() {
	elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	if ((elapsedTime - base_time) > 1000.0) {
		fps = frames * 1000.0 / (elapsedTime - base_time);
		printf("fps: %f", fps);
		base_time = elapsedTime;
		frames = 0;
	}
	frames++;
}

void r_idle() {}

void MyTimerFunc(int value);

int count = 0;
void pisau()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0


	glViewport(0, 0, 800, 600);


	whiteBackground();
	glPushMatrix();
	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);

	glVertex3f(0, 4, 4);
	glVertex3f(7, 4, 4);


	glVertex3f(3.5, 0, 4);
	glVertex3f(0, 4, 4);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);
	glColor3ub(100, 100, 100);

	glVertex3f(7, 4, 4);
	glVertex3f(7.5, 3.5, 4);

	/*glVertex3f(7.5, 3.5, 4);
	glVertex3f(5.1, -0.1, 4);*/

	glVertex3f(5.1, -0.1, 4);
	glVertex3f(3.5, 0, 4);
	glEnd();
	glPopMatrix();

	//hold

	glNormal3f(0, 0, 1);
	glColor3ub(255, 0, 0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(0.5, 3.7, 3);
	glVertex3f(-2.5, 1.7, 3);

	/*glVertex3f(-2.5, 1.7, 3);
	glVertex3f(-2.5, -0.3, 3);*/

	glVertex3f(-3.5, -0.5, 3);
	glVertex3f(2, 2, 3);
	glEnd();
	glPopMatrix();

	glNormal3f(0, 0, 1);
	glColor3ub(215, 0, 0);
	glPushMatrix();
	glBegin(GL_QUADS);

	glVertex3f(2, 2, 3);
	glVertex3f(2 - 0.5, 2 - 0.5, 3);

	//glVertex3f(2 - 0.5, 2 - 0.5, 3);
	glVertex3f(-5, -1.5, 3);
	glVertex3f(-2.5, 1.7, 3);
	glEnd();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	//base();
	lightBase();
	//bedsideTable();
	bed();
	//door();
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();

	float pos1, pos2, pos3 = 0.0;

	if (x_position >= -222.22) {
		pos1 = 2.7 + x_position;
		pos2 = 2.5 + x_position;
		pos3 = 3.0 + x_position;
		glRotatef(count, pos1, pos2, pos3);
		roomorgTest(pos1, pos2, pos3);
		x_position -= 0.0009;
		count += 0.8;

		//if (remainder(count,30) == 0) handTest2(pos2, pos3);
		//else if (remainder(count, 30) != 0) handTest(pos2, pos3);
		////handTest(pos2, pos3);
		//roomlegTest(pos2, pos3);
		/*handTest2(pos2, pos3);*/
	}
	//orgTest(3, 2.5, 3.5);
	//handTest2(2.8, 3.1);
	glPushMatrix();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void display2() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	base();
	//bedsideTable();
	bed();
	//door();
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();


	roomorgTest(0, -0.2, 0.2);
	//body front
	//glTranslatef(10, 1, 1);
	//glColor3ub(187, 187, 255);
	//glNormal3f(0, 0, 1);
	//glPushMatrix();
	//glTranslatef(3, 2, 6.5);
	//glBegin(GL_QUADS);

	//glVertex3f(2, 1.75, 5.6);
	//glVertex3f(2, 1.75, 5.6);
	//glVertex3f(6, 0.7, 5.6);
	//glVertex3f(6, 0.7, 5.6);

	glEnd();
	glPopMatrix();
	//handTest(-0.2, 0.1);
	//roomlegTest(-0.2, 0.1);

	glFlush();
	glutSwapBuffers();
}
void display3() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);


	base();
	//bedsideTable();
	bedRise();
	//door();
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();
	org(0.25, 0, 2);

	glFlush();
	glutSwapBuffers();
}
void display4() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);


	base();
	//bedsideTable();
	bedRise();
	/*door();*/
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();
	org(0.25, 0, 2);

	cloud();

	glFlush();
	glutSwapBuffers();
}

void display5() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);


	base();
	//bedsideTable();
	bedRise();
	/*door();*/
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();
	org(0.25, 0, 2);
	cloud();
	cloud2();

	glFlush();
	glutSwapBuffers();
}
void display6() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);


	base();
	//bedsideTable();
	bedRise();
	/*door();*/
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();
	org(0.25, 0, 2);
	cloud();
	cloud2();
	cloud3();

	glFlush();
	glutSwapBuffers();
}

void display7() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);


	base();
	//bedsideTable();
	bedRise();
	/*door();*/
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();
	org(0.2, 0, 2);
	cloud();
	cloud2();
	cloud3();
	cloud4();

	glFlush();
	glutSwapBuffers();
}
void display8() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	forest();
	//mount(1);
	glPopMatrix();

	if (m1x1 >= -4)
	{
		//	//stop = 0 + x_position;
		org4(0.2 + x_position, 0.2 + x_position2, 0.7 + x_position2);
		//orgHands(0.6 + x_position2, 0.9 + x_position2);
		//orgLegs(-0.2 + x_position, 0.2 + x_position2, 0.7 + x_position2);
		glPushMatrix();
		/*glTranslatef(0+x_position, -0.4, 4);
		glutSolidCube(0.5);*/
		//glutSolidTetrahedron();
		glPopMatrix();
		//hand();
		x_position += 0.0001;
		x_position2 += 0.00015;
		mount(-1 + m1x1, 2 + m1x2, 5 + m1x3);
		mount2(-3 + m1x1, 0 + m1x2, 3 + m1x3);
		mount3(5 + m1x1, 8 + m1x2, 11 + m1x3);
		mount4(8 + m1x1, 12 + m1x2, 16 + m1x3);
		mount5(16 + m1x1, 19 + m1x2, 20 - m1x3);
		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
		//cube();
		//glTranslatef(x_coordinate, 0.0f, 0.0f);

	}
	Cloud(1);


	glFlush();
	glutSwapBuffers();
}

void display9() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	forest();
	//mount(1);
	glPopMatrix();

	if (m1x1 >= -4)
	{
		//stop = 0 + x_position;

		org4(1.3 + x_position, 2.2 + x_position2, 2.7 + x_position2);

		x_position += 0.0001;
		x_position2 += 0.00015;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);
		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}
	Cloud(1);
	glFlush();
	glutSwapBuffers();
}

void display10() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	orgThunder(1.2, 2.6, 3.3);


	x_position += 0.00009;
	x_position2 += 0.00015;
	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);
	m1x1 -= 0.000095;
	m1x2 -= 0.000095;
	m1x3 -= 0.00003;

	Cloud(1);

	thunder();


	glFlush();
	glutSwapBuffers();
}

void display11() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	forest();
	glPopMatrix();

	//stop = 0 + x_position;

	org4(1.2, 2.6, 3.3);

	x_position += 0.00009;
	x_position2 += 0.00015;
	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);
	m1x1 -= 0.000095;
	m1x2 -= 0.000095;
	m1x3 -= 0.00003;

	//org4(2.1, 4.2, 4.6);
	//shadow(2.1, 3.4);

	whiteBackground();


	glFlush();
	glutSwapBuffers();
}

void display12() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	orgThunder(1.2, 2.6, 3.3);


	x_position += 0.00009;
	x_position2 += 0.00015;
	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);
	m1x1 -= 0.000095;
	m1x2 -= 0.000095;
	m1x3 -= 0.00003;

	Cloud(1);

	thunder();


	glFlush();
	glutSwapBuffers();
}

void display13() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	forest();
	glPopMatrix();

	//stop = 0 + x_position;

	org4(1.2, 2.6, 3.3);
	killer(-0.2, 0.4, 0.8);

	x_position += 0.00009;
	x_position2 += 0.00015;
	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);
	m1x1 -= 0.000095;
	m1x2 -= 0.000095;
	m1x3 -= 0.00003;

	//org4(2.1, 4.2, 4.6);
	//shadow(2.1, 3.4);

	whiteBackground();


	glFlush();
	glutSwapBuffers();
}



//end for scene 2
//POV start
//POV
void display14() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	glNormal3f(0, 0, 0);
	whiteBackground();
	//head
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(3, 2, 5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//body
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(3, -2.5, 5);
	glutSolidCube(5);
	glEnd();
	glPopMatrix();

	//hand right
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);
	glVertex3f(3, 1, 5);
	glVertex3f(8, 1, 5);

	/*glVertex3f(8, 1, 5);
	glVertex3f(9.5, -1, 5);*/

	glVertex3f(9.5, -1, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(139, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(9.5, -1, 5);
	glVertex3f(9.5, -8, 5);

	//glVertex3f(9.5, -4, 5);
	glVertex3f(8, -8, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	//hand left
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);

	glVertex3f(3, 0.6, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(3, -0.5, 2.5);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(139, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(3, -0.5, 2.5);
	glVertex3f(3, -8, 2.5);

	/*glVertex3f(3, -8, 2.5);
	glVertex3f(0, -8, 2.5);*/

	glVertex3f(0, -8, 2.5);
	glVertex3f(0, -0.5, 2.5);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(0, -8, 2.5);

	/*glVertex3f(0, -8, 2.5);
	glVertex3f(-1, -7.5, 2.5);*/

	glVertex3f(-1, -7.5, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glEnd();
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f); //text color
	glRasterPos3f(0, -8, 3); //text position
	char text[] = "Husband: Dear wife, let's start saving for";
	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glFlush();
	glutSwapBuffers();
}

void display15() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	glNormal3f(0, 0, 0);
	whiteBackground();
	//head
	glPushMatrix();
	glColor3ub(255, 181, 114);
	glTranslatef(3, 2, 5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//body
	glPushMatrix();
	glColor3ub(207, 207, 255);
	glTranslatef(3, -2.5, 5);
	glutSolidCube(5);
	glEnd();
	glPopMatrix();

	//hand right
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);
	glVertex3f(3, 1, 5);
	glVertex3f(8, 1, 5);

	/*glVertex3f(8, 1, 5);
	glVertex3f(9.5, -1, 5);*/

	glVertex3f(9.5, -1, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(177, 177, 255);
	glBegin(GL_QUADS);

	glVertex3f(9.5, -1, 5);
	glVertex3f(9.5, -8, 5);

	//glVertex3f(9.5, -4, 5);
	glVertex3f(8, -8, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	//hand left
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);

	glVertex3f(3, 0.6, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(3, -0.5, 2.5);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(177, 177, 255);
	glBegin(GL_QUADS);

	glVertex3f(3, -0.5, 2.5);
	glVertex3f(3, -8, 2.5);

	/*glVertex3f(3, -8, 2.5);
	glVertex3f(0, -8, 2.5);*/

	glVertex3f(0, -8, 2.5);
	glVertex3f(0, -0.5, 2.5);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(0, -8, 2.5);

	/*glVertex3f(0, -8, 2.5);
	glVertex3f(-1, -7.5, 2.5);*/

	glVertex3f(-1, -7.5, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glEnd();
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f); //text color
	glRasterPos3f(0, -8, 3); //text position
	char text[] = "Husband: Dear wife, let's start saving for";
	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glFlush();
	glutSwapBuffers();
}


void display16()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	org4(3.1, 5.9, 6.3);
	killer(-0.55, -0.4, -0.1);
	float time = 0.0;
	
	if (time <= 10) {
		knife(0.5 + time, 0.8);
		time += 0.01;
	}
	forest();


	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

	whiteBackground();
	Cloud(2);


	glFlush();
	glutSwapBuffers();
}

void display17() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	killer(-0.8, -0.7, -0.5);
	knife(-0.6, -0.2);
	forest();

	//glTranslatef(4, 5, 5);
	float x_position = 0.0;
	float x_position2 = 0.0;

	if (m1x1 >= -4)
	{

		//stop = 0 + x_position;
		glPushMatrix();

		org4(2.65 + x_position, 5. + x_position2, 5.7 + x_position2);
		glPopMatrix();

		x_position += 0.0008;
		x_position2 += 0.00165;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}


	glColor3ub(255, 255, 255);

	whiteBackground();
	Cloud(2);
	glFlush();
	glutSwapBuffers();
}

void display18() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	killer(-0.7, -0.5, -0.3);
	knife(-0.45, -0.2);
	forest();
	float x_position = 0.0;
	float x_position2 = 0.0;
	if (m1x1 >= -4)
	{

		//stop = 0 + x_position;
		glPushMatrix();

		org4(2.80 + x_position, 5.4 + x_position2, 6.0 + x_position2);
		glPopMatrix();

		x_position += 0.0008;
		x_position2 += 0.00165;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}
	whiteBackground();
	Cloud(2);

	glFlush();
	glutSwapBuffers();
}

void display19() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	killer(-0.7, -0.6, -0.4);
	knife(-0.55, -0.25);
	forest();
	float x_position = 0.0;
	float x_position2 = 0.0;
	if (m1x1 >= -4)
	{

		//stop = 0 + x_position;
		glPushMatrix();

		org4(2.7 + x_position, 5.2 + x_position2, 5.6 + x_position2);
		glPopMatrix();

		x_position += 0.0009;
		x_position2 += 0.00165;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}
	whiteBackground();
	Cloud(2);

	glFlush();
	glutSwapBuffers();
}

void display20()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	/*org4(3.1, 5.9, 6.3);
	killer(-0.55, -0.4, -0.1);*/
	float time = 0.0;

	//if (time <= 10) {
	//	knife(0.5 + time, 0.8);
	//	time += 0.01;
	//}
	org4(2.0 , 3.9, 4.3);
	killer(-0.8 + 0.0001, -0.7 + 0.0001, -0.5 + 0.0001);
	if (m1x1 >= -4)
	{

		//stop = 0 + x_position;
		glPushMatrix();
		knife(0.7 + time, 1.0);
		time += 0.01;
		
		glPopMatrix();

		x_position += 0.0008;
		x_position2 += 0.00165;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}
	forest();


	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

	whiteBackground();
	Cloud(2);


	glFlush();
	glutSwapBuffers();
}

void display21()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	/*org4(3.1, 5.9, 6.3);
	killer(-0.55, -0.4, -0.1);*/
	float time = 0.0;

	//if (time <= 10) {
	//	knife(0.5 + time, 0.8);
	//	time += 0.01;
	//}
	org4(2.0, 3.9, 4.3);
	killer(-0.8 + 0.0001, -0.7 + 0.0001, -0.5 + 0.0001);
	if (m1x1 >= -4)
	{

		//stop = 0 + x_position;
		glPushMatrix();
		knife(0.9 + time, 1.3);
		time += 0.01;

		glPopMatrix();

		x_position += 0.0008;
		x_position2 += 0.00165;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}
	forest();


	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

	whiteBackground();
	Cloud(2);


	glFlush();
	glutSwapBuffers();
}

void display22()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	//lightBackground();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	//org4(2.1, 4.3, 4.5);
	glPopMatrix();
	//shadow(2.1, 3.4);
	/*org4(3.1, 5.9, 6.3);
	killer(-0.55, -0.4, -0.1);*/
	float time = 0.0;

	//if (time <= 10) {
	//	knife(0.5 + time, 0.8);
	//	time += 0.01;
	//}
	org4(2.0, 3.9, 4.3);
	killer(-0.8 + 0.0001, -0.7 + 0.0001, -0.5 + 0.0001);
	if (m1x1 >= -4)
	{

		//stop = 0 + x_position;
		glPushMatrix();
		knife(2.1 + time, 2.5);
		time += 0.01;

		glPopMatrix();

		x_position += 0.0008;
		x_position2 += 0.00165;
		mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
		mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
		mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
		mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
		mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

		m1x1 -= 0.000095;
		m1x2 -= 0.000095;
		m1x3 -= 0.00003;
	}
	forest();


	mount(-1.7 + m1x1, 2.7 + m1x2, 5.7 + m1x3);
	mount2(-3.5 + m1x1, 0.5 + m1x2, 3.5 + m1x3);
	mount3(5.5 + m1x1, 8.5 + m1x2, 11.5 + m1x3);
	mount4(8.5 + m1x1, 12.5 + m1x2, 16.5 + m1x3);
	mount5(16.5 + m1x1, 19.5 + m1x2, 20.5 - m1x3);

	whiteBackground();
	Cloud(2);


	glFlush();
	glutSwapBuffers();
}

void display23() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	base();
	//bedsideTable();
	bedRise();
	//door();
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();
	org(0.25, 0, 2);


	glFlush();
	glutSwapBuffers();

}

void display24() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	base();
	//bedsideTable();
	bed();
	//door();
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();


	roomorgTest(0, -0.2, 0.2);

	glEnd();
	glPopMatrix();
	//handTest(-0.2, 0.1);
	//roomlegTest(-0.2, 0.1);

	glFlush();
	glutSwapBuffers();

}

void display25() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	base();
	//bedsideTable();
	bed();
	//door();
	lamp();
	//window();
	//fan();
	dressingtable();
	pintu();


	roomorgTest(0, -0.2, 0.2);
	roomkiller(2.7, 2.7, 3.5);
	roomkillerHands(2.0, 2.0);
	roomkillerLegs(2.7, 2.7, 3.5);

	glEnd();
	glPopMatrix();
	//handTest(-0.2, 0.1);
	//roomlegTest(-0.2, 0.1);

	glFlush();
	glutSwapBuffers();

}

void display26() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);
	
	glNormal3f(0, 0, 0);
	pinkBackground();
	//head
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(3, 2, 5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//body
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(3, -2.5, 5);
	glutSolidCube(5);
	glEnd();
	glPopMatrix();

	//hand right
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);
	glVertex3f(3, 1, 5);
	glVertex3f(8, 1, 5);

	/*glVertex3f(8, 1, 5);
	glVertex3f(9.5, -1, 5);*/

	glVertex3f(9.5, -1, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(139, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(9.5, -1, 5);
	glVertex3f(9.5, -8, 5);

	//glVertex3f(9.5, -4, 5);
	glVertex3f(8, -8, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	//hand left
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);

	glVertex3f(3, 0.6, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(3, -0.5, 2.5);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(139, 0, 0);
	glBegin(GL_QUADS);

	glVertex3f(3, -0.5, 2.5);
	glVertex3f(3, -8, 2.5);

	/*glVertex3f(3, -8, 2.5);
	glVertex3f(0, -8, 2.5);*/

	glVertex3f(0, -8, 2.5);
	glVertex3f(0, -0.5, 2.5);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(0, -8, 2.5);

	/*glVertex3f(0, -8, 2.5);
	glVertex3f(-1, -7.5, 2.5);*/

	glVertex3f(-1, -7.5, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glEnd();
	glPopMatrix();



	glFlush();
	glutSwapBuffers();
}

void display27() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	glNormal3f(0, 0, 0);
	pinkBackground();
	//head
	glPushMatrix();
	glColor3ub(255, 181, 114);
	glTranslatef(3, 2, 5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//body
	glPushMatrix();
	glColor3ub(207, 207, 255);
	glTranslatef(3, -2.5, 5);
	glutSolidCube(5);
	glEnd();
	glPopMatrix();

	//hand right
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);
	glVertex3f(3, 1, 5);
	glVertex3f(8, 1, 5);

	/*glVertex3f(8, 1, 5);
	glVertex3f(9.5, -1, 5);*/

	glVertex3f(9.5, -1, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(177, 177, 255);
	glBegin(GL_QUADS);

	glVertex3f(9.5, -1, 5);
	glVertex3f(9.5, -8, 5);

	//glVertex3f(9.5, -4, 5);
	glVertex3f(8, -8, 5);
	glVertex3f(8, -1, 5);
	glEnd();
	glPopMatrix();

	//hand left
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(19, 0, 0);

	glVertex3f(3, 0.6, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(3, -0.5, 2.5);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(177, 177, 255);
	glBegin(GL_QUADS);

	glVertex3f(3, -0.5, 2.5);
	glVertex3f(3, -8, 2.5);

	/*glVertex3f(3, -8, 2.5);
	glVertex3f(0, -8, 2.5);*/

	glVertex3f(0, -8, 2.5);
	glVertex3f(0, -0.5, 2.5);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);

	glVertex3f(0, -0.5, 2.5);
	glVertex3f(0, -8, 2.5);

	/*glVertex3f(0, -8, 2.5);
	glVertex3f(-1, -7.5, 2.5);*/

	glVertex3f(-1, -7.5, 2.5);
	glVertex3f(-1, 0.6, 2.5);

	glEnd();
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f); //text color
	glRasterPos3f(0, -8, 3); //text position
	char text[] = "Husband: Dear wife, let's start saving for";
	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glFlush();
	glutSwapBuffers();
}

void display28() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); // -1.0, 2.0, 14.0 / 5.0, 0, 0 / 0, 1, 0

	glViewport(0, 0, 800, 600);

	glNormal3f(0, 0, 0);
	darkBackground();
	glFlush();
	glutSwapBuffers();
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800, 0.0, 600);
}

void idle() {
	DWORD start = GetTickCount64();
	while (GetTickCount64() - start < 1000 / FPS);
	x += dx;
	y += dy;
	if (x < 0 || x > SCREEN_WIDTH) dx *= -1;
	if (y < 0 || y > SCREEN_HEIGHT) dy *= -1;
	glutPostRedisplay();
}

void initGL() {
	glClearColor(0.15, 0.88, 0.96, 0.8);

	glMatrixMode(GL_PROJECTION);
	glPointSize(4.0);
	glLoadIdentity();
	gluPerspective(45, 1.0, 2.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	GLfloat dir[] = { 0.2,0.0,1.0,0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, dir);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Test");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(1000, MyTimerFunc, 0);
	srand(1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	initGL();
	glutMainLoop();


	return 0;

}

void MyTimerFunc(int value)
{


	if (value == 0)
	{
		glutDisplayFunc(display);
		glutIdleFunc(display);
		glutTimerFunc(1350, MyTimerFunc, 1);
		//glutTimerFunc(300, MyTimerFunc, 1);
	}




	if (value == 1)
	{
		glutDisplayFunc(display2);
		glutIdleFunc(display2);
		glutTimerFunc(700, MyTimerFunc, 2);
	}


	if (value == 2)
	{
		glutDisplayFunc(display3);
		glutIdleFunc(display3);
		glutTimerFunc(700, MyTimerFunc, 3);
	}

	if (value == 3)
	{
		glutDisplayFunc(display4);
		glutIdleFunc(display4);
		glutTimerFunc(1000, MyTimerFunc, 4);
	}

	if (value == 4)
	{
		glutDisplayFunc(display5);
		glutIdleFunc(display5);
		glutTimerFunc(1000, MyTimerFunc, 5);
	}

	if (value == 5)
	{
		glutDisplayFunc(display6);
		glutIdleFunc(display6);
		glutTimerFunc(1000, MyTimerFunc, 6);
	}

	if (value == 6)
	{
		glutDisplayFunc(display7);
		glutIdleFunc(display7);
		glutTimerFunc(1000, MyTimerFunc, 7);
	}
	/*SCENE 2*/
	if (value == 7)
	{
		glutDisplayFunc(display8);
		glutIdleFunc(display8);
		//glutTimerFunc(7000, MyTimerFunc, 1);
		glutTimerFunc(5500, MyTimerFunc, 8);
	}


	if (value == 8)
	{
		glutDisplayFunc(display9);
		glutIdleFunc(display9);
		//glutTimerFunc(1000, MyTimerFunc, 2);
		glutTimerFunc(1000, MyTimerFunc, 9);
	}

	if (value == 9)
	{
		glutDisplayFunc(display10);
		glutIdleFunc(display10);
		//glutTimerFunc(3000, MyTimerFunc, 3);
		glutTimerFunc(1000, MyTimerFunc, 10);
	}

	if (value == 10)
	{
		glutDisplayFunc(display11);
		glutIdleFunc(display11);
		//glutTimerFunc(700, MyTimerFunc, 4);
		glutTimerFunc(1000, MyTimerFunc, 11);
	}


	if (value == 11)
	{
		glutDisplayFunc(display12);
		glutIdleFunc(display12);
		glutTimerFunc(1000, MyTimerFunc, 12);
		//glutTimerFunc(100, MyTimerFunc, 5);
	}

	if (value == 12)
	{
		glutDisplayFunc(display13);
		glutIdleFunc(display13);
		glutTimerFunc(2000, MyTimerFunc, 13);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 13)
	{
		glutDisplayFunc(display14);
		glutIdleFunc(display14);
		glutTimerFunc(2000, MyTimerFunc, 14);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 14)
	{
		glutDisplayFunc(display15);
		glutIdleFunc(display15);
		glutTimerFunc(2000, MyTimerFunc, 15);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}
	if (value == 15)
	{
		glutDisplayFunc(pisau);
		glutIdleFunc(pisau);
		glutTimerFunc(2000, MyTimerFunc, 16);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	//if (value == 16)
	//{
	//	glutDisplayFunc(display16);
	//	glutIdleFunc(display16);
	//	glutTimerFunc(2000, MyTimerFunc, 17);
	//	//glutTimerFunc(100, MyTimerFunc, 6);
	//}
	if (value == 16)
	{
		glutDisplayFunc(display17);
		glutIdleFunc(display17);
		glutTimerFunc(2000, MyTimerFunc, 17);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}
	if (value == 17)
	{
		glutDisplayFunc(display18);
		glutIdleFunc(display18);
		glutTimerFunc(2000, MyTimerFunc, 18);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 18)
	{
		glutDisplayFunc(display19);
		glutIdleFunc(display19);
		glutTimerFunc(2000, MyTimerFunc, 19);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 19)
	{
		glutDisplayFunc(display20);
		glutIdleFunc(display20);
		glutTimerFunc(2000, MyTimerFunc, 20);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}
	
	if (value == 20)
	{
		glutDisplayFunc(display21);
		glutIdleFunc(display21);
		glutTimerFunc(2000, MyTimerFunc, 21);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 21)
	{
		glutDisplayFunc(display22);
		glutIdleFunc(display22);
		glutTimerFunc(2000, MyTimerFunc, 22);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 22)
	{
		glutDisplayFunc(display23);
		glutIdleFunc(display23);
		glutTimerFunc(2000, MyTimerFunc, 23);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 23)
	{
		glutDisplayFunc(display24);
		glutIdleFunc(display24);
		glutTimerFunc(2000, MyTimerFunc, 24);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 24)
	{
		glutDisplayFunc(display25);
		glutIdleFunc(display25);
		glutTimerFunc(2000, MyTimerFunc, 25);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 25)
	{
		glutDisplayFunc(display26);
		glutIdleFunc(display26);
		glutTimerFunc(2000, MyTimerFunc, 26);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 26)
	{
		glutDisplayFunc(display27);
		glutIdleFunc(display27);
		glutTimerFunc(2000, MyTimerFunc, 27);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}

	if (value == 27)
	{
		glutDisplayFunc(display28);
		glutIdleFunc(display28);
		glutTimerFunc(2000, MyTimerFunc, 28);
		//glutTimerFunc(100, MyTimerFunc, 6);
	}
}

