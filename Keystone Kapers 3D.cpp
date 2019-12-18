#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

// Vari�veis para controles de navega��o
GLfloat angle, fAspect, angsol, rotb, rotbL;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot, dx, dy, dz, tx, ty, tz, velP = 0;

int txL, tyL, tzL, flag, cor, corF, descendo, andarLula, andarLulaF, movLula, pular1, pular, p;

bool rotbb, move, move2, move3, move4, movec, ori;

bool rotbbL, moveL, move2L, move3L, move4L, movecL, oriL;

int distanciaF;		   //Distancia final permitida pelo boneco
int distanciaI = -100; //Distancia inicial permitida pelo boneco

int distanciaFL;		//Distancia final permitida pelo boneco
int distanciaIL = -100; //Distancia inicial permitida pelo boneco

// Fun��o respons�vel pela especifica��o dos par�metros de ilumina��o

//

void BracoDireito(int cor1, int cor2, int cor3)
{
	//bra�o direito
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10, -10, -10.0);
	glScalef(2, 1, 1);

	glutSolidCube(5);
	glPopMatrix();
}

void BracoEsquerdo(int cor1, int cor2, int cor3)
{
	//bra�o direito
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10, -10, 10.0);
	glScalef(2, 1, 1);

	glutSolidCube(5);
	glPopMatrix();
}

void PernaDireita(int cor1, int cor2, int cor3)
{
	//perna direita
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(5, -25, -5.0);
	glScalef(1, 2, 1);
	glutSolidCube(5);
	glPopMatrix();
}

void PernaEsquerda(int cor1, int cor2, int cor3)
{
	//perna esquerda
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(5, -25, 5.0);
	glScalef(1, 2, 1);
	glRotatef(50, 0, 0, 0);
	glutSolidCube(5);
	glPopMatrix();
}

void ListrasPreta(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glScalef(2.5, 0.5, 2);
	glutSolidCube(5);
}

void Corpo(int cor1, int cor2, int cor3)
{

	//Boné
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(6.0, 4.0, 0.0);
	glScalef(2.5, 0.5, 2.0);
	glutSolidCube(5);
	//glutSolidSphere(5,20,10);
	glPopMatrix();

	//cabe�a
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(5.0, 0.0, 0.0);
	glutSolidCube(8);
	//glutSolidSphere(5,20,10);
	glPopMatrix();

	//pesco�o
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(5.0, -6, .0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(5);
	// glutSolidTorus(3,4,20,20);
	glPopMatrix();

	//corpo
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(5.0, -14, 0.0);
	glScalef(2, 3, 2.5);
	glutSolidCube(5);
	glPopMatrix();

	//olho esquerdo
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(10.2, 0.8, -2.2);
	glutSolidSphere(0.5, 20, 10);
	glPopMatrix();

	//olho direito
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(10.2, 0.8, 2.2);
	glutSolidSphere(0.5, 20, 10);
	glPopMatrix();
}

void DesenhaPiso(void)
{
	glColor3f(1, 1, 0);
	glScalef(10, 0.1, 3);
	glutSolidCube(50);
}

void DesenhaFundo(void)
{
	glColor3f(0, 1, 0);
	glScalef(10, 4, 0.1);
	glutSolidCube(50);
}

void Elevador(void)
{
	glColor3f(1, 1, 1);
	glScalef(0.5, 1, 1.5);
	glutSolidCube(50);
}

void Lula(int cor1, int cor2, int cor3, int velocidade)
{
	glPushMatrix();
	glTranslatef(10 + txL + velocidade, -18 + tyL, 0.0 + tzL); //Posição do boneco
	glRotatef(rotbL, 0, 1, 0);
	if (movecL)
	{
		glRotatef(-10, 0, 0, 1);
		movecL = !movecL;
	}
	Corpo(cor1, cor2, cor3);
	glPopMatrix();

	//manipular Braço Direito
	glPushMatrix();
	glTranslatef(10 + txL + velocidade, -18 + tyL, 0.0 + tzL);
	glRotatef(rotbL, 0, 1, 0);

	if (moveL)
	{
		glRotatef(45, 0, 0, 1);

		glTranslatef(-17, 0, -2);
		moveL = !moveL;
	}
	BracoDireito(cor1, cor2, cor3);
	glPopMatrix();

	//manipular Braço Direito
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10 + txL + velocidade, -18 + tyL, 0.0 + tzL);

	glRotatef(rotbL, 0, 1, 0);

	if (move2L)
	{
		glRotatef(-45, 0, 0, 1);
		glTranslatef(3, 5, 0);
		move2L = !move2L;
	}
	BracoEsquerdo(cor1, cor2, cor3);
	glPopMatrix();

	//Manipula Perna Direita
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10 + txL + velocidade, -18 + tyL, 0.0 + tzL);
	glRotatef(rotbL, 0, 1, 0);

	if (move3L)
	{
		glRotatef(90, 0, 0, 1);
		glTranslatef(-27, 14, 0);
		move3L = !move3L;
	}

	PernaDireita(cor1, cor2, cor3);
	glPopMatrix();

	//Manipula Perna Esquerda
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10 + txL + velocidade, -18 + tyL, 0.0 + tzL);
	glRotatef(rotbL, 0, 1, 0);

	if (move4L)
	{
		glRotatef(-90, 0, 0, 1);
		glTranslatef(16, 23, 0);
		move4L = !move4L;
	}

	PernaEsquerda(cor1, cor2, cor3);
	glPopMatrix();
}

