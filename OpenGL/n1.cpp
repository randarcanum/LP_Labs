#include <stdlib.h>
#include <gl/glut.h>

GLint width = 512, height = 512;
const int cube_size = 200;

void display(void) {
    int left, right, top, bottom;
    left = (width-cube_size)/2;
    right = left+cube_size;
    bottom = (height-cube_size)/2;
    top = bottom+cube_size;

    glClearColor(0.7, 0.7, 0.7, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(left, bottom);
    glVertex2f(left, top);
    glVertex2f(right, top);
    glVertex2f(right, bottom);
    glEnd();
    glFinish();
}

void reshape(GLint w, GLint h) {
    width = w;
    height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    if(key == '\033')
        exit(0);
}

void main(int argc, char *argv[]) {
    glutInit(&argc, argv);

}