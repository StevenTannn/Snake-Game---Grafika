#include <GL/glut.h>
#include "snake.h"
#include <GL/gl.h>

extern bool gameOver;

extern int value;

extern int gridX,gridY;

extern int foodX,foodY;

extern bool food;

extern int score;

int snake_length = 5;

short sDirection = RIGHT;

extern int posX[60],posY[60];

void drawSnake()
{
	for(int i =snake_length-1;i>0;i--)
	{
		posX[i]=posX[i-1];
		posY[i]=posY[i-1];
	}
	if(sDirection==UP)
		posY[0]++;
	else if(sDirection == DOWN)
		posY[0]--;
	else if (sDirection == LEFT)
		posX[0]--;
	else if (sDirection == RIGHT)
		posX[0]++;
	for (int i =0;i< snake_length ;i++){
		if (i==0){
			if (value == 1){
				glColor3f(0.0,1.0,0.0);	
			}
			else if (value == 2){
				glColor3f(1.0,0.5,0.0);
			}
			else if (value == 3){
				glColor3f(0.0,1.0,1.0);
			}
		}
		else{
			if (value == 1){
				glColor3f(1.0,1.0,1.0);	
			}
			else if (value == 2){
				glColor3f(1.0,0.9,1.0);
			}
			else if (value == 3){
				glColor3f(0.2,0.5,0.5);
			}
			
		}
		glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
	}
	if(posX[0]==0 || posX[0] ==gridX-1 || posY[0]==0 || posY[0]==gridY-1){
		gameOver=true;
	}
	if(posX[0]==foodX && posY[0]==foodY){
		 
		score++;
		snake_length++;
		if(snake_length>MAX)
			{
				snake_length = MAX;
			}
		food=true;
	}
	for(int j=1;j<snake_length;j++){
		if(posX[j]==posX[0] && posY[j]==posY[0]){
			gameOver=true;
		}
	}
}
