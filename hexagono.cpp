// ConsoleApplication1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>

#define window_size 64

const double PI = 3.141592653589793;

void display();
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitWindowSize(window_size, window_size);

	glutCreateWindow("Desenhando uma linha");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0, window_size, 0, window_size, -1, 1);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}

// exercício aula - pentágono com cada segmento medindo 30 unidades

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	int sides = 5;
	int middle_point = window_size / 2;
	int radius = 15 / sin(36*PI/180);
	float angle_step = 360 / sides;

	float first_x, first_y;

	for (int i = 0; i < sides; i++) {
		float angle = (((angle_step * i) + 54 + 180) * PI) / 180;
		float x_offset = cos(angle) * radius;
		float y_offset = sin(angle) * radius;
		float x = middle_point + x_offset;
		float y = middle_point + y_offset;
		if (i == 0) {
			first_x = x;
			first_y = y;
		}
		else {
			glVertex2i(x, y);
		}
		glVertex2i(x, y);
	}
	glVertex2i(first_x, first_y);

	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	}

}