void Policial(int cor1, int cor2, int cor3, int velocidade)
{
	glPushMatrix();
	glTranslatef(10 + tx + velocidade, -18 + ty, 0.0 + tz); //Posição do boneco
	glRotatef(rotb, 0, 1, 0);
	if (movec)
	{
		glRotatef(-10, 0, 0, 1);
		movec = !movec;
	}
	Corpo(cor1, cor2, cor3);
	glPopMatrix();

	//manipular Braço Direito
	glPushMatrix();
	glTranslatef(10 + tx + velocidade, -18 + ty, 0.0 + tz);
	glRotatef(rotb, 0, 1, 0);

	if (move)
	{
		glRotatef(45, 0, 0, 1);

		glTranslatef(-17, 0, -2);
		move = !move;
	}
	BracoDireito(cor1, cor2, cor3);
	glPopMatrix();

	//manipular Braço Direito
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10 + tx + velocidade, -18 + ty, 0.0 + tz);

	glRotatef(rotb, 0, 1, 0);

	if (move2)
	{
		glRotatef(-45, 0, 0, 1);
		glTranslatef(3, 5, 0);
		move2 = !move2;
	}
	BracoEsquerdo(cor1, cor2, cor3);
	glPopMatrix();

	//Manipula Perna Direita
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10 + tx + velocidade, -18 + ty, 0.0 + tz);
	glRotatef(rotb, 0, 1, 0);

	if (move3)
	{
		glRotatef(90, 0, 0, 1);
		glTranslatef(-27, 14, 0);
		move3 = !move3;
	}

	PernaDireita(cor1, cor2, cor3);
	glPopMatrix();

	//Manipula Perna Esquerda
	glPushMatrix();
	glColor3f(cor1, cor2, cor3);
	glTranslatef(10 + tx + velocidade, -18 + ty, 0.0 + tz);
	glRotatef(rotb, 0, 1, 0);

	if (move4)
	{
		glRotatef(-90, 0, 0, 1);
		glTranslatef(16, 23, 0);
		move4 = !move4;
	}

	PernaEsquerda(cor1, cor2, cor3);
	glPopMatrix();
}

