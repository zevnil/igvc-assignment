#include <GL/glut.h>
#include <math.h>

GLfloat xRotate, yRotate, zRotate1, zRotate2;

void displayCone(void) { 
	GLdouble base=1;
	GLdouble height=1.5;
	GLint slices =100;
	GLint stacks =100;
	GLfloat light_pos[] = {1.0, 2.0, 3.0, 1.0};
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glTranslatef(0.0,1.5,-4.5);
	glColor3f(1.0,1.0,1.0); 
	glRotatef(xRotate,1.0,0.0,0.0);
	glRotatef(yRotate,0.0,1.0,0.0);
	glRotatef(zRotate1,0.0,0.0,1.0);
	glScalef(1.0,1.0,1.0);
	glutSolidCone(base,height,slices,stacks);
	glFlush();
} 

void reshapeCone(int x, int y)
{
	if (y == 0 || x == 0) return;
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();

	gluPerspective(70.0,(GLdouble)x/(GLdouble)y,0.5,20.0);

	glViewport(0,0,x,y);  
}

void idleCone(void)
{
 
	zRotate1 += 0.1;
	zRotate2 += 0.1;
	displayCone();
}

void main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cone Rotate");
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	xRotate=90;
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(displayCone);
	glutReshapeFunc(reshapeCone);
	glutIdleFunc(idleCone);
	glutMainLoop();
	return;
}