#include<cstdio>
#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
using namespace std;

#define sign(x) ((x>0)?1:((x<0)?-1:0))

int x1g, x2g, y2g, y1g;
void setPixel(GLint x, GLint y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}


void bres(int x1, int y1, int x2, int y2)
{
  int dx, dy, x, y, d, s1, s2, swap=0, temp;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);


  if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}


  d = 2 * dy - dx;
  x = x1;
  y = y1;

  int i;
  setPixel(x1, y1);
  setPixel(x2, y2);
  for(i = 1; i <= dx; i++)
  {
    if(i%9 > 4)
    setPixel(x,y);

    while(d >= 0)
    {
      if(swap) x = x + s1;
      else
      {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
  }
  glFlush();
}


void draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);


  bres(x1g, y1g, x2g, y2g);
  glFlush();
}

void init() {
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Green Window");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0,640,0,480);

}

int main(int argc, char **argv)
{

  cout<<"Enter coordinates of first point:\n";
  cin>>x1g>>y1g;
  cout<<"Enter coordinates of second point:\n";
  cin>>x2g>>y2g;
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
