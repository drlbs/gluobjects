

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glLoadIdentity();
}

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glLoadIdentity();   // Call this before setting the viewing position 

   // We are going to set our position to be down the Y-Axis looking at the
   // center of the coordinate frame.  The positive Z-Axis will be up.

   gluLookAt( 20.0,   0.0, 5.0,  // Eye
               0.0,   0.0, 0.0,  // Center
               0.0,   0.0, 1.0); // Up

   
   glEnable(GL_DEPTH_TEST);

   glColor3f(0.0,1.0,0.0);
   

      // Set up my global coordinate system for drawing
      // Be sure to draw within my clipping planes! (check gluPerspective)

      // Try commenting out each of the following lines independently to see how
      // it changes the scene 
      /*
      glTranslated(0.0,0.0,4.0);    
      glRotated(90.0,0,1,0);
      glRotated(90.0,1,0,0);
      glRotated(90.0,0,1,0);
      */


      // This should be to draw the vertical support
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

      // This should draw a doughnut 
      glPushMatrix();
      glRotated(90.0,0,1,0);
      glColor3f (0.0,1.0,0.0);
      gluDisk(gluNewQuadric(), 
             (GLdouble) 0.1,
             (GLdouble) 1.0,
             (GLint) 10,
             (GLint)    20 );
      glPopMatrix();


      glFlush();
      
  glFlush ();
  }
}

#endif

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

#endif
