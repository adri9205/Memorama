/*

Adriana Cortés Soto A01034348

Gráficas Computacionales
Maestra: Guadalupe Roque

*/
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600


using namespace std;
bool active=false;
int opcion=2;
bool pause=false;
bool reset=false;
bool reactive=false;
int aba=0;
int aba2=0;
bool win=false;
GLfloat seg=0.0;
GLfloat mins=0.0;
GLfloat deci=0.0;
GLfloat turns=0.0;
typedef enum {FONDO1,FONDO2,FONDO3,FONDO4,FONDO5};
int arr1[17]={6,2,5,1,7,3,4,0,5,2,1,0,3,7,4,6};
GLfloat arrDim[16];
GLfloat arrDim2[16]={1.36,2.58,3.8,5.02,6.18,7.36,8.62,9.76};
GLfloat PosXO[17]={2.14,4.06,6.04,7.42,9.84,11.76,13.7,15.6,17.04};
GLfloat PoxXP[17]={2.22,4.24,6.24,8.24,10.26,12.24,14.2,16.2,17.68};
bool sel[20]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
bool arrboleado[20]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
bool ok[20]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};

void draw();
void reshape(int width, int height);
void init();
void keyboard(unsigned char, int, int);
void dibujaCrono();
void mouse(int boton, int state, int x, int y);
int j=0;
void timer(int i);
GLfloat color1=255;
GLfloat color2=0;
GLfloat color3=255;
GLfloat color01=255;
GLfloat color02=255;
GLfloat color03=0;
float x=1.0;
double mouseX;
double mouseY;
bool finish=false;
int c;
int contR=0;
int k;
void creacionMenu();
bool ver=false;
GLfloat contadorCartas=0;
int contWin=0;

void outputText(double x,double y,double z,double scale,char *s);

void myTimer(int v)
{
    x=x+1;
    glutPostRedisplay();
    glutTimerFunc(5, myTimer, 1);

}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(20, 20);
	glEnable(GL_DEPTH_TEST);
	glutCreateWindow("Memorama");
	glutDisplayFunc(dibujaCrono);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
	glutTimerFunc(25, timer, 0.1);
    glutTimerFunc(5, myTimer, 1);
	init();
	creacionMenu();
	glutMainLoop();

	return 0;
}

void onMenu(int opcion) {
	switch(opcion) {
case FONDO1:

	break;
case 2:
    active=true;
    win=false;
    finish=false;

	break;
case 3:
   active=!active;
	break;

	case 4: // Blanco 3
reset=true;
    active=false;
	break;
case 5:
exit(0);
	break;
	glutPostRedisplay();
}}

