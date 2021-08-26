/*  Alexis tercero: https://github.com/AlexisTercero55
    run command: gcc plantilla.c -lfreeglut -lopengl32
    build task@\.vscode\task.json : ctrl + shift + b
*/
#include <stdlib.h>
#include <GL/glut.h>

void dibujar(void);
void teclado (unsigned char key, int x, int y);

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    //configuracion de pantalla
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Practica 1: Alexis Tercero");
    //registro y ejecuccion de procesos
    glutDisplayFunc(dibujar);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    return 0;
}

void dibujar(void) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*ponga aqui sus primitivas OpenGL*/
    glutSwapBuffers();
}

void teclado (unsigned char key, int x, int y) 
{
    switch (key) 
    {
        case 27: //scape in ASCII
            exit(0);
            break;
    }
}