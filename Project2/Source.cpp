#include <windows.h>
#include <GL/glut.h>
#include<math.h>
#include <stdio.h>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
// Global variables
const int windowWidth = 1000;
const int windowHeight = 1000;
float p1 = 150, p2 = 140, p3 = 75, p4 = 85, p5 = 185, p6 = 50, p7 = 175, p9 = 145, p11 = 135, p10 = 155, p12 =
145, p13 = 135, p14 = 155, p15 = 75, p16 = 150, p17 = 185, p18 = 50, p19 = 75, p20 = 150, p21 = 140, p22 = 85;
float deltax = 0.04, deltay = 0.02, deltay1 = 0.04;
bool stop = false;
float bx = 50;
bool isSunVisible = true;
float circlePosY = 200.0f;
float skyColorR = 0.0f, skyColorG = 0.9f, skyColorB = 1.0f;
float randomFloat(float min, float max);
bool transitioningToNight = false;
bool transitioningToDay = false;
const float colorTransitionSpeed = 0.001f;
void drawStars(float x, float y) {
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
void DrawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta); //calculate the x component
		float y = r * sinf(theta); //calculate the y component
		glVertex2f(x + cx, y + cy); //output vertex
	}
	glEnd();
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(skyColorR, skyColorG, skyColorB, 0);
	gluOrtho2D(0.0, 420.0, 0.0, 220.0);
	//sun and moon
	if (isSunVisible) {
		// Draw the sun
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		DrawCircle(175, circlePosY, 13, 50);
	}
	else {
		// Draw the moon
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		DrawCircle(175, circlePosY, 13, 50);
	}
	if (!isSunVisible) { // If it's night
		glColor3f(1.0, 1.0, 1.0); // White color for stars
		for (int i = 0; i < 1000; ++i) {
			drawStars(randomFloat(0, windowWidth), randomFloat(0, windowHeight));
		}
	}
	// the sea
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2i(0, 130);
	glVertex2i(0, 60);
	glVertex2f(500, 60);
	glVertex2f(500, 130);
	glEnd();
	// mountains
	glColor3ub(184, 134, 11);
	glBegin(GL_POLYGON);
	glVertex2d(-40, 120);
	glVertex2d(200, 120);
	glVertex2d(100, 220);
	glEnd();
	glColor3ub(218, 165, 32);
	glBegin(GL_POLYGON);
	glVertex2d(150, 120);
	glVertex2d(350, 120);
	glVertex2d(250, 220);
	glEnd();
	glColor3ub(184, 134, 11);
	glBegin(GL_POLYGON);
	glVertex2d(300, 120);
	glVertex2d(520, 120);
	glVertex2d(400, 220);
	glEnd();
	// Boats
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(p3, 60);
	glVertex2d(p1, 60);
	glVertex2d(p5, 80);
	glVertex2d(p6, 80);
	glEnd();
	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2d(p3, 80);
	glVertex2d(p1, 80);
	glVertex2d(p2, 100);
	glVertex2d(p4, 100);
	glEnd();
	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2d(75, 105);
	glVertex2d(150, 105);
	glVertex2d(185, 120);
	glVertex2d(50, 120);
	glEnd();
	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2d(75, 120);
	glVertex2d(150, 120);
	glVertex2d(140, 130);
	glVertex2d(85, 130);
	glEnd();
	// green land
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 60);
	glVertex2i(0, 0);
	glVertex2f(500, 0);
	glVertex2f(500, 60);
	glEnd();
	// Trees
	glLineWidth(30);
	glColor3f(0.5, 0.4, 0);
	glBegin(GL_LINES);
	glVertex2i(185, 30);
	glVertex2i(185, 40);
	glEnd();
	glLineWidth(30);
	glColor3f(0.5, 0.4, 0);
	glBegin(GL_LINES);
	glVertex2i(85, 30);
	glVertex2i(85, 40);
	glEnd();
	glColor3f(0.2, 0.6, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(65, 40);
	glVertex2f(105, 40);
	glVertex2f(85, 90);
	glEnd();
	glColor3f(0.2, 0.6, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(165, 40);
	glVertex2f(205, 40);
	glVertex2f(185, 90);
	glEnd();
	// Tree 2
	glLineWidth(30);
	glColor3f(0.5, 0.4, 0);
	glBegin(GL_LINES);
	glVertex2i(285, 30);
	glVertex2i(285, 40);
	glEnd();
	glColor3f(0.2, 0.6, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(265, 40);
	glVertex2f(305, 40);
	glVertex2f(285, 90);
	glEnd();
	// Tree 3
	glLineWidth(30);
	glColor3f(0.5, 0.4, 0);
	glBegin(GL_LINES);
	glVertex2i(385, 30);
	glVertex2i(385, 40);
	glEnd();
	glColor3f(0.2, 0.6, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(365, 40);
	glVertex2f(405, 40);
	glVertex2f(385, 90);
	glEnd();
	// Clouds
	glColor3f(1, 1, 1);
	DrawCircle(p9, 205, 13, 30);
	DrawCircle(p11, 205, 10, 30);
	DrawCircle(p10, 205, 10, 30);
	DrawCircle(p12, 170, 13, 30);
	DrawCircle(p13, 170, 10, 30);
	DrawCircle(p14, 170, 10, 30);
	DrawCircle(p9 + 50, 185, 13, 30);
	DrawCircle(p11 + 50, 185, 10, 30);
	DrawCircle(p10 + 50, 185, 10, 30);
	DrawCircle(p12 + 100, 160, 13, 30);
	DrawCircle(p13 + 100, 160, 10, 30);
	DrawCircle(p14 + 100, 160, 10, 30);
	glFlush();
}
void update(int value) {
	if (!stop) {
		p1 += deltax;
		if (p1 > 500 || p1 <= 0)
			deltax = -deltax;
		p2 += deltax;
		if (p2 > 500 || p2 <= 0)
			deltax = -deltax;
		p3 += deltax;
		if (p3 > 500 || p3 <= 0)
			deltax = -deltax;
		p4 += deltax;
		if (p4 > 500 || p4 <= 0)
			deltax = -deltax;
		p5 += deltax;
		if (p5 > 500 || p5 <= 0)
			deltax = -deltax;
		p6 += deltax;
		if (p6 > 500 || p6 <= 0)
			deltax = -deltax;
		//clouds movement
		p9 += deltay;
		if (p9 > 500 || p9 <= 0)
			deltay = -deltay;
		p11 += deltay;
		if (p11 > 500 || p11 <= 0)
			deltay = -deltay;
		p10 += deltay;
		if (p10 > 500 || p10 <= 0)
			deltay = -deltay;
		p12 += deltay1;
		if (p12 > 500 || p12 <= 0)
			deltay1 = -deltay1;
		p13 += deltay1;
		if (p13 > 500 || p13 <= 0)
			deltay1 = -deltay1;
		p14 += deltay1;
		if (p14 > 500 || p14 <= 0)
			deltay1 = -deltay1;
		if (isSunVisible) {
			circlePosY -= deltay;
			if (circlePosY <= 110.0f) {
				isSunVisible = false;
			}
		}
		else {
			circlePosY += deltay;
			if (circlePosY >= 200.0f) {
				isSunVisible = true;
			}
		}
		// Sky color transition
		if (!isSunVisible && skyColorB > 0.2f) {
			// Transition to night
			skyColorR -= colorTransitionSpeed; if (skyColorR < 0.0f) skyColorR = 0.0f;
			skyColorG -= colorTransitionSpeed; if (skyColorG < 0.0f) skyColorG = 0.0f;
			skyColorB -= colorTransitionSpeed; if (skyColorB < 0.2f) skyColorB = 0.2f;
		}
		else if (isSunVisible && skyColorB < 1.0f) {
			// Transition to day
			skyColorR += colorTransitionSpeed; if (skyColorR > 0.0f) skyColorR = 0.0f;
			skyColorG += colorTransitionSpeed; if (skyColorG > 0.9f) skyColorG = 0.9f;
			skyColorB += colorTransitionSpeed; if (skyColorB > 1.0f) skyColorB = 1.0f;
		}
	}
	glutPostRedisplay();
	// Set the next update
	glutTimerFunc(1, update, 0);
}
void key(unsigned char key, int x, int y)
{
	if (key == 'a') stop = !stop;
	if (key == 'e') exit(0);
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("");
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
	glutTimerFunc(0, update, 0);
	glutMainLoop();
	srand(time(0)); // Seed the random number generator
	return 0;
}
// Function to generate a random float between min and max
float randomFloat(float min, float max) {
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}