void creacionMenu(void) {
	int menuFondo, menuDibujo;
    menuDibujo = glutCreateMenu(onMenu);
   glutAddMenuEntry("Adriana Cortés ", 0);
	glutAddMenuEntry("Javier Yépiz", 0);

	menuFondo = glutCreateMenu(onMenu);

    glutAddSubMenu("Autores", menuDibujo);
    glutAddMenuEntry("Iniciar",1);
	glutAddMenuEntry("Pause",2);
	glutAddMenuEntry("Reset",3);
	glutAddMenuEntry("Salir",4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void timer(int extra)
{
if (active)
{
   deci+=1.0;
   if (deci==56){
    deci=0.0;
    seg+=6.0;
    if(seg == 360.0)
    {
	seg = 0.0;
	mins += 6.0;
	if(mins == 360.0)
	{
		mins = 0.0;}
    }}

    }

else {
if (reset){
    seg=0.0;
    mins=0.0;
    deci=0.0;
    contR=0;
    contWin=0;
    win=false;
    turns=0;
    for (int i=0; i<16; i++){
        arrboleado[i]=false;
        sel[i]=false;
        ok[i]=false;
    }
    int r;
    int t;
    for(int i=15; i>0; i--){
        r=rand()%16;
        t=arr1[i];
        arr1[i]=arr1[r];
        arr1[r]=t;
    }

    reset=false;
    active=false;
}

}
glutPostRedisplay();
glutTimerFunc(25, timer, 0.1);


}

void setX(double x)
{
    mouseX=x;
}

void setY(double y)
{
    mouseY=y;
}
void game(){
    if (opcion==1){


        for (int i=0; i<16; i++){
        if (mouseY<=18&&mouseY>=15){
        if ((mouseX>=PosXO[i])&&(mouseX<PosXO[i+1])){
                contR+=1;
                if (!ver){
                if (contR==1){
                    j=i;
                    arrboleado[j]=true;
                    sel[j]=true;
                }}
                if (ver){
                    j=c;
                    contR=1;
                    arrboleado[j]=true;
                    sel[j]=true;
                    ver=!ver;
                }

                if (contR==2){

                    if (j==i){
                        contR-=1;
                    }
                    else {
                        turns+=1;
                        arrboleado[i]=true;
                        sel[i]=true;
                        contR+=1;
                        if((arr1[j]==arr1[i])||(arr1[i]==arr1[j])){
                            contWin+=1;
                            sel[i]=false;
                            sel[j]=false;
                            ok[i]=true;
                            ok[j]=true;
                            contR=0;
                        }
                        if ((arr1[i]!=arr1[j])||(arr1[j]!=arr1[i])){

                            sel[j]=false;
                            arrboleado[j]=false;
                        contR=0;
                        c=i;
                        ver=true;
                        }

                        if (contWin==8){
                            win=true;

                        }
                    }
                }

                }}


        if (mouseY<=13&&mouseY>=8){

        if ((mouseX>=PosXO[i])&&(mouseX<PosXO[i+1])){

                contR+=1;
                if (!ver){
                if (contR==1){
                    j=i+8;
                    arrboleado[j]=true;
                    sel[j]=true;
                }}
                if (ver){
                    j=c;
                    contR=1;
                    arrboleado[j]=true;
                    sel[j]=true;
                    ver=!ver;
                }

                if (contR==2){

                    if (j==(i+8)){
                        contR-=1;
                    }
                    else {
                    turns+=1;
                        arrboleado[i+8]=true;
                        sel[i+8]=true;
                        contR+=1;
                        if((arr1[j]==arr1[i+8])||(arr1[i+8]==arr1[j])){
                            contWin+=1;
                            sel[i+8]=false;
                            sel[j]=false;
                            ok[i+8]=true;
                            ok[j]=true;
                            contR=0;
                        }
                        if ((arr1[i+8]!=arr1[j])||(arr1[j]!=arr1[i+8])){

                            sel[j]=false;
                            arrboleado[j]=false;
                            contR=0;
                            c=i+8;
                            ver=true;
                        }

                        if (contWin==8){
                            win=true;

                        }
                    }
                }

                }}}



    }
    else{


        for (int i=0; i<16; i++){
        if (mouseY<=18&&mouseY>=15){
        if ((mouseX>=PoxXP[i])&&(mouseX<PoxXP[i+1])){
                contR+=1;
                if (!ver){
                if (contR==1){
                    j=i;
                    arrboleado[j]=true;
                    sel[j]=true;
                }}
                if (ver){
                    j=c;
                    contR=1;
                    arrboleado[j]=true;
                    sel[j]=true;
                    ver=!ver;
                }

                if (contR==2){

                    if (j==i){
                        contR-=2;
                    }
                    else {
                        turns+=1;
                        arrboleado[i]=true;
                        sel[i]=true;
                        contR+=2;
                        if((arr1[j]==arr1[i])||(arr1[i]==arr1[j])){
                            contWin+=1;
                            sel[i]=false;
                            sel[j]=false;
                            ok[i]=true;
                            ok[j]=true;
                            contR=0;
                        }
                        if ((arr1[i]!=arr1[j])||(arr1[j]!=arr1[i])){

                            sel[j]=false;
                            arrboleado[j]=false;
                        contR=0;
                        c=i;
                        ver=true;
                        }

                        if (contWin==8){
                            win=true;

                        }
                    }
                }

                }}


        if (mouseY<=13&&mouseY>=8){

        if ((mouseX>=PoxXP[i])&&(mouseX<PoxXP[i+1])){

                contR+=1;
                if (!ver){
                if (contR==1){
                    j=i+8;
                    arrboleado[j]=true;
                    sel[j]=true;
                }}
                if (ver){
                    j=c;
                    contR=1;
                    arrboleado[j]=true;
                    sel[j]=true;
                    ver=!ver;
                }

                if (contR==2){

                    if (j==(i+8)){
                        contR-=1;
                    }
                    else {
                    turns+=1;
                        arrboleado[i+8]=true;
                        sel[i+8]=true;
                        contR+=1;
                        if((arr1[j]==arr1[i+8])||(arr1[i+8]==arr1[j])){
                            contWin+=1;
                            sel[i+8]=false;
                            sel[j]=false;
                            ok[i+8]=true;
                            ok[j]=true;
                            contR=0;
                        }
                        if ((arr1[i+8]!=arr1[j])||(arr1[j]!=arr1[i+8])){

                            sel[j]=false;
                            arrboleado[j]=false;
                            contR=0;
                            c=i+8;
                            ver=true;
                        }

                        if (contWin==8){
                            win=true;

                        }
                    }
                }

                }}}




    }
}

void mouse(int boton, int state, int xGLUT, int yGLUT)
{ double x=(double)xGLUT/50;
  int y =(int)(WINDOW_HEIGHT - yGLUT)/30;

  if (active){

    if(boton==GLUT_LEFT_BUTTON)
    {

        if (state==GLUT_DOWN){
        setX(x);
        setY(y);
        game();


        }
        glutPostRedisplay();
}
    }


}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 83:
    active=true;
    win=false;
    finish=false;
    PlaySound("Batman_Evolution_-_The_Piano_Guys.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


    break;
   case 115:
    active=true;
    win=false;
    finish=false;
    PlaySound("Batman_Evolution_-_The_Piano_Guys.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    break;
   case 100:
    active=!active;
    glutPostRedisplay();
    break;
    case 68:
    active=!active;
    glutPostRedisplay();
    break;
    case 82:
    reset=true;
    active=false;
    glutPostRedisplay();
    break;
   case 114:
    reset=true;
    active=false;
    glutPostRedisplay();
    break;
    case 'o':
        case 'O':
            opcion = 1;
            reshape(WINDOW_WIDTH,WINDOW_HEIGHT);
            glutPostRedisplay();
            break;
        case 'p':
        case 'P':
            opcion = 2;
            reshape(WINDOW_WIDTH,WINDOW_HEIGHT);
            glutPostRedisplay();
            break;

      	case 27:
         	exit(0);
         	break;
   }
}
char buff2[100];

void init()
{

}


void outputText(double x,double y,double z,double scale,char *s)
{
   int i;

   glPushMatrix();
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
   for (i=0;i<strlen(s);i++)
      glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
   glPopMatrix();
}


void dibujaCrono() {

char buff[100];
char b3[200];
char b4[100];
char b5[100];
char num[200];
char b10[200];
char nombre[200];
glClearColor(0.0, 0.0, 0.0, 0.0);
float medida = 50;
glEnable (GL_DEPTH);
glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
GLubyte itc[] = {
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE0,0x7C,0x00,
0x03,0xE3,0xFF,0x80,
0x03,0xE3,0xFF,0x80,
0x03,0xE3,0xFF,0x80,
0x03,0xE3,0xFF,0x80,
0x03,0xE3,0xFF,0x80,
0x03,0xE3,0xFF,0x80,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
    };



	if (!win){
    glColor3ub(255,255,255);
    sprintf(b3, "%s" , "S- Inicio  D-Pausa  R- Reset   Esc-Salir");
    outputText(0.0,2.3,0,0.006, b3);

    for(int i=0; i<16; i++){
    sprintf(num, "%2d", (int) arr1[i]);
    outputText(i,1.0,0,0.006, num);
    }

	sprintf(buff, "%2dm:%2.0fs.%2.0fms", (int)(mins/6), seg/6, deci/6);
	outputText(-0.1,6.0,0,0.006, buff);
    sprintf(b4, "Turnos::%2d", (int) turns);
	outputText(12.0,5.3,0,0.006, b4);
	glClearColor(1.0, 0.0, 1.0, 0.0);
	   char b7[100];

    double q=3;
	double q1=3;
	for (int i=0; i<16; i++){
    if (i<8){
    glColor3f (1.0, 1.0, 0.0);
    glPushMatrix();
	glTranslatef(q,17, 0);
	if(arrboleado[i]&&sel[i]){
    glRotatef(x, 0.0, 0.0, 1.0);
    glEnable (GL_POLYGON_STIPPLE);
    glColor3f (1.0, 1.0, 0.0);
    glPolygonStipple (itc);}
    if(ok[i]){

	glColor3f(0.0,0.0,1.0);}
	else{
      glColor3f(1.0,0.0,1.0);
	}
    glScaled(1.6, 3.0, 0.25);
    glutSolidCube(1);
    glColor3f (1.0, 1.0, 1.0);
    glutWireCube(1);                 // building
    glPopMatrix();
    q+=2;
    glDisable (GL_POLYGON_STIPPLE);
    }
    if (i>=8){
    glPushMatrix();
	glTranslatef(q1,11, 0);
	if(arrboleado[i]&&sel[i]){
    glRotatef(x, 0.0, 0.0, 1.0);
    glEnable (GL_POLYGON_STIPPLE);
    glColor3f (1.0, 1.0, 0.0);
    glPolygonStipple (itc);}
	if(ok[i]){

	glColor3f(0.0,0.0,1.0);}
	else{
      glColor3f(1.0,0.0,1.0);
	}
    glScaled(1.6, 3.0, 0.25);
    glutSolidCube(1);
    glColor3f (1.0, 1.0, 1.0);
    glutWireCube(1);                 // building
    glPopMatrix();
    q1+=2;
    glDisable (GL_POLYGON_STIPPLE);
    }
    }
char b11[200], b13[100];
    double o=1.3, o1=1.3, o2=1.3, o3=1.3;
    for (int i=0;i<8; i++){
            if (opcion==2){
            if ((arrboleado[i]&&sel[i])||ok[i]){
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o,16.0,0,0.01, b10);}//}
            o+=2;}
            else{
            if ((arrboleado[i]&&sel[i])||ok[i]){
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o1,16.0,0,0.01, b10);}
            o1+=2;}}

    for(int i=8; i<16; i++){
        if (opcion==2){
            if ((arrboleado[i]&&sel[i])||ok[i]){
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o3,10.0,0,0.01, b10);}//}
            o3+=2;}
            else{
            if ((arrboleado[i]&&sel[i])||ok[i]){
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o2,10.0,0,0.01, b10);}//}
            o2+=2;
            }
    }

	sprintf(nombre, "%s", "Adriana Cortes A01034348 Javier Yepiz A01034594");
	outputText(3,7.0,0,0.005, nombre);


	}

