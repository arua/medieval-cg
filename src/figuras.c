/*!
 * \file
 *
 * Neste arquivo sao implementadas as funcoes referentes ao desenho isolado de cada objeto do jogo, as funcoes sao definidas
 * no arquivo \ref figuras.h .
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#include "macros.h"
#include "figuras.h"
#include "texturas.h"
#include "logica.h"

static bool inited = false;
static GLUquadricObj *obj;

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
		glRotatef(-45, 1, 0, 0);
		glColor(150, 150, 150);
		gluDisk(obj, 0, 20, 20, 20);
		glColor(150, 150, 150);
		gluCylinder(obj,20,40,30,20,20);
		glTranslatef(0, 0, 30);
		gluCylinder(obj,40,40,100,20,20);
		glTranslatef(0, 0, 100);
		gluCylinder(obj,40,25,30,20,20);
		glTranslatef(0, 0, 30);
		gluCylinder(obj,25,20,100,20,20);
	});
}

void desenha_quadrado_textura_pessoa( int textures_ID_index )
{
	glBindTexture(GL_TEXTURE_2D, texturesID[textures_ID_index]);

	glBegin(GL_QUADS);

	glNormal3f(-100.0, -100.0, 0.0); glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, -100.0, 0.0);
	glNormal3f(100.0, -100.0, 0.0); glTexCoord2f(1.0, 0.0); glVertex3f(100.0, -100.0, 0.0);
	glNormal3f(100.0,  100.0, 0.0); glTexCoord2f(1.0, 1.0); glVertex3f(100.0,  100.0, 0.0);
	glNormal3f(-100.0,  100.0, 0.0); glTexCoord2f(0.0, 1.0); glVertex3f(-100.0,  100.0, 0.0);

	glEnd();
}

void bandeira_derrota() {
	transform({
		//Bandeira
		desenha_quadrado_textura_pessoa(BANDEIRA_DERROTA);

		//Cabo
		glTranslatef( -110.0, -100.0, 0.0 );
		glScalef( 0.1, 2.0, 0.0 );

		desenha_quadrado_textura_pessoa(BANDEIRA_DERROTA_CABO);
	});
}

void desenha_pessoa_cabeca( int tipo_pessoa )
{

	switch ( tipo_pessoa ) {
	case 0:
		desenha_quadrado_textura_pessoa( CABECA_FRENTE_JOGO );
		break;
	case 1:
		desenha_quadrado_textura_pessoa( CABECA_FRENTE_VITORIA );
		break;
	case 2:
		desenha_quadrado_textura_pessoa( CABECA_FRENTE_DERROTA );
		break;
	case 3:
		desenha_quadrado_textura_pessoa( CABECA_FRENTE_MORTE );
		break;
	default:
		break;
	}

	transform({
		glTranslatef( -100.0, 0.0, -100.0 );
		glRotatef( 90.0, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( CABECA_LADO_ESQUERDO );
	});
	transform({
		glTranslatef( 100.0, 0.0, -100.0 );
		glRotatef( -90.0, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( CABECA_LADO_DIREITO );
	});
	transform({
		glTranslatef( 0.0, 0.0, -200.0 );
		desenha_quadrado_textura_pessoa( CABECA_ATRAS );
	});
	transform({
		glTranslatef( 0.0, 100.0, -100.0 );
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( CABECA_TOPO );
	});
	transform({
		glTranslatef( 0.0, -100.0, -100.0 );
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( CABECA_BAIXO );
	});
}

void desenha_pessoa_torso()
{
	transform({
		glScalef( 0.9, 1.4, 1.0 );
		desenha_quadrado_textura_pessoa( TORSO_FRENTE );
	});
	transform({
		glScalef( 0.9, 1.4, 0.5 );
		glTranslatef( 100, 0.0, -100.0 );
		glRotatef( 90, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( TORSO_LADO );
	});
	transform({
		glScalef( 0.9, 1.4, 0.5 );
		glTranslatef( -100, 0.0, -100.0 );
		glRotatef( 90, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( TORSO_LADO );
	});
	transform({
		glScalef( 0.9, 1.4, 0.5 );
		glTranslatef( 0.0, 0.0, -200.0 );
		desenha_quadrado_textura_pessoa( TORSO_ATRAS );
	});
	transform({
		glScalef( 0.9, 1.4, 0.5 );
		glTranslatef( 0.0, -100.0, -100.0 );
		glRotatef( 90, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( TORSO_BAIXO );
	});
	transform({
		glScalef( 0.9, 1.4, 0.5 );
		glTranslatef( 0.0, 100.0, -100.0 );
		glRotatef( 90, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( TORSO_CIMA );
	});
}

void desenha_pessoa_braco()
{
	transform({
		glScalef( 0.3, 1.5, 0.3 );
		desenha_quadrado_textura_pessoa( BRACO_FRENTE );
	});
	transform({
		glScalef( 0.3, 1.5, 0.3 );
		glTranslatef( 100, 0.0, -100.0 );
		glRotatef( 90, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( BRACO_LADO );
	});
	transform({
		glScalef( 0.3, 1.5, 0.3 );
		glTranslatef( -100, 0.0, -100.0 );
		glRotatef( 90, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( BRACO_LADO );
	});
	transform({
		glScalef( 0.3, 1.5, 0.3 );
		glTranslatef( 0.0, 0.0, -200.0 );
		desenha_quadrado_textura_pessoa( BRACO_ATRAS );
	});
	transform({
		glScalef( 0.3, 1.5, 0.3 );
		glTranslatef( 0.0, -100.0, -100.0 );
		glRotatef( 90, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( BRACO_BAIXO );
	});
	transform({
		glScalef( 0.3, 1.5, 0.3 );
		glTranslatef( 0.0, 100.0, -100.0 );
		glRotatef( 90, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( BRACO_CIMA );
	});
}

void desenha_pessoa_perna()
{
	transform({
		glScalef( 0.45, 1.5, 0.3 );
		desenha_quadrado_textura_pessoa( PERNA_FRENTE );
	});
	transform({
		glScalef( 0.45, 1.5, 0.3 );
		glTranslatef( 100, 0.0, -100.0 );
		glRotatef( 90, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( PERNA_LADO );
	});
	transform({
		glScalef( 0.45, 1.5, 0.3 );
		glTranslatef( -100, 0.0, -100.0 );
		glRotatef( 90, 0.0, 1.0, 0.0 );
		desenha_quadrado_textura_pessoa( PERNA_LADO );
	});
	transform({
		glScalef( 0.45, 1.5, 0.3 );
		glTranslatef( 0.0, 0.0, -200.0 );
		desenha_quadrado_textura_pessoa( PERNA_ATRAS );
	});
	transform({
		glScalef( 0.45, 1.5, 0.3 );
		glTranslatef( 0.0, -100.0, -100.0 );
		glRotatef( 90, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( PERNA_BAIXO );
	});
	transform({
		glScalef( 0.45, 1.5, 0.3 );
		glTranslatef( 0.0, 100.0, -100.0 );
		glRotatef( 90, 1.0, 0.0, 0.0 );
		desenha_quadrado_textura_pessoa( PERNA_CIMA );
	});
}

void desenha_pessoa_jogo( double estagio_anima )
{
	// Desenha cabeca
	transform({
		glTranslatef( 0.0, 240, 50.0);
		desenha_pessoa_cabeca(0);
	});

	// Desenha torso
	transform({
		desenha_pessoa_torso();
	});

	//Desenha braco esquerdo
	transform({
		glTranslatef( -120.0, -10.0, -20.0);

		//Movimentacao do braco
		glTranslatef( 0.0, 100.0, 0.0);
		glRotatef( -110, 1.0, 0.0, 0.0 );
		glTranslatef( 0.0, -100.0, 0.0);

		desenha_pessoa_braco();
	});

	// Desenha braco direito
	transform({
		glTranslatef( 120.0, -10.0, -20.0);

		//Movimentacao do braco
		glTranslatef( 0.0, 100.0, 0.0);
		glRotatef( 40, 1.0, 0.0, 0.0 );
		glTranslatef( 0.0, -100.0, 0.0);

		desenha_pessoa_braco();
	});

	// Desenha perna esquerda
	transform({
		glTranslatef( -40.0, -260.0, -20.0);

		//Movimento da perna
		glTranslatef( 0.0, 140.0, 0.0);
		glRotatef( -30, 1.0, 0.0, 0.0 );
		glTranslatef( 0.0, -140.0, 0.0);

		desenha_pessoa_perna();
	});

	// Desenha perna direita
	transform({
		glTranslatef( 40.0, -290.0, -20.0);

		//Movimento da perna
		glTranslatef( 0.0, 140.0, 0.0);
		glRotatef( 30, 1.0, 0.0, 0.0 );
		glTranslatef( 0.0, -140.0, 0.0);

		desenha_pessoa_perna();
	});
}

void desenha_pessoa_vitoria( double estagio_anima )
{
	transform({
		//glTranslatef( 0.0, 100.0, 0.0);
		//glRotatef( -estagio_anima, 1.0, 0.0, 0.0 );
		glTranslatef( 0.0, estagio_anima*2, 0.0);

		// Desenha cabeca
		transform({
			glTranslatef( 0.0, 240, 50.0);
			desenha_pessoa_cabeca(1);
		});

		// Desenha torso
		transform({
			desenha_pessoa_torso();
		});

		//Desenha braco esquerdo
		transform({
			glTranslatef( -120.0, -10.0, -20.0);

			//Movimentacao do braco
			glTranslatef( 0.0, 100.0, 0.0);
			glRotatef( -estagio_anima*2, 1.0, 0.0, 0.0 );
			glTranslatef( 0.0, -100.0, 0.0);
		
			desenha_pessoa_braco();
		});

		// Desenha braco direito
		transform({
			glTranslatef( 120.0, -10.0, -20.0);
		
			glTranslatef( 0.0, 100.0, 0.0);
			glRotatef( -estagio_anima*2, 1.0, 0.0, 0.0 );
			glTranslatef( 0.0, -100.0, 0.0);
		
			desenha_pessoa_braco();
		});

		// Desenha perna esquerda
		transform({
			glTranslatef( -40.0, -290.0, -20.0);
			desenha_pessoa_perna();
		});

		// Desenha perna direita
		transform({
			glTranslatef( 40.0, -290.0, -20.0);
			desenha_pessoa_perna();
		});
	});
}

void desenha_pessoa_derrota( double estagio_anima )
{
	// Desenha cabeca
	transform({
		glTranslatef( 0.0, 240, 50.0);
		desenha_pessoa_cabeca(2);
	});

	// Desenha torso
	transform({
		desenha_pessoa_torso();
	});

	//Desenha braco esquerdo
	transform({
		//Para a movimentacao do braco
		glTranslatef( 0.0, 100.0, 0.0);
		glRotatef( -estagio_anima, 1.0, 0.0, 0.0 );
		glTranslatef( 0.0, -100.0, 0.0);

		transform({
			glTranslatef( -120.0, -10.0, -20.0);

			desenha_pessoa_braco();

		});

		//Para ajuste da posicao da bandeira
		glTranslatef( -140.0, -260.0, 240.0 );
		glRotatef( -95, 0.0, 1.0, 0.0 );
		glRotatef( -95, 0.0, 0.0, 1.0 );

		bandeira_derrota();

	});

	// Desenha braco direito
	transform({
		glTranslatef( 120.0, -10.0, -20.0);
		desenha_pessoa_braco();
	});

	// Desenha perna esquerda
	transform({
		glTranslatef( -40.0, -290.0, -20.0);
		desenha_pessoa_perna();
	});

	// Desenha perna direita
	transform({
		glTranslatef( 40.0, -290.0, -20.0);
		desenha_pessoa_perna();
	});
}

void desenha_pessoa_morte( double estagio_anima )
{
	transform({

		glTranslatef( 0.0, -300.0, 0.0);
		glRotatef( -((estagio_anima/100)*90), 1.0, 0.0, 0.0 ); //estagio_anima varia de 0 a 100, mas precisamos de uma rotacao de 0 a 90
		glTranslatef( 0.0, 300.0, 0.0);

		// Desenha cabeca
		transform({
			glTranslatef( 0.0, 240, 50.0);
			desenha_pessoa_cabeca(3);
		});

		// Desenha torso
		transform({
			desenha_pessoa_torso();
		});

		//Desenha braco esquerdo
		transform({
			glTranslatef( -120.0, -10.0, -20.0);

			//Animacao do braco na queda
			glTranslatef( 0.0, 100.0, 0.0);
			glRotatef( -estagio_anima, 1.0, 0.0, 0.0 );
			glTranslatef( 0.0, -100.0, 0.0);

			desenha_pessoa_braco();
		});

		// Desenha braco direito
		transform({
			glTranslatef( 120.0, -10.0, -20.0);

			//Animacao do braco na queda
			glTranslatef( 0.0, 100.0, 0.0);
			glRotatef( -estagio_anima, 1.0, 0.0, 0.0 );
			glTranslatef( 0.0, -100.0, 0.0);

			desenha_pessoa_braco();
		});

		// Desenha perna esquerda
		transform({
			glTranslatef( -40.0, -290.0, -20.0);
			desenha_pessoa_perna();
		});

		// Desenha perna direita
		transform({
			glTranslatef( 40.0, -290.0, -20.0);
			desenha_pessoa_perna();
		});
	});
}

/* Funcao generica para todas as pessoas:
 * parametro 'tipo_pessoa':
 * 	- 0 pessoaJogo
 * 	- 1 pessoaVitoria
 * 	- 2 pessoaDerrota
 * 	- 3 pessoaMorte
 */
