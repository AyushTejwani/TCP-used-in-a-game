#include <GL/glut.h>
#include<stdio.h>
int c = 0;
void init()
{

glClearColor(0, 1, 1, 0);

glMatrixMode(GL_PROJECTION);

gluOrtho2D(0, 800, 0,600);
}
int a=800,b=800;
void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
int v=0,h=0;

if (c == 0)
{
glColor3f(1, 1, 1); 
c = 1;
}

else
{
glColor3f(0, 0, 0);
c = 0;
}

// Draw Square
glBegin(GL_POLYGON);
glVertex2i(x1, y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4, y4);
glEnd();
}
void chessboard()
{
glClear(GL_COLOR_BUFFER_BIT); 
   

 GLint x, y;
char ch;
int v=0,h=0;
char prev;
label:
printf("");
FILE *fp;
fp = fopen("save.txt", "r");
 
	ch=fgetc(fp);	
  //printf("%d", ch);
	

if(prev!=ch )
	{
	//printf("asd");
  	switch(ch)
  	{
  		case 's':
  		{
  			v=v-75;
			//printf("this is W");
  			break;
  		}
  		case 'a':
  		{
  			h=h-100;
			
			//printf("this is A");
  			break;
  		}
  		case 'w':
  		{
  			v=v+75;
			
			//printf("this is S");
  			break;
  		}
  		case 'd':
  		{
  			h=h+100;
			
			//printf("this is D");
			break;
  		}
  		
  	}

 }
   fclose(fp);


prev=ch;
 x=0+h,y=75+v;
drawSquare(x, y + 75, x + 100, y + 75, x + 100, y, x, y);

glFlush();
goto label;
}
int main(int agrc, char ** argv)
{

glutInit(&agrc, argv);

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowPosition(100, 100);

glutInitWindowSize(800, 600);

glutCreateWindow("Game using OpenGL in C++");

init();

glutDisplayFunc(chessboard);

glutMainLoop();
}
