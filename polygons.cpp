//Rodolfo Arechiga (A01634610)
//Compilar con:
//g++ polygons.cpp -o polygons -lglut -lGLU -lGL
//./polygons

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double TWO_PI = 6.2831853;

int n = 6;
double m = 6.0;

GLsizei winWidth = 400, winHeight = 300; // Initial display-window size.
GLuint regHex;
GLdouble theta;
GLint k;

class screenPt
{
private:
    GLint x, y;
public:
    /* Default Constructor: initializes coordinate position to (0, 0).*/
    screenPt ( ) {
	x = y = 0;
    }
    void setCoords (GLint xCoord, GLint yCoord) {
	x = xCoord;
	y = yCoord;
    }
    GLint getx ( ) const {
	return x;
    }
    GLint gety ( ) const {
	return y;
    }
};

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
}

void displayFcn (void)
{
    glClear (GL_COLOR_BUFFER_BIT);  //Clear display window.
    glColor3f (1.0, 0.0, 0.0);      //Set point color to red.
    glPointSize (3.0);              //Set point size to 3.0.
}

void winReshapeFcn (GLint newWidth, GLint newHeight)
{
    /* Reset viewport and projection parameters */
    glViewport (0, 0, newWidth, newHeight);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ( );
    gluOrtho2D (0.0, GLdouble (newWidth), 0.0, GLdouble (newHeight));
    // Reset display-window size parameters.
    winWidth = newWidth;
    winHeight = newHeight;
}

void regHexagon (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    screenPt hexVertex, circCtr;
    circCtr.setCoords (winWidth / 2, winHeight / 2);
    srand((unsigned)time(NULL));
    glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);  // Set fill color for hexagon to red.
    glBegin (GL_POLYGON);
    for (k = 0; k < 5; k++) {
	    theta = TWO_PI * k / 5.0;
	    hexVertex.setCoords (circCtr.getx ( ) + 150 * cos (theta),
		circCtr.gety ( ) + 150 * sin (theta));
	    glVertex2i (hexVertex.getx ( ), hexVertex.gety ( ));
    }
    glEnd ( );
    glFlush ( );
}


void plotPoint ()
{
    if(n == 13 && m == 13){
        n = 5;
        m = 5.0;
    }

    glClear (GL_COLOR_BUFFER_BIT);
    screenPt hexVertex, circCtr;
    circCtr.setCoords (winWidth / 2, winHeight / 2);
    srand((unsigned)time(NULL));
    glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);  // Set fill color for hexagon to red.
        glBegin (GL_POLYGON);
        for (k = 0; k < n; k++) {
	        theta = TWO_PI * k / m;
	        hexVertex.setCoords (circCtr.getx ( ) + 150 * cos (theta),
		    circCtr.gety ( ) + 150 * sin (theta));
	        glVertex2i (hexVertex.getx ( ), hexVertex.gety ( ));
        }
        n = n + 1;
        m = m + 1.0;
        glEnd ( );
}

void mousePtPlot (GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
    plotPoint();
    glFlush ( );
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Mouse Plot Points");
    init ( );
    glutDisplayFunc (regHexagon);
    glutReshapeFunc (winReshapeFcn);
    glutMouseFunc (mousePtPlot);
    glutMainLoop ( );
    return 0;
}