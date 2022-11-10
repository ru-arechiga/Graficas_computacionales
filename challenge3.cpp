// First Program in OpenGL
// Compile with:
// g++ challenge3.cpp -o challenge3 -lglut -lGLU -lGL
// Run with:
// ./challenge3

#include <iostream>
#include <GL/glut.h>
// (or others, depending on the system in use)

using namespace std;

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);    // Set display-window color to white.
    glMatrixMode (GL_PROJECTION);         // Set projection parameters.
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);  //coordinate limits for the picture we want to display.
}
void lineSegment (void)
{
    glClear (GL_COLOR_BUFFER_BIT);        // Clear display window.

    int x1, x2, y1, y2, dx, dy, x, y;
  
    cout<<"Introduce el valor X del PRIMER punto: ";
    cin>>x1;
    cout<<"Introduce el valor Y del PRIMER punto: ";
    cin>>y1;
    cout<<"Introduce el valor X del SEGUNDO punto: ";
    cin>>x2;
    cout<<"Introduce el valor Y del SEGUNDO punto: ";
    cin>>y2;

    dx = x2 - x1;
    dy = y2 - y1;

    for(x = x1; x < x2+1; x++){
        y = y1 + dy * (x - x1) / dx;
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }

    glColor3f (0.0, 0.4, 0.2);            // Set line segment color to green.
    glBegin (GL_LINES);
      glVertex2i (x1, y1);                 // Specify line-segment geometry.
      glVertex2i (x2, y2);
    glEnd ( );
    glFlush ( );                    // Process all OpenGL routines as quickly as possible.
}

void points (void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin (GL_POINTS);
    for (int i = 0; i<400; i+=5)
      glVertex2i (i, i);
    glEnd ();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);    // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);    // Set display mode.
    glutInitWindowPosition (50, 100);    // Set top-left display-window position.
    glutInitWindowSize (400, 400);    // Set display-window width and height.
    glutCreateWindow ("An Example OpenGL Program"); // Create display window.
    init (); // Execute initialization procedure.
    glutDisplayFunc(lineSegment);    // Send graphics to display window.
    //glutDisplayFunc (points);
    glutMainLoop ( );    // Display everything and wait.
    return 0;
}