void pessoa(estadoJogador tipo_pessoa, double estagio_anima)
{
	glEnable(GL_TEXTURE_2D);

	switch (tipo_pessoa) {
	// pessoaJogo 
	case JOGANDO:
		desenha_pessoa_jogo( estagio_anima );
		break;
		// pessoa vitoria
	case VENCEU:
		desenha_pessoa_vitoria( estagio_anima );
		break;
		//pessoa derrota
	case PERDEU:
		desenha_pessoa_derrota( estagio_anima );
		break;
		//pessoaMorte
	case MORREU:
		desenha_pessoa_morte( estagio_anima );
		break;
	default:
		printf("Erro - Entrou no default da funcao 'pessoa()' - Arquivo 'figuras.c'");
		break;
	}
	glDisable( GL_TEXTURE_2D );
}

static void desenhaParalelepipedo()
{
  GLfloat size = 11.0;
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

  glBindTexture(GL_TEXTURE_2D, texturesID[22]);
  glBegin(GL_QUADS);
  for (i = 5; i >= 0; i--) {
    glNormal3fv(&n[i][0]);
    glTexCoord2i(0, 0);glVertex3fv(&v[faces[i][0]][0]);
    glTexCoord2i(1, 0);glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2i(1, 1);glVertex3fv(&v[faces[i][2]][0]);
    glTexCoord2i(0, 1);glVertex3fv(&v[faces[i][3]][0]);
    
  }
  glEnd();
}

