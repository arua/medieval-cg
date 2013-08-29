#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "macros.h"
#include "cenario.h"
#include "texturas.h"

static GLUquadricObj *obj;

float tx1[NUM_TREES/2], tx2[NUM_TREES/2], ty1[NUM_TREES/2], ty2[NUM_TREES/2];

static inline double sig(double x, int i) {
    return i == 1 ? x : -x;
}

static inline double rndSig(double x) {
    return sig(x, rand()%2 + 1);
}

#define auxInit(id) macrofy(\
    range(i, 0, NUM_TREES/2){ \
        ty##id[i] = rndSig(((double)rand() / (double)RAND_MAX)*320); \
        xRange = (powf(ty##id[i],2.0f)/8.0f)/100.0f; \
        tx##id[i] = sig((((double)rand() / (double)RAND_MAX))*(xRange+50) + 20, id); \
        dprintf("%f, %f\n", tx##id[i], ty##id[i]); \
    })

void initCenario(){
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj,GLU_FILL);
    float xRange;
	auxInit(1);
    auxInit(2);
}

void drawBranches(float x, float y){
    transform({
        glScalef(10,10,10);
        glRotatef(-90,1.0,0.0,0.0);
    	glColor3f(0,0.5,0);
    	glTranslatef(x,y,-30.0);
        glutSolidCone(2,7,20,20);
    });
}

void drawTrunk(float x, float y){
    transform({ 
        glScalef(10,10,10);
    	glRotatef(-90,1.0,0.0,0.0);
    	glColor3f(0.5,0.35,0.05);
    	glTranslatef(x,y,-35.0);
        gluCylinder(obj,0.5,0.5,5,20,20);
    });
}

void cenario(){
    transform({
        glColor3f(0.7,0.7,0.7);
        transform({//desenha chão
            glColor3f(0,0.6,0);
            glTranslatef(0,-355,0);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glEnable ( GL_TEXTURE_2D );
            glBindTexture(GL_TEXTURE_2D, texturesID[GRAMA]);
            draw(GL_QUADS, {
				glNormal3f(-1.0, 0.0, 0.0);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-3200.0f, 0.0f, -3200.0f);
				glTexCoord2f(0.0f, 7.0f); glVertex3f(-3200.0f, 0.0f, 3200.0f);
				glTexCoord2f(7.0f, 7.0f); glVertex3f(3200.0f, 0.0f, 3200.0f);
				glTexCoord2f(7.0f, 0.0f); glVertex3f(3200.0f, 0.0f, -3200.0f);
			});
			glDisable ( GL_TEXTURE_2D );
        });
        transform({//desenha rio
            glColor3f(0,0,1);
            glTranslatef(0,-345,0);
            glScalef(0.2,0.003,8);
            glutSolidCube(800);
        });
        range(i, 0, NUM_TREES/2) {
        	drawTrunk(tx1[i], ty1[i]);
            drawBranches(tx1[i], ty1[i]);
            drawTrunk(tx2[i], ty2[i]);
            drawBranches(tx2[i], ty2[i]);
        }
    });
}