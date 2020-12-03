#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<unistd.h>

#define PI 3.1415927
GLfloat xRotated, yRotated, zRotated;
GLdouble radius;
float xinc,yinc,zinc;
int count=0;
// void timer(int)
// {
//     glutPostRedisplay();
//     glutTimerFunc(1000/60,timer,0);
// }

static double sx = 0.0;
static double sy = 0.0;
static double sz = 0.0;
 
void special_keys(int key, int x, int y) 
{
    if (key == GLUT_KEY_RIGHT) {
    count++;
    glutPostRedisplay();
  }
}

void cut(void)
{
 //glClear(GL_COLOR_BUFFER_BIT);
 glBegin (GL_LINES);
 glColor3f(1.0,0.0,0.0);
 glVertex3f( -1, 0.0, 0.0);
 glVertex3f(-1+sx, 0.0+sy, 0.0+sz);    //-1+2, 0.0-1.8, 0.3 new points
 
 glEnd();
 //glFlush();
}

void timer_function( int value)
{
 static bool flag = true ;
 static int count = 0;
 if ( count == 100 )
 {
 flag=false;
 }
 
 
 if (flag )
 {
 sx += 0.02;
 sy -= 0.018;
 sz += 0.003;
 count++;
 }
 else
 {

 }
 glutPostRedisplay();
 glutTimerFunc( 200,timer_function , 0);
}

void knife()
{
    glTranslatef(-1,0.8,0);
    glBegin(GL_POLYGON);
glColor3f(0.1, 0.3, 0.3);
glVertex3f(-0.2+sx, 0+sy, 0+sz);
glVertex3f(-1+sx, 0+sy, 0+sz);
glVertex3f(0+sx, -0.5+sy, 0+sz);
// glEnd();
// glBegin(GL_POLYGON);
glVertex3f(0+sx,0.3+sy,0.3+sz);
glVertex3f(0.5+sx,0.3+sy,0.3+sz);
glVertex3f(0.5+sx,0.1+sy,0.3+sz);
glVertex3f(0.1+sx,0.1+sy,0.3+sz);

glEnd();
}




void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}

void drawcircle(float x,float y,float z,GLfloat xRotated,GLfloat yRotated,GLfloat zRotated,GLubyte R,GLubyte G,GLubyte B,GLdouble radius)
{


    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    //glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(x,y,z);
    // Red color used to draw.
    glColor3ub(R-40,G-40,B-40); 
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    glutSolidSphere(radius,20,20);
    // Flush buffers to screen
     
    //glFlush();        
    // sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}
void leg()
{

    draw_cylinder(0.2, 2.0, 255, 160, 100);
    drawcircle(0.3,-0.8,-5.0,30,30,30,255,160,100,0.4);
    drawcircle(0.28,-0.2,-5.0,30,30,30,255,160,100,0.45);
    drawcircle(0.28,-0.4,-5.0,30,30,30,255,160,100,0.45);
    //toes
    drawcircle(0.3,0.3,-5.0,30,30,30,255,160,100,0.09);             //third low
    drawcircle(0.3,0.35,-5.0,30,30,30,255,160,100,0.09);            //third mid
    drawcircle(0.3,0.43,-5.0,30,30,30,255,160,100,0.09);            //third up
    drawcircle(0.49,0.25,-5.0,30,30,30,255,160,100,0.08);           //forth low
    drawcircle(0.5,0.35,-5.0,30,30,30,255,160,100,0.08);           //forth up
    drawcircle(0.5,0.2,-5.0,30,30,30,255,160,100,0.08);            //forth mid
    drawcircle(0.64,0.1,-5.0,30,30,30,255,160,100,0.065);         //fifth low
    drawcircle(0.64,0.16,-5.0,30,30,30,255,160,100,0.065);         //fifth mid
    drawcircle(0.65,0.21,-5.0,30,30,30,255,160,100,0.065);         //fifth up
    drawcircle(0.11,0.2,-5.0,30,30,30,255,160,100,0.1);            //second low 
    drawcircle(0.11,0.3,-5.0,30,30,30,255,160,100,0.1);             //second mid
    drawcircle(0.1,0.4,-5.0,30,30,30,255,160,100,0.1);              //second up
    drawcircle(-0.08,0.04,-5.0,30,30,30,255,160,100,0.11);         //first super low
    drawcircle(-0.08,0.1,-5.0,30,30,30,255,160,100,0.11);          //first low
    drawcircle(-0.1,0.21,-5.0,30,30,30,255,160,100,0.11);          //first mid
    drawcircle(-0.1,0.3,-5.0,30,30,30,255,160,100,0.11);           //first up
}
 

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,-0.4,-3.0);
    glRotatef(-40, 0.0, 1.0, 0.0);

    if(count==0)
        leg();
    else if(count==1)
    {
        leg();
        knife();
        cut();
    }
    else if(count==2)
    {
        leg();
    }
    else
    {
        exit(0);
    }
    

    glFlush();
}

void reshape(int width, int height)
{
    if (width == 0 || height == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width/(GLdouble)height,
                   0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);   
    glViewport(0, 0, width, height);
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Create Cylinder");
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,1.0,0.0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special_keys);
    glutTimerFunc (1, timer_function,0);
    glutMainLoop();
    return 0;
}