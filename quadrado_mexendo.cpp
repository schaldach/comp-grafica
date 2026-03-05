// ConsoleApplication1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>

#define window_size 512

int y_offset = 0;
int x_offset = 0;

const double PI = 3.141592653589793;

void display();
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitWindowSize(window_size, window_size);

	glutCreateWindow("Desenhando uma linha");
	glClearColor(1.0, 0, 1.0, 1.0);
	glOrtho(0, window_size, 0, window_size, -1, 1);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}


void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	int square_side = 30;

	glBegin(GL_POLYGON);
	glVertex2i(30 + x_offset, 30 + y_offset);
	glVertex2i(30 + x_offset + square_side, 30 + y_offset);
	glVertex2i(30 + x_offset + square_side, 30 + y_offset + square_side);
	glVertex2i(30 + x_offset, 30 + y_offset + square_side);
	glVertex2i(30 + x_offset, 30 + y_offset);
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		y_offset += 20;
		break;
	case 's':
		y_offset -= 20;
		break;
	case 'a':
		x_offset -= 20;
		break;
	case 'd':
		x_offset += 20;
		break;
	case 27:
		exit(0);
		break;
	}

}
