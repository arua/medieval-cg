#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>

#include "macros.h"
#include "cenario.h"
#include "texturas.h"

static GLUquadricObj *obj;
static float angX = 15;
static float angY = 0;
static float moonHeight = 12.0;

float x[NUM_TREES], y[NUM_TREES];

void initCenario(){
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj,GLU_FILL);
    float xRange;
    int spreadTrees = (NUM_TREES/100 + 1)*20;
	range(i, 0, NUM_TREES){
		y[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*320;
		xRange=(powf(y[i],2.0f)/8.0f)/100.0f;
        x[i] = ((2 * (float)rand() / (float)RAND_MAX - 1)*(xRange+70));
        printf("%f, %f\n",xRange,y[i]);
    }
	
    /*range(i, 0, NUM_TREES/4){
        x[i] = ((2 * (float)rand() / (float)RAND_MAX - 1)*spreadTrees)-1.5*spreadTrees;
        y[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*140 - 180;
    }
    range(i, NUM_TREES/4, NUM_TREES/2){
        x[i] = ((2 * (float)rand() / (float)RAND_MAX - 1)*spreadTrees)-1.5*spreadTrees;
        y[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*140 + 180;
    }
    range(i, NUM_TREES/2, 3*NUM_TREES/4){
        x[i] = ((2 * (float)rand() / (float)RAND_MAX - 1)*spreadTrees)+1.5*spreadTrees;
        y[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*140 - 180;
    }
    range(i, 3*NUM_TREES/4, NUM_TREES){
        x[i] = ((2 * (float)rand() / (float)RAND_MAX - 1)*spreadTrees)+1.5*spreadTrees;
        y[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*140 + 180;
    }*/
}

void drawBranches(float x, float y){
    transform({
        glScalef(10,10,10);
        glRotatef(-90,1.0,0.0,0.0);
        glTranslatef(x,y,-30.0);
    	glColor3f(0,0.5,0);
    	glutSolidCone(2,7,20,20);
    });
}

void drawTrunk(float x, float y){
    transform({  
        glScalef(10,10,10);
    	glRotatef(-90,1.0,0.0,0.0);
        glTranslatef(x,y,-35.0); 
    	glColor3f(0.5,0.35,0.05);
    	gluCylinder(obj,0.5,0.5,5,20,20);
    });
}

void cenario(){
    transform({
        glColor3f(0.7,0.7,0.7);
        //glScalef(50,50,50);          
        /*transform({
            glTranslatef(10.0,moonHeight,7.0);
            glutSolidSphere(1.5,50,50);
        });*/
        transform({//desenha chão
            glColor3f(0,0.6,0);
            glTranslatef(0,-355,0);
            //glScalef(4,0.001,2);
            //glutSolidCube(3200);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glEnable ( GL_TEXTURE_2D );
            glBindTexture(GL_TEXTURE_2D, texturesID[GRAMA]);
            glBegin(GL_QUADS);
            
				glNormal3f(-1.0, 0.0, 0.0);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-3200.0f, 0.0f, -3200.0f);
				glTexCoord2f(0.0f, 7.0f); glVertex3f(-3200.0f, 0.0f, 3200.0f);
				glTexCoord2f(7.0f, 7.0f); glVertex3f(3200.0f, 0.0f, 3200.0f);
				glTexCoord2f(7.0f, 0.0f); glVertex3f(3200.0f, 0.0f, -3200.0f);

			glEnd();
			glDisable ( GL_TEXTURE_2D );
        });
        transform({//desenha rio
            glColor3f(0,0,1);
            glTranslatef(0,-345,0);
            glScalef(0.2,0.003,8);
            glutSolidCube(800);
        });
        int i;
        for(i=0;i<NUM_TREES; i++){
        	drawTrunk(x[i], y[i]);
        }
        for(i=0;i<NUM_TREES; i++){
        	drawBranches(x[i], y[i]);
        }
    });
}

void giraCenario(int value){
	angY +=1;
    glutPostRedisplay();
    glutTimerFunc(100,giraCenario,0);
}

void sobeLua(int value);

void desceLua(int value){
	moonHeight -=0.1;
    //glutPostRedisplay();
    if (value < 300)
    	glutTimerFunc(20,desceLua,value+1);
    else
    	glutTimerFunc(20,sobeLua,0);
}

void sobeLua(int value){
	moonHeight +=0.1;
    //glutPostRedisplay();
    if (value < 300)
    	glutTimerFunc(20,sobeLua,value+1);
    else
    	glutTimerFunc(15000,desceLua,0);
}

void transformacoes(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
           angX+=15;
           break ;
        case GLUT_KEY_DOWN :
           angX-=15;
           break ;
        case GLUT_KEY_LEFT :
           angY-=15;
           break ;
        case GLUT_KEY_RIGHT :
           angY+=15;
           break;
        default:
           break;
     }
     glutPostRedisplay() ;
}

/*int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<100; i++){
		x[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*40;
    	y[i] = (2 * (float)rand() / (float)RAND_MAX - 1)*40;
	}
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Objetos 3D - OpenGL");
     glutDisplayFunc(display);
     glutTimerFunc(500,giraCenario,0);
     glutTimerFunc(15000,desceLua,0);
     glutSpecialFunc(transformacoes);
     init();
     glutMainLoop();
}*/