if (win){
    glColor3ub(255,255,255);
	sprintf(b5, "Felicidades! Lo lograste en %2d pasos", (int)(turns));
	outputText(2.0,6.0,0,0.005, b5);

	glPushMatrix();
	glTranslatef(10,5, 0);
	glScaled(1.5, 1.5, 1.5);
	glRotatef(x, 0.0, 0.0, 1.0);
	glColor3f(0.0,1.0,0.0);
    glutSolidCube(1);                 // building
    glPopMatrix();

    double q=3;
	double q1=3;
	for (int i=0; i<16; i++){
    if (i<8){
    glColor3f (1.0, 1.0, 0.0);
    glPushMatrix();
	glTranslatef(q,17, 0);
    glRotatef(x, 0.0, 0.0, 1.0);
    glEnable (GL_POLYGON_STIPPLE);
    glColor3f (1.0, 1.0, 0.0);
    glPolygonStipple (itc);

	glColor3f(1.0,0.0,1.0);
    glScaled(1.6, 3.0, 0.25);
    glutSolidCube(1);
    glColor3f (1.0, 1.0, 1.0);
    glutWireCube(1);                 // building
    glPopMatrix();
    q+=2;
    glDisable (GL_POLYGON_STIPPLE);
    }

    if (i>=8){
    glPushMatrix();
	glTranslatef(q1,11, 0);
    glRotatef(x, 0.0, 0.0, 1.0);
    glEnable (GL_POLYGON_STIPPLE);
    glColor3f (1.0, 1.0, 0.0);
    glPolygonStipple (itc);
	glColor3f(1.0,0.0,0.0);
    glScaled(1.6, 3.0, 0.25);
    glutSolidCube(1);
    glColor3f (1.0, 1.0, 1.0);
    glutWireCube(1);                 // building
    glPopMatrix();
    q1+=2;
    glDisable (GL_POLYGON_STIPPLE);
    }

    }

    double o=1.3, o1=1.3, o2=1.3, o3=1.3;
    for (int i=0;i<8; i++){
            //if (arrboleado[i]||ok[i]){


            if (opcion==2){
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o,16.0,0,0.01, b10);
            o+=2;}
            else{
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o1,16.0,0,0.01, b10);
            o1+=2;

            }}
           for (int i=8; i<16;i++){

            if (opcion==2){
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o3,10.0,0,0.01, b10);
            o3+=2;}
            else{
            sprintf(b10,"%2d", (int) arr1[i]);
            outputText(o2,10.0,0,0.01, b10);
            o2+=2;
            }
            }




}
	glutSwapBuffers();
}

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei) w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (opcion == 1){
    glOrtho(0, 20, 0, 20, 1, 20);}
    else{
      glFrustum(0, 20, 0, 20, 3, 40);
    }
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 3, 0, 0, 0, 0.0, 1.0, 0.0);

}


