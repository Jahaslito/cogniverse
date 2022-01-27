#include <cstdio>
#include <cstdlib>
#include <GL/glut.h>
#include <cmath>
#include <cstring>
#include <shellapi.h>
#include "bmpLoader.h"
//#include "video.html"

int flag=0;
void *currentfont;
unsigned int ID[100];

void setFont(void *font)
{
    currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
    char *c;
    int len = (int) strlen(string);
    int i;
    glRasterPos3f(x,y,z);
    /*for(c=string;*c!='\0';c++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,*c);
    }*/
    for(i = 0;i<len;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,string[i]);
    }
}

void frontscreen()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0,0,1);
    drawstring(20.0-50,90.0,0.0,"Team 2");
    glColor3f(1,0.5,0);
    drawstring(38-50,70,0.0,"A MINI PROJECT ON");
    glColor3f(1,0,0);
    drawstring(40-50,60,0.0,"Cogniverse");
    glColor3f(1,0.5,0);
    drawstring(20-50,50,0.0,"BY:");
    glColor3f(0.5,0,0.5);
    drawstring(10-50,40,0.0,"Jafer Hassan      108130");
    glColor3f(0.5,0,0.5);
    drawstring(10-50,34,0.0,"Tony Mogoa              116814");
    glColor3f(0.5,0,0.5);
    drawstring(10-50,28,0.0,"Victoria Nyamai      116889");
    glColor3f(0.5,0,0.5);
    drawstring(10-50,22,0.0,"Joan Waweru              122466");
//    glColor3f(1,0.5,0);
//    drawstring(68-50,50,0.0,"GUIDES:");
//    glColor3f(0.5,0.2,0.2);
//    drawstring(63-50,40,0.0,"GUIDE NAME FIRST");
//    drawstring(63-50,34,0.0,"GUIDE NAME SECOND");
    glColor3f(1,0.1,1);
    drawstring(32-50,10,0.0,"PRESS ENTER TO START");
    glutSwapBuffers();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);//top
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//bottom
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);//front
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(100.0, 100.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//back
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);//left
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);//right
    glVertex3f(100.0, 100.0, 100.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 100.0);
    glEnd();

    gluLookAt(1,1,1,0,0,0,0,1,0);

    glFlush();
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
        frontscreen();
    if(flag==1)
        display();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch(key)
    {
        case 13:if(flag==0) //Ascii of 'enter' key is 13
                flag=1;
            break;
    }
    mydisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-100.0,100.0,-100.0,100.0,-50.0,50.0);
}

void LoadTexture(const char*filename, int index)
{
    glGenTextures(1, &ID[index]);
    glBindTexture(GL_TEXTURE_2D, ID[index]);
    printf("%d\n",ID[index]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID[index]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Cogniverse");
    // glutDisplayFunc(display);
    //LoadTexture("C:\\Users\\JOAN\\Desktop\\2022 Vision Board\\1bmp.bmp",1); //splashscreen
    glutDisplayFunc(mydisplay);
    //glutReshapeFunc(reshape);
    glutKeyboardFunc(myKeyboardFunc);
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}