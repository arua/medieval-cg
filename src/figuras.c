#include <stdbool.h>
#include <math.h>
#include <GL/glut.h>

#include "macros.h"
#include "figuras.h"

bool inited = false;
GLUquadricObj *obj;

void initFiguras() {
	if(!inited) {
		obj = gluNewQuadric();
		gluQuadricDrawStyle(obj,GLU_FILL);
		inited = true;
	}
}

void roda() {
	transform({
		glColor(255, 255, 0);

		glTranslatef(0, 0, -5);
		gluDisk(obj, 50, 70, 20, 20);

		glColor(255, 255, 127);
		transform({
			glTranslatef(0, 0, 5);
			glScalef(10, 2, 1);
			glutSolidCube(10);
			glScalef(1/5.0, 5, 1);
			glutSolidCube(10);
		});

		glColor(255, 255, 0);
		gluCylinder(obj,70,70,10,20,20);
		gluCylinder(obj,50,50,10,20,20);
		glTranslatef(0, 0, 10);
		gluDisk(obj, 50, 70, 20, 20);
	});
}

void catapulta(float angulo) {
	transform({
		glTranslatef(0, -40, 70);
		glRotatef(90, 0, 1, 0);

		transform({
			glColor(255, 127, 127);
			glScalef(1, 1, 10);
			glutSolidCube(10);
		});

		glTranslatef(0, 0, -45);
		roda();
		glTranslatef(0, 0, 90);
		roda();
	});

	transform({
		glColor(255, 0, 0);
		gluDisk(obj, 0, 20, 20, 20);
		glColor(0, 255, 0);
		gluCylinder(obj,20,40,30,20,20);
		glTranslatef(0, 0, 30);
		gluCylinder(obj,40,40,100,20,20);
		glTranslatef(0, 0, 100);
		gluCylinder(obj,40,25,30,20,20);
		glTranslatef(0, 0, 30);
		gluCylinder(obj,25,20,100,20,20);
	});
}

void pessoaJogo() {

	/* Desenha cabeca */
	transform({
		glTranslatef( 0.0, 300.0, 0.0 );
		transform({
			/* Desenha rosto */
			glColor3f( 1.0, 1.0, 1.0 );
			transform({
				glScaled( 0.7, 1.0, 0.7 );
				glRotatef( 90.0, 0.0, 1.0, 0.0 );
				glutSolidSphere(100.0, 20, 50);
			});

			/* Olho esquerdo */
			glColor3f( 0.8, 1.0, 0.8 );
			transform({
				glTranslatef( -30.0, 40.0, -60.0 );
				transform({
					glScaled( 0.2, 0.2, 0.05 );
					glutSolidSphere(150.0, 20, 50);
				});
				glColor3f( 0.0, 0.0, 0.0 );
				glScaled( 0.07, 0.07, 0.07 );
				glutSolidSphere(100.0, 20, 50);
			});

			/* Olho direito */
			glColor3f( 0.8, 1.0, 0.8 );
			transform({
				glTranslatef( 30.0, 40.0, -60.0 );
				transform({
					glScaled( 0.2, 0.2, 0.05 );
					glutSolidSphere(150.0, 20, 50);
				});
				glColor3f( 0.0, 0.0, 0.0 );
				glScaled( 0.04, 0.04, 0.04 );
				glutSolidSphere(100.0, 20, 50);
			});

			/* Boca */
			glColor3f( 0.0, 0.0, 1.0 );
			transform({
				glScaled( 0.35, 0.045, 0.25 );
				glTranslatef( 0.0, -500.0, -250.0);
				glutSolidTorus(30.0, 70.0, 20, 20);
			});
		});

	});

	/* Desenha torso */
	glColor3f( 1.0, 1.0, 1.0 );
	transform({
		glScaled( 1.2, 2.2, 1.2  );
		glRotatef( 90.0, 0.0, 1.0, 0.0 );
		glutSolidSphere(100.0, 20, 50);
	});

	/* Desenha braco esquerdo */
	transform({
		glTranslatef( -100.0, 120.0, 0.0);
		glColor3f( 1.0, 1.0, 0.0 );
		transform({/* Desenha braco esquerdo */
			glTranslatef( -10.0, 0.0, -50.0);
			glRotatef( 20.0, 0.0, 0.0, 1.0 );
			glRotatef( 90.0, 0.0, 1.0, 0.0 );
			glScaled( 0.7, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 1.0, 0.0 );
		transform({
			glTranslatef( -10.0, 0.0, -140.0);
			glRotatef( -90.0, 0.0, 1.0, 0.0 );
			glScaled( 0.5, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 0.0, 1.0 );
		transform({
			glTranslatef( -10.0, 0.0, -200.0);
			glScaled( 1.0, 1.0, 1.0 );
			glutSolidSphere(20.0, 20, 50);
		});
	});

	/* Desenha braco direito */
	transform({
		glTranslatef( 60.0, 70.0, 0.0);
		glColor3f( 1.0, 1.0, 0.0 );
		transform({/* Desenha braco esquerdo */
			glTranslatef( 70.0, 0.0, 0.0);
			glRotatef( -70.0, 0.0, 0.0, 1.0 );
			glScaled( 0.7, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 1.0, 0.0 );
		transform({
			glTranslatef( 100.0, -100.0, 0.0);
			glRotatef( -80.0, 0.0, 0.0, 1.0 );
			glScaled( 0.5, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 0.0, 1.0 );
		transform({
			glTranslatef( 110.0, -165.0, 0.0);
			glScaled( 1.0, 1.0, 1.0 );
			glutSolidSphere(20.0, 20, 50);
		});
	});

	/* Desenha perna esquerda */
	transform({
		glTranslatef( -15.0, -250.0, 0.0);
		glColor3f( 1.0, 1.0, 0.0 );
		transform({
			glTranslatef( -70.0, 0.0, 0.0);
			glRotatef( 70.0, 0.0, 0.0, 1.0 );
			glScaled( 0.7, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 1.0, 0.0 );
		transform({
			glTranslatef( -100.0, -100.0, 0.0);
			glRotatef( 80.0, 0.0, 0.0, 1.0 );
			glScaled( 0.5, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 0.0, 1.0 );
		transform({
			glTranslatef( -110.0, -165.0, -20.0);
			glScaled( 1.0, 1.0, 2.0 );
			glutSolidSphere(20.0, 20, 50);
		});
	});

	/* Desenha perna direita */
	transform({
		glTranslatef( 15.0, -250.0, 0.0);
		glColor3f( 1.0, 1.0, 0.0 );
		transform({
			glTranslatef( 70.0, 0.0, 0.0);
			glRotatef( -70.0, 0.0, 0.0, 1.0 );
			glScaled( 0.7, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 1.0, 0.0 );
		transform({
			glTranslatef( 100.0, -100.0, 0.0);
			glRotatef( -80.0, 0.0, 0.0, 1.0 );
			glScaled( 0.5, 0.2, 0.2 );
			glutSolidSphere(100.0, 20, 50);
		});
		glColor3f( 0.0, 0.0, 1.0 );
		transform({
			glTranslatef( 110.0, -165.0, -20.0);
			glScaled( 1.0, 1.0, 2.0 );
			glutSolidSphere(20.0, 20, 50);
		});
	});
}

void pessoaVence() {

}

void pessoaMorta() {

}

void muralha(muralhaEstado estado) {

}

void castelo() {

}

void bandeira(int jogador) {
	if(jogador == 1) glColor(255,0,0);
	else glColor(0,0,255);
	transform({
		// Triângulo bizarro
		glRotatef(90, 0, 0, 1);
		draw(GL_POLYGON, {
			glVertex3f(-25, 0, 0);
			glVertex3f(0, 70, 0);
			glVertex3f(25, 0, 0);
			
			glVertex3f(-25, 0, 0);
			glVertex3f(-25, 0, 5);
			
			glVertex3f(0, 70, 5);
			glVertex3f(0, 70, 0);
			glVertex3f(0, 70, 5);
			
			glVertex3f(25, 0, 5);
			glVertex3f(25, 0, 0);
			glVertex3f(25, 0, 5);
			
			glVertex3f(-25, 0, 5);
		});
		glTranslatef(-25, -10, 0);
		glColor(168, 86, 3);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, -105);
		gluCylinder(obj,5,5,160,20,20);
	});
}

void trombete() {
	glColor(242, 227, 7);
	transform({
		glScalef(1, 0.5, 1);
		glutSolidTorus(10, 50, 20, 20);
	});
	transform({
		glTranslatef(-80, 25, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(obj, 7.5, 7.5, 160, 20, 20);
		glTranslatef(0, 0, -40);
		gluCylinder(obj, 15, 7.5, 40, 20, 20);
		glTranslatef(0, 0, 200);
		gluCylinder(obj, 7.5, 5, 40, 20, 20);
	});
	transform({
		glTranslatef(-30, 50, 0);
		repeat(3) {
			transform({
				glRotatef(90, 1, 0, 0);
				gluCylinder(obj, 5, 5, 20, 20, 20);
			});
			transform({
				glRotatef(90, 1, 0, 0);
				gluDisk(obj, 0, 10, 20, 20);
				gluCylinder(obj, 10, 10, 3, 20, 20);
				glTranslatef(0, 3, 0);
				gluDisk(obj, 0, 10, 20, 20);
			});
			glTranslatef(30, 0, 0);
		}
	});
}