void ProgramaPolicial(void)
{

	//Define os Limites:
	//Descendo:
	//////////////////////////////
	if (tx > distanciaF - 40)
	{
		if (descendo == 1)
		{
			if (ty == 100 && cor == 100)
			{
				ty -= 50;
			}
			if (ty == 50 && cor == 200)
			{
				ty -= 50;
			}
			if (ty == 0 && cor == 300)
			{
				ty -= 50;
			}
		}
		else
		{
			//Subindo
			if (descendo == 0)
			{
				if (ty == -50 && cor == 300)
				{
					ty += 50;
				}
				if (ty == 0 && cor == 200)
				{
					ty += 50;
				}
				if (ty == 50 && cor == 100)
				{
					ty += 50;
				}
			}
		}
	}

	Policial(0, 1, 1, -2);
}

void ProgramaLula(void)
{
	if (txL > distanciaF - 40)
	{
		if (descendo == 1)
		{
			if (tyL == 100 && cor == 100)
			{
				tyL -= 50;
			}
			if (tyL == 50 && cor == 200)
			{
				tyL -= 50;
			}
			if (tyL == 0 && cor == 300)
			{
				tyL -= 50;
			}
		}
		else
		{
			//Subindo
			if (descendo == 0)
			{
				if (tyL == -50 && cor == 300)
				{
					tyL += 50;
				}
				if (tyL == 0 && cor == 200)
				{
					tyL += 50;
				}
				if (tyL == 50 && cor == 100)
				{
					tyL += 50;
				}
			}
		}
	}

	Lula(1, 0, 0, 30);
}

void DesenhaTexto(void *font, char *string)
{
	glColor3f(1,1,1);
	glPushMatrix();
		while(*string)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++);
		}
	glPopMatrix();
}


void Vitoria(void)
{
	if ((txL == tx) && (ty == txL))
	{
		glPushMatrix();
			DesenhaTexto(GLUT_BITMAP_9_BY_15,"Você venceu!");
		glPopMatrix();
	}
}


void CalculoElevador(void)
{
	//Policial
	if (((cor >= 0 && cor <= 100) && (ty == 100)) || ((cor > 100 && cor <= 200) && (ty == 50)) ||
		((cor > 200 && cor <= 300) && (ty == 0)) || ((cor > 300 && cor <= 400) && (ty == -50)))
	{
		distanciaF = 250;
	}
	else
	{
		distanciaF = 180;
	}

	//Lula
	if (((cor >= 0 && cor <= 100) && (tyL == 100)) || ((cor > 100 && cor <= 200) && (tyL == 50)) ||
		((cor > 200 && cor <= 300) && (tyL == 0)) || ((cor > 300 && cor <= 400) && (tyL == -50)))
	{
		distanciaFL = 250;
	}
	else
	{
		distanciaFL = 180;
	}
}

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{
	tyL = 50;
	Vitoria();
	CalculoElevador();
	// Limpa a janela de visualiza��o com a cor

	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Chama a fun��o que especifica os par�metros de ilumina��o
	ProgramaPolicial();

	ProgramaLula();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-70.0, 80.0, -100.0);
	glRotatef(angsol, 0, 0, 1);
	glutSolidSphere(15, 15, 10);
	glPopMatrix();

	//Desenhando o Cenário:

	//Desenha Elevador
	glPushMatrix();
	glTranslated(250, 75, 0);
	Elevador();
	glPopMatrix();

	glPushMatrix();
	if (cor >= 0 && cor <= 100)
	{
		glColor3f(1, 0, 0);
	}
	else
	{
		glColor3f(0, 0, 1);
	}
	glTranslated(250, 65, 0);
	glutSolidCube(30);
	glPopMatrix();

	//Desenha Elevador
	glPushMatrix();
	glTranslated(250, 25, 0);
	Elevador();
	glPopMatrix();

	glPushMatrix();
	if (cor > 100 && cor <= 200)
	{
		glColor3f(1, 0, 0);
	}
	else
	{
		glColor3f(0, 0, 1);
	}
	glTranslated(250, 15, 0);
	glutSolidCube(30);
	glPopMatrix();

	//Desenha Elevador
	glPushMatrix();
	glTranslated(250, -30, 0);
	Elevador();
	glPopMatrix();

	glPushMatrix();
	if (cor > 200 && cor <= 300)
	{
		glColor3f(1, 0, 0);
	}
	else
	{
		glColor3f(0, 0, 1);
	}

	glTranslated(250, -35, 0);
	glutSolidCube(30);
	glPopMatrix();

	//Desenha Elevador
	glPushMatrix();
	glTranslated(250, -75, 0);
	Elevador();
	glPopMatrix();

	glPushMatrix();
	if (cor > 300 && cor <= 400)
	{
		glColor3f(1, 0, 0);
	}
	else
	{
		glColor3f(0, 0, 1);
	}
	glTranslated(250, -80, 0);
	glutSolidCube(30);
	glPopMatrix();

	//Desenhando o Fundo
	glPushMatrix();
	glTranslated(10, -50, -50);
	DesenhaFundo();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, -100, -0);
	DesenhaPiso();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, -50, -0);
	DesenhaPiso();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 0, -0);
	DesenhaPiso();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 50, -0);
	DesenhaPiso();
	glPopMatrix();

	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Fun��o usada para especificar a posi��o do observador virtual

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
	// (angulo, aspecto, zMin, zMax)
	gluPerspective(angle, fAspect, 0.5, 1000);

	// Posiciona e orienta o observador
	glTranslatef(-obsX, -obsY, -obsZ);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	gluLookAt(0 + dx, 5 + dy, 350 + dx, 0 + dx, 50 + dy, -80 + dz, 0, 1, 0);

	glutPostRedisplay();
}