void muralha(muralhaEstado estado){
	int i,j;
	int matrizMuralha[9][9] = {
		{1,1,1,1,1,1,0,0,0},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
	};

	switch(estado) {
		case M0:  range(i, 0, 9) matrizMuralha[8][i] = 0;
		case M20: range(i, 0, 9) matrizMuralha[7][i] = matrizMuralha[6][i] = 0;
		case M40: range(i, 0, 9) matrizMuralha[5][i] = matrizMuralha[4][i] = 0;
		case M60: range(i, 0, 9) matrizMuralha[3][i] = matrizMuralha[2][i] = 0;
		case M80: range(i, 0, 9) matrizMuralha[1][i] = matrizMuralha[0][i] = 0;
		case M100: break;
	}

	glEnable ( GL_TEXTURE_2D );
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	transform({
		//glColor(168, 86, 3);
		glColor(255, 255, 255);
		glScalef(6.5, 5.5, 8.5);
		glTranslatef(0,-52,-40);
		for(i=1;i<9;i++){
			glTranslatef(0,13,0);
			for(j=0;j<9;j++){
				glTranslatef(0, 0, 13);
				if(matrizMuralha[9-i][9-j]) desenhaParalelepipedo();
			}
			if (i%2==0)glTranslatef(0,0,-125.5);
			else glTranslatef(0,0,-109.5);
		}
	});
	transform({
		glScalef(11, 11, 85);
		glTranslatef(0, 36, 2.7);
		if(matrizMuralha[0][5]) desenhaParalelepipedo();

	});

	transform({
		glTranslatef(0, 550, -130);
		glScalef(11, 11, 11);
		if(matrizMuralha[0][0]) desenhaParalelepipedo();
		glTranslatef(0, 0, 17);
		if(matrizMuralha[0][1]) desenhaParalelepipedo();

		glTranslatef(0, 0, 17);
		if(matrizMuralha[0][2]) desenhaParalelepipedo();

		glTranslatef(0, 0, 17);
		if(matrizMuralha[0][3]) desenhaParalelepipedo();
	
		glTranslatef(0, 0, 17);
		if(matrizMuralha[0][4]) desenhaParalelepipedo();

	});
	//glDisable( GL_TEXTURE_2D );
}

void escreverTexto(char* texto) {
	transform({
		do glutStrokeCharacter(GLUT_STROKE_ROMAN, *texto); while(*(++texto));
	});
}

void _letreiro(const char* text1, const char* text2) {
	transform({
		glColor(127, 127, 127);
		escreverTexto(text1);
		glTranslatef(0, -65, 0);
		glScalef(0.7, 0.7, 0.7);
		escreverTexto(text2);
	});
}

void letreiroIni() {
	_letreiro("Batalha Medieval", "Pressione Enter para jogar...");
}

void letreiroFim(int vencedor) {
	glColor(0, 0, 0);
	_letreiro(vencedor == 1 ? "Parabens jogador 1!" : "Parabens jogador 2!", "Pressione Enter para sair...");
}

void pontuacao(int jogador, int pontos) {
	static const char* template = "P%d: %d";
	static char texto[20];
	sprintf(texto, template, jogador, pontos);
	transform({
		if(jogador == 1) glColor(255, 0, 0); else glColor(0, 0, 255);
		escreverTexto(texto);
	});
}


