#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
void init(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

float Material(float tecla);
//vamos a definir un color predeterminado para la tetera en este caso es el dorado
GLfloat AmX = 0.329412f;
GLfloat AmY = 0.223529f;
GLfloat AmZ = 0.027451f;
GLfloat DiX = 0.780392f;
GLfloat DiY = 0.568627f;
GLfloat DiZ = 0.113725f;
GLfloat SpX = 0.992157f;
GLfloat SpY = 0.941176f;
GLfloat SpZ = 0.807843f;
GLfloat SH = 27.8974f;


void display(void)
{
    //ambient difuse y specualar reciben paraetros 
    GLfloat mat_ambient[] = { AmX, AmY, AmZ,1.0f };
    GLfloat mat_diffuse[] = { DiX, DiY, DiZ, 1.0f };
    GLfloat mat_specular[] = { SpX, SpY, SpZ, 1.0f };
    GLfloat shine[] = {SH};
// "Limpiamos" el frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
    glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
    glutSolidTeapot(125.0);
    glFlush();
}




void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 49:
        AmX = 0.135;
        AmY = 0.2225;
        AmZ = 0.1575;
        DiX = 0.54;
        DiY = 0.89;
        DiZ = 0.63;
        SpX = 0.316228;
        SpY = 0.316228;
        SpZ = 0.316228;
        SH = 0.1;
        break;
    case 50:
        AmX = 0.05375;
        AmY = 0.05;
        AmZ = 0.06625;
        DiX = 0.18275;
        DiY = 0.17;
        DiZ = 0.22525;
        SpX = 0.332741;
        SpY = 0.328634;
        SpZ = 0.346435;
        SH = 0.3;
        break;
    case 51:
        AmX = 0.25;
        AmY = 0.20725;
        AmZ = 0.20725;
        DiX = 0.1;
        DiY = 0.829;
        DiZ = 0.829;
        SpX = 0.296648;
        SpY = 0.296648;
        SpZ = 0.296648;
        SH = 0.088;
        break;
    case 52:
        AmX = 0.1745;
        AmY = 0.01175;
        AmZ = 0.01175;
        DiX = 0.61424;
        DiY = 0.04136;
        DiZ = 0.04136;
        SpX = 0.727811;
        SpY = 0.626959;
        SpZ = 0.626959;
        SH = 0.6;
        break;
    case 53:
        AmX = 0.1;
        AmY = 0.18725;
        AmZ = 0.1745;
        DiX = 0.396;
        DiY = 0.74151;
        DiZ = 0.69102;
        SpX = 0.297254;
        SpY = 0.30829;
        SpZ = 0.306678;
        SH = 0.1;
        break;
    
    case 54: //para retornar al color original
    AmX = 0.329412f;
    AmY = 0.223529f;
    AmZ = 0.027451f;
    DiX = 0.780392f;
    DiY = 0.568627f;
    DiZ = 0.113725f;
    SpX = 0.992157f;
    SpY = 0.941176f;
    SpZ = 0.807843f;
    SH = 27.8974f;
    break;
   
}

    glutPostRedisplay();
}






int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tetera");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
