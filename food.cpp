#include <GL/glut.h>
#include "food.h"
#include <GL/gl.h>
#include <ctime>
#include <stdlib.h>

extern bool gameOver;

extern int value;

extern int gridX,gridY;
int foodX,foodY;
bool food=true;
extern int snake_length;

extern int posX[60],posY[60];

void drawFood(){
	for(int j=1;j<snake_length;j++){
		if(posX[j]==posX[0] && posY[j]==posY[0]){
			random(foodX,foodY);
		}
	}
	if(food)
		random(foodX,foodY);
	glColor3f(1.0,0.1,0.6);  
	food=false;
	glRectf(foodX,foodY,foodX+1,foodY+1);
}


void random(int &x, int&y){
	int _maxX = gridX-2;
	int _maxY = gridY-2;
	int _min = 1;
	srand(time(NULL));
	x = _min + rand() % (_maxX - _min);
	y = _min + rand() % (_maxY - _min);
}

