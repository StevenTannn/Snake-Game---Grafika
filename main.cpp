#include <GL/gl.h>
#include <GL/glut.h>
#include "grid.h"
#include "snake.h"
#include "food.h"
#include <stdlib.h>

#define COLUMNS 40
#define ROWS 40

extern int snake_length;

int posXa[60]={20,20,20,20,20},posYb[60]={20,19,18,17,16};

extern int foodX,foodY;

int FPS = 8;

extern short sDirection;

bool gameOver=false;

int score=0;

void display_callback();

void render();

bool restart = false;

void reeshape_callback(int w,int h);

void timer_callback(int);

int win;

int value=0;

static int submenu_id;

static int menu_id;

void keyboard_callback(int,int,int);

void init() 
{
	glClearColor(0.0,0.0,0.0,1.0); 
	initGrid(COLUMNS,ROWS);
}

void drawBitmapText(char *string,float xa,float yb,float zc) 
{  
	char *c;
	glRasterPos3f(xa, yb,zc);
	
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

void menu(int num){
	value=num;
	glutPostRedisplay();
}

void createMenu(void){   
    drawBitmapText((char*)"WELCOME",-0.2,0.3,0);
    drawBitmapText((char*)"TO",-0.1,0.2,0);
    drawBitmapText((char*)"SNAKE",-0.15,0.1,0);
    drawBitmapText((char*)"GAME",-0.15,0,0);
    drawBitmapText((char*)"KLIK KANAN PADA MOUSE UNTUK MENU",-0.6,-0.1,0);
    drawBitmapText((char*)"DEVELOP BY : ANDIKA, FARANDI, STEVEN",-0.6,-0.8,0); 
    submenu_id=glutCreateMenu(menu);
	glutAddMenuEntry("LEVEL 1 (EASY)", 1);
    glutAddMenuEntry("LEVEL 2 (MEDIUM)", 2);
    glutAddMenuEntry("LEVEL 3 (HARD)", 3);
	menu_id=glutCreateMenu(menu);
	glutAddSubMenu("PLAY GAME",submenu_id);
    glutAddMenuEntry("QUIT", 4);     
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char** argv)
{
		glutInit(&argc,argv); 
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 
		glutInitWindowSize(800,800); 
		glutCreateWindow("SNAKE GAME BY 18TI2(ASF)"); 
		createMenu();
		glutDisplayFunc(display_callback);
		glutReshapeFunc(reeshape_callback); 
		glutTimerFunc(0,timer_callback,0);
		//glutKeyboardFunc(keyboard_callback); 
		glutSpecialFunc(keyboard_callback);
		init();
		glutMainLoop(); 
		return 0;	
	
}

//int index=0;
void display_callback()
{
	if(value==1){
		glClear(GL_COLOR_BUFFER_BIT); 
		drawGrid();
		drawSnake();
		drawFood();
		char _score[10];
		itoa(score,_score,10);
		char text[50] = "Your Score : ";
		char text1[50] = "[EASY]";	
		strcat (text,_score); 
		glColor3f(1,0.7,0.3);
		drawBitmapText((char*)text,0,0,0);
		drawBitmapText((char*)text1,0,39,0); 
	}
	else if(value==2){
		glClear(GL_COLOR_BUFFER_BIT); 
		drawGrid();
		drawSnake();
		drawFood();
		char _score[10];
		itoa(score,_score,10);
		char text[50] = "Your Score : ";
		char text1[50] = "[MEDIUM]";	
		strcat (text,_score); 
		glColor3f(0.9,1,0.1);
		drawBitmapText((char*)text,0,0,0);
		drawBitmapText((char*)text1,0,39,0);  
	}
	else if(value==3){
		glClear(GL_COLOR_BUFFER_BIT); 
		drawGrid();
		drawSnake();
		drawFood();
		char _score[10];
		itoa(score,_score,10);
		char text[50] = "Your Score : ";
		char text1[50] = "[HARD]";
		strcat (text,_score); 
		glColor3f(1,0.9,1);
		drawBitmapText((char*)text,0,0,0); 
		drawBitmapText((char*)text1,0,39,0); 
	}
	else if (value==4){
		exit(0);
	}
	glutSwapBuffers();
	if(gameOver)
	{
		char _score[10];
		itoa(score,_score,10);
		char text[50] = "Your Score : ";
		strcat (text,_score); 
		const int result = MessageBox(NULL,text,"GAMEOVER", MB_ICONINFORMATION|MB_OK);
		exit(0);
		//switch (result){
		//	case IDYES:
		//		glutDestroyWindow(win);
		//		break;
		//	case IDNO:
		//		exit(0);
		//		break;
		//}
	}
}

void reeshape_callback(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity(); 
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
	glutPostRedisplay();
	if (value == 1){
		FPS=8;
	}
	else if (value == 2){
		FPS=10;
	}
	else if (value == 3){
		FPS=12;
	}
	for (int z =5;z<snake_length ;z++){
		FPS+1;
	}
	glutTimerFunc(1000/FPS,timer_callback,0);
}


void keyboard_callback(int press, int,int)
{
	switch(press)
	{
		case GLUT_KEY_UP:
			if(sDirection != DOWN)
				sDirection = UP;
			break;	
		case GLUT_KEY_DOWN:
			if(sDirection != UP)
				sDirection = DOWN;
			break;
		case GLUT_KEY_LEFT:
			if(sDirection != RIGHT)
				sDirection = LEFT;
			break;
		case GLUT_KEY_RIGHT:
			if(sDirection != LEFT)
				sDirection = RIGHT;
			break;
	}	
}

