/*  Alexis tercero: https://github.com/AlexisTercero55
    run command: gcc plantillaNotas.c -lfreeglut -lopengl32
    build task@\.vscode\task.json : ctrl + shift + b
*/
#include <GL/glut.h>
#include <stdlib.h>

void dibujar(void);
void teclado(unsigned char key, int x, int y);
void dibujar_triangulo(void);

int main(int argc, char** argv)
{
    //iniciar FreeGLUT : gestor de ventanas, (entorno de OpenGL)
    glutInit(&argc, argv);
    //especificar el tamaño de ventana (resolucion) en pixeles
    glutInitWindowSize(800, 600);
    //definir posicion inicial de pantalla
    glutInitWindowPosition(0,0);
    //crear ventana y darle un titulo
    glutCreateWindow("Practica 1: Alexis Tercero");


    /*Se requiere especificar a la ventana que es lo que va a dibujar
      mediante una funcion que procesa las primitivas, en este caso se trata de
      la funcion: void dibujar(void)*/

    //indicar a GLUT los procesos que debe realizar
    glutDisplayFunc(dibujar_triangulo);

    /*Configurar FreeGlut para recibir eventos de teclado*/
    glutKeyboardFunc(teclado);
    
    /*      El problema de las ventanas (game loop)
      Se necesita especificar que una ventana se mantenga abierta
      y empiece a procesar los eventos de dibujo e interaccion con el usuario
      mediante la funcion: glutMainLoop()*/
   glutMainLoop();

    return 0;
}
void dibujar(void)
{
    /* recurso: https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glClear.xml
    glClear — borrar búferes a valores preestablecidos
      
      Description:
        glClear sets the bitplane area of the window to values previously selected by: 
            glClearColor, 
            glClearIndex, 
            glClearDepth, 
            glClearStencil, 
            glClearAccum. 
        Multiple color buffers can be cleared simultaneously by 
        selecting more than one buffer at a time using glDrawBuffer.

      C Specification:
        void glClear(GLbitfield mask);

      glClear toma un solo argumento que es el bitwise OR de varios valores que indican qué búfer se va a borrar.
      Parametros:
        mask:
            GL_COLOR_BUFFER_BIT : Indica los búferes actualmente habilitados para 
                                  la escritura en color.
            GL_DEPTH_BUFFER_BIT : Indica el búfer de profundidad.
            GL_ACCUM_BUFFER_BIT : Indica el búfer de acumulación.
            GL_STENCIL_BUFFER_BIT : Indica el búfer de la plantilla.
    */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /*ponga aqui sus primitivas OpenGL*/

    /* recurso: https://www.opengl.org/resources/libraries/glut/spec3/node21.html
    glutSwapBuffers — intercambia los búferes de la ventana actual si tiene doble búfer.

       C Specification:
        void glutSwapBuffers(void); 
       
       Descripcion:
        Realiza un intercambio de búfer en la capa en uso para la ventana actual. 
        Específicamente, glutSwapBuffers promueve el contenido del búfer posterior 
        de la capa en uso de la ventana actual para que se convierta en el contenido del búfer frontal. 
        El contenido del búfer posterior se vuelve indefinido. La actualización suele tener lugar 
        durante el retroceso vertical del monitor, en lugar de inmediatamente después de que se llame a glutSwapBuffers.

        Un glFlush implícito lo realiza glutSwapBuffers antes de que regrese. 
        Los comandos subsiguientes de OpenGL se pueden emitir inmediatamente 
        después de llamar a glutSwapBuffers, pero no se ejecutan hasta que se completa el intercambio de búfer.

        If the layer in use is not double buffered, glutSwapBuffers has no effect.
    */
    glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: //scape in ASCII
            exit(0);//no erros
            break;
    }
}

void dibujar_triangulo(void) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(-0.5, -0.5);
        glColor3f(0, 1, 0);
        glVertex2f(0.5, -0.5);
        glColor3f(0, 0, 1);
        glVertex2f(0.0, 0.5);
      glEnd();
    glutSwapBuffers();
}