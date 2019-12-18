#include <GL/glut.h>
#include <stdlib.h>

// Vari�veis para controles de navega��o
GLfloat angle, fAspect, angsol, rotb ,angCarro;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot, dx, dy, dz, tx, ty, tz, MoveNuvem, MoveAviao;
bool rotbb, move;

bool dia, viraCarro;

// Fun��o respons�vel pela especifica��o dos par�metros de ilumina��o
void DefineIluminacao(void)
{
    GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
    GLfloat luzDifusa[4] = {0.8, 0.8, 0.8, 1.0};    // "cor"
    GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
    GLfloat posicaoLuz[4] = {-70.0, 75.0, 90.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
    GLint especMaterial = 60;

    // Define a reflet�ncia do material
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    // Define a concentra��o do brilho
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os par�metros da luz de n�mero 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}
//

void BracoBonecoNeve(void)
{
    //bra�o direito
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);

    glTranslatef(10, -10, 10.0);
    glScalef(2, 1, 1);

    glutSolidSphere(2, 20, 10);
    glPopMatrix();
}

void BonecoNeve(void)
{

    //cabe�a
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(5, 20, 10);
    glPopMatrix();

    //pesco�o
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, -6, 0.0);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(3, 4, 20, 20);
    glPopMatrix();

    //corpo
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, -16, 0.0);
    glScalef(1, 1.2, 1.0);
    glutSolidSphere(10, 20, 10);
    glPopMatrix();

    //bra�o esquerdo
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-10, -10, 0.0);
    glScalef(2, 1, 1);
    glutSolidSphere(2, 20, 10);
    glPopMatrix();

    //perna direita
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(6, -25, 0.0);
    glScalef(1, 2, 1);
    glutSolidSphere(2, 20, 10);
    glPopMatrix();

    //perna esquerda
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-6, -25, 0.0);
    glScalef(1, 2, 1);
    glutSolidSphere(2, 20, 10);
    glPopMatrix();

    //olho esquerdo
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-1.2, 0.8, 5.2);
    glutSolidSphere(0.5, 20, 10);
    glPopMatrix();

    //olho direito
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(1.2, 0.8, 5.2);
    glutSolidSphere(0.5, 20, 10);
    glPopMatrix();
}
void Carro(void)
{

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0, -37, 250);
    glutSolidCube(15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-15, -37, 250);
    glScalef(1.5, 1, 1);
    glutSolidCube(15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(15, -37, 250);
    glutSolidCube(15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-14, -27, 250);
    glutSolidCube(16);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(-12, 13 - 37, 250);
    glScalef(1, 1, 2.4);
    glutSolidCube(8);
    glPopMatrix();

    // farois
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-27, 2 - 37, 195+50);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-27, 2 - 37, 205+50);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();

    // rodas e pneus
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-16, -7 - 37, 197+50);
    glutSolidTorus(2, 3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-16, -7 - 37, 207+50);
    glutSolidTorus(2, 3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(16, -7 - 37, 193+50);
    glutSolidTorus(2, 3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(16, -7 - 37, 207+50);
    glutSolidTorus(2, 3, 20, 20);
    glPopMatrix();
}
void Nuvem(void)
{
     glPushMatrix();
       glTranslatef(1,1,1);
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(-15,15,0);     
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();
     
     glPushMatrix();
       glTranslatef(15,-15,0);          
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();     
     
     glPushMatrix();
       glTranslatef(-15,-15,0);          
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(15,15,0);          
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();    
}
void Arvores1(void)
{
    //Tronco
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-100.0, -50.0, -50.0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(2, 100, 5, 8);
    glPopMatrix();

    //Copa
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-100.0, 30.0, -50.0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(30, 100, 5, 8);
    glPopMatrix();
}

void Arvores2(void)
{
    //Tronco
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-100.0, -50.0, -50.0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(2, 50, 5, 8);
    glPopMatrix();

    //Copa
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-100.0, 20.0, -50.0);
    glRotatef(-90, 1, 0, 0);
    glutSolidSphere(30,30,30);
    glPopMatrix();
}
void compoe_jato(void){
  GLUquadricObj *quadric;

  GLfloat asa[][3]={
    {-4.0,0.0,0.0},
    {+4.0,0.0,0.0},
    {0.0,0.0,3.0}
  };

  GLfloat cauda[][3]={
    {0.0,0.0,0.0},
    {0.0,2.0,-1.0},
    {0.0,2.0,0.0},
    {0.0,0.0,2.0}
  };
  /* inicia a composicao do jato */
  //jato = glGenLists(1);
  //glNewList(jato, GL_COMPILE);

  /* asas */
  glBegin(GL_TRIANGLES);
   glVertex3fv(asa[0]);
   glVertex3fv(asa[1]);
   glVertex3fv(asa[2]);
  glEnd();

  /* corpo */
  quadric = gluNewQuadric();
  gluQuadricTexture(quadric, GL_TRUE);
  gluCylinder(quadric, 0.5, 0.5, 4, 12, 3);

  /* nariz */
  quadric = gluNewQuadric();
  gluQuadricTexture(quadric, GL_TRUE);
  glPushMatrix();
  glTranslatef(0,0,4);
  gluCylinder(quadric, 0.5, 0.0, 1.5, 12, 3);
  glPopMatrix();

  /* cauda */
  glBegin(GL_POLYGON);
   glVertex3fv(cauda[0]);
   glVertex3fv(cauda[1]);
   glVertex3fv(cauda[2]);
   glVertex3fv(cauda[3]);
  glEnd();

  /* cabine do piloto */
  glTranslatef(0,0.3,3.5);
  glPushMatrix();
  glScalef(0.7,0.7,2.0);
  quadric=gluNewQuadric();
  glColor4f(0.3,0.5,1,0.5);
  glDisable(GL_TEXTURE_2D);
  gluSphere(quadric,0.5,12,12);
  glPopMatrix();

  /* termina a composicao do jato*/
  glEndList();
}


void Casa(void)
{
    //Telhado
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(10.0, 23.0, -50.0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(100, 40, 5, 10);
    glPopMatrix();

    //Corpo da Casa
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(1.0, 0.8, 1.0);
    glTranslatef(10.0, -17.0, -50.0);
    glutSolidCube(100);
    glPopMatrix();

    //Porta
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(0.3, 0.5, 0.1);
    glTranslatef(-60.0, -50.0, -20.0);
    glutSolidCube(100);
    glPopMatrix();

    //Janela
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(0.3, 0.3, 0.1);
    glTranslatef(90.0, -30.0, -20.0);
    glutSolidCube(100);
    glPopMatrix();

    //Arvore 1
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    Arvores1();
    glPopMatrix();

    //Arvore 2
    glPushMatrix();
    glTranslatef(220.0, 0.0, 0.0);
    Arvores1();
    glPopMatrix();

     //Arvore 3
    glPushMatrix();
    glTranslatef(-80.0, 0.0, 0.0);
    Arvores2();
    glPopMatrix();

    //Arvore 4
    glPushMatrix();
    glTranslatef(300.0, 0.0, 0.0);
    Arvores2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(MoveNuvem, 120.0, -100.0);
    Nuvem();
    glPopMatrix();

    glPushMatrix();
    glScalef(20.0, 5.0, 5.0);
    glTranslatef(MoveAviao, 0.0, -100.0);
    compoe_jato();
    glPopMatrix();


}
void Dia(void)
{
    //Define cor do fundo
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    //Objetos de fundo

    //Sol
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-70.0, 80.0, -100.0);
    glRotatef(angsol, 0, 0, 1);
    glutSolidSphere(15, 15, 10);
    glPopMatrix();
}
void Noite(void)
{
    //Define cor do fundo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Objetos de fundo

    //Sol
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    
    glTranslatef(-70.0, 80.0, -100.0);
    glRotatef(angsol, 0, 0, 1);
    glutSolidSphere(15, 15, 10);
    glPopMatrix();
}



void DesenhaPiso(void)
{
    // Terra
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0.0, -350.0, 100.0);
    glutSolidCube(600);
    glPopMatrix();

    //Pista do carrinho
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glScalef(60, 0.5, 3.5);
    glTranslatef(0, -100.0, 70.0);
    glutSolidCube(10);
    glPopMatrix();
}

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{

    // Limpa a janela de visualiza��o com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Chama a fun��o que especifica os par�metros de ilumina��o
    DefineIluminacao();

  

 
    Casa();
   

    glPushMatrix();
    if(!viraCarro)
    {
        glTranslatef(10 + tx, ty, 0.0 + tz);
    }
    else
    {
        glRotatef(-90, 0, 1, 0);
        glTranslatef(250 + tx, ty, -240.0 + tz);
    }
    Carro();
    glPopMatrix();



    DesenhaPiso();
   
    if (!dia)
    {
        glPushMatrix();
        Dia();
        glPopMatrix();
    }
    else
    {
        Noite();
    }
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

    DefineIluminacao();
    // Posiciona e orienta o observador
    glTranslatef(-obsX, -obsY, -obsZ);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();

    gluLookAt(0 - dz, 0 + dy, 250 + dx, 0 + dz, dy, 0 + dz, 0, 1, 0);

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
        dz++;
        break;
    case 'w':
        dx--;
        break;
    case 's':
        dx++;
        break;
    case 'x':
        dy--;
        break;
    case 'd':
        dz--;
        break;
    case 'c':
        dz--;
        break;
    case 'f':
        dia = !dia;
        break;
    case 'g':
        viraCarro = !viraCarro;
        angCarro = 90;
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
        tz -= 2;
        break;
    case GLUT_KEY_DOWN:
        tz += 2;
        break;
    case GLUT_KEY_LEFT:
        tx -= 2;
        break;
    case GLUT_KEY_RIGHT:
        tx += 2;
        break;
    case GLUT_KEY_F3:
        tz += 2;
        move = 1;
        break;
    case GLUT_KEY_F4:
        tz -= 2;
        move = 1;
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
    // Muda o angulo de rota��o, e se chegar a 360, passa para zero
    if (++angsol > 360.0f)
        angsol = 0.0f;

    angsol += 10;
    if (rotbb)
        rotb += 5;


    if (++MoveNuvem>350)
    {
        MoveNuvem = -350;
    }
    MoveNuvem += 2;


    if(++MoveAviao>50)
    {
        MoveAviao = -50;
    }
    MoveAviao += 1;


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

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

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

    dx = 0;
    dy = 0;
    dz = 0;

    tx = 0;
    ty = 0;
    tz = 0;

    dia = 0;
    MoveNuvem = 0;
    MoveAviao = 0;
    viraCarro = 0;

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

    glutTimerFunc(60, Anima, 1);

    // Inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();

    return 0;
}
