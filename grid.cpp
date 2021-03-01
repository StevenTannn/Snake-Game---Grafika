#include <GL/glut.h>
#include "grid.h"
#include <GL/gl.h>
#include <ctime>
#include <stdlib.h>


extern bool gameOver;

extern int value;

int gridX,gridY;

extern int foodX,foodY;

int posX[60]={20,20,20,20,20},posY[60]={20,19,18,17,16};

void initGrid(int x, int y)
{
	gridX=x;
	gridY=y;	
}


void unit(int,int);
void drawGrid()
{
	for(int x=0;x<gridX;x++)
	{
		for(int y=0;y<gridY;y++)
		{
			unit(x,y);
		}
	}
}

void unit(int x,int y)
{
//	glLineWidth(1.0);
//	glColor3f(1.0,1.0,1.0);
	
	if(x==0 || y==0 || x==gridX-1 || y==gridY-1)
	{
		glLineWidth(3.0);
		if (value == 1){
			glColor3f(0.9,0.9,0.2);
		}
		else if (value == 2){
			glColor3f(1.0,0.6,0.0);	
		}
		else if (value == 3){
			glColor3f(1.0,0.0,0.0);
		}
	}
	else
	{
		glLineWidth(1.0);
		if (value == 1){
			glColor3f(1.0,1.0,1.0);
		}
		else if (value == 2){
			glColor3f(1.0,0.9,1.0);	
		}
		else if (value == 3){
			glColor3f(0.2,0.1,0.8);
		}
	}
		
	glBegin(GL_LINE_LOOP);
		glVertex2f(x,y);
		glVertex2f(x+1,y);
		glVertex2f(x+1,y+1);
		glVertex2f(x,y+1);
	glEnd();
}