// Fun��o callback chamada para gerenciar eventos de teclas normais (ESC)
void Teclado(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		dx++, tx++;
		break;
	case 'z':
		dx--;
		break;
	case 's':
		dy++;
		break;
	case 'x':
		dy--;
		break;
	case 'd':
		dz++;
		break;
	case 'c':
		dz--;
		break;
	}

	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Fun��o callback para tratar eventos de teclas especiais
void TeclasEspeciais(int tecla, int x, int y)
{
	switch (tecla)
	{
	case GLUT_KEY_HOME:
		if (angle >= 10)
			angle -= 5;
		break;
	case GLUT_KEY_END:
		if (angle <= 150)
			angle += 5;
		break;
	case GLUT_KEY_F10:
		rotbb = !rotbb;
		break;
	case GLUT_KEY_UP:
		ty += 50;
		break;
	case GLUT_KEY_DOWN:
		ty -= 50;
		break;
	case GLUT_KEY_LEFT:
		if (tx >= distanciaI)
		{
			tx -= 5;
			move = 1, move3 = 1, move2 = 1, move4 = 1, movec = 1, rotb = 180;
		}
		else
		{
			tx = distanciaI + 5;
		}

		break;

	case GLUT_KEY_RIGHT:
		if (tx <= distanciaF)
		{
			tx += 5;
			move2 = 1, move4 = 4, move = 1, move3 = 1, movec = 1, rotb = 0;
		}
		else
		{
			tx = distanciaF - 5;
		}

		break;

	case GLUT_KEY_F3:
		tz += 2;
		break;
	case GLUT_KEY_F4:
		tz -= 2;
		break;
	case GLUT_KEY_F5:
		pular = 1;
		break;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Fun��o callback para eventos de bot�es do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		// Salva os par�metros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else
		bot = -1;
}

// Fun��o callback para eventos de movimento do mouse
#define SENS_ROT 5.0
#define SENS_OBS 10.0
#define SENS_TRANSL 10.0
void GerenciaMovim(int x, int y)
{
	// Bot�o esquerdo ?
	if (bot == GLUT_LEFT_BUTTON)
	{
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica �ngulos
		rotY = rotY_ini - deltax / SENS_ROT;
		rotX = rotX_ini - deltay / SENS_ROT;
	}
	// Bot�o direito ?
	else if (bot == GLUT_RIGHT_BUTTON)
	{
		// Calcula diferen�a
		int deltaz = y_ini - y;
		// E modifica dist�ncia do observador
		obsZ = obsZ_ini + deltaz / SENS_OBS;
	}
	// Bot�o do meio ?
	else if (bot == GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posi��es
		obsX = obsX_ini + deltax / SENS_TRANSL;
		obsY = obsY_ini - deltay / SENS_TRANSL;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Fun��o callback chamada pela GLUT a cada intervalo de tempo
void Anima(int value)
{
	int t = ty;
	// Muda o angulo de rota��o, e se chegar a 360, passa para zero
	if (++angsol > 360.0f)
	{
		angsol = 0.0f;
	}

	angsol += 10;

	if (rotbb)
	{

		rotb += 5;
	}

	//Pular

	if (pular == 2)
	{
		if (p == 0)
		{
			pular = 0;
		}
		p -= 1;
		ty = ty - p;
	}
	if(pular == 1)
	{
		if (++p > 2)
		{
			pular = 2;
		}
		p += 1;
		ty = ty + p;
	}
	

	//Cor elevador
	///////////////////
	if (corF == 1)
	{
		descendo = 0;
		if (--cor < 0)
		{
			corF = 0;
		}
		cor -= 1;
	}
	else
	{
		descendo = 1;
		if (++cor > 400)
		{
			corF = 1;
		}
		cor += 1;
	}
	///////////////////

	//AndarLula
	if (++movLula > 2)
	{
		movLula = 0;

		if (movLula % 2 == 0)
		{
			moveL = 1;
			move2L = 1;
			move3L = 1;
			move4L = 1;
			movecL = 1;
		}
		else
		{
			moveL = 0;
			move2L = 0;
			move3L = 0;
			move4L = 0;
			movecL = 0;
		}
	}
	movLula += 1;

	//AndarLula
	if (andarLulaF == 1)
	{
		rotbL = 180;
		if (--andarLula < distanciaIL)
		{
			andarLulaF = 0;
		}
		andarLula -= 2;
		txL = andarLula;
	}
	else
	{
		rotbL = 0;
		if (++andarLula > distanciaFL)
		{
			andarLulaF = 1;
		}
		andarLula += 3;
		txL = andarLula;
	}

	glutPostRedisplay();
	glutTimerFunc(60, Anima, 1);
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if (h == 0)
		h = 1;

	// Especifica as dimens�es da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(0.4f, 0.0f, 1.0f, 1.0f);

	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Inicializa a vari�vel que especifica o �ngulo da proje��o
	// perspectiva
	angle = 45;

	// Inicializa as vari�veis usadas para alterar a posi��o do
	// observador virtual
	rotX = 0;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 150;

	rotb = 0;
	rotbL = 0;

	dx = 0;
	dy = 0;
	dz = 0;

	tx = 0;
	ty = 0;
	tz = 0;

	txL = 0;
	tyL = 0;
	tzL = 0;

	cor = 0;
	corF = 0;

	descendo = 0;

	movLula = 0;
	andarLula = 0;
	andarLulaF = 0;

	pular1 = 0;
	pular = 0;
	p = 0;
}

// Programa Principal
int main(int argc, char **argv)
{
	//Argumentos para rodar no Linux:
	glutInit(&argc, argv);

	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(5, 5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(800, 600);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Cubo RGB");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas normais
	glutKeyboardFunc(Teclado);

	// Registra a fun��o callback para tratamento das teclas especiais
	glutSpecialFunc(TeclasEspeciais);

	// Registra a fun��o callback para eventos de bot�es do mouse
	glutMouseFunc(GerenciaMouse);

	// Registra a fun��o callback para eventos de movimento do mouse
	glutMotionFunc(GerenciaMovim);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	glutTimerFunc(100, Anima, 1);

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
