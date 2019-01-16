
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init(void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
}

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt( 20.0,   5.0, 5.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up


    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);

    // This should be to draw a cylinder 
    glPushMatrix();
    glTranslated(2.0,0.0,0.0);    
    glTranslated(0.0,0.0,0.0);    
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

    // This should draw a green doughnut 
    glPushMatrix();
    glRotated(90.0,0,1,0);
    glTranslatef(2.0,0.0,0.0);
    glColor3f (0.0,1.0,0.0);
    gluDisk(gluNewQuadric(), 
            (GLdouble) 0.5,
            (GLdouble) 1.0,
            (GLint)     10,
            (GLint)     20 );
    glPopMatrix();

    // This should draw a red sphere 
    glPushMatrix();
    glTranslatef(-3.0,1.0,1.0);
    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(), 
             (GLdouble) 1.5,
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();


    glFlush();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutReshapeFunc(reshape); 
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;
}


