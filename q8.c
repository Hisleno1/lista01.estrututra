#include <GL/glut.h>

// Função para desenhar um triângulo equilátero
void desenharTriangulo(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Função recursiva para desenhar o triângulo de Sierpinski
void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int nivel) {
    if (nivel == 0) {
        // Se o nível for zero, desenha o triângulo atual
        desenharTriangulo(x1, y1, x2, y2, x3, y3);
    } else {
        // Calcula os pontos médios dos lados do triângulo
        float x12 = (x1 + x2) / 2;
        float y12 = (y1 + y2) / 2;
        float x23 = (x2 + x3) / 2;
        float y23 = (y2 + y3) / 2;
        float x31 = (x3 + x1) / 2;
        float y31 = (y3 + y1) / 2;

        // Desenha os três triângulos menores recursivamente
        sierpinski(x1, y1, x12, y12, x31, y31, nivel - 1);
        sierpinski(x12, y12, x2, y2, x23, y23, nivel - 1);
        sierpinski(x31, y31, x23, y23, x3, y3, nivel - 1);
    }
}

// Função de desenho
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Cor do triângulo (branco)
    
    // Coordenadas dos vértices do triângulo inicial
    float x1 = -1.0;
    float y1 = -1.0;
    float x2 = 1.0;
    float y2 = -1.0;
    float x3 = 0.0;
    float y3 = 1.0;
    
    // Nível de recursão
    int nivel = 4;

    // Chama a função sierpinski para desenhar o triângulo de Sierpinski
    sierpinski(x1, y1, x2, y2, x3, y3, nivel);

    glFlush();
}

// Função de inicialização
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Cor de fundo preta
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0); // Define a região de visualização
    glMatrixMode(GL_MODELVIEW);
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triângulo de Sierpinski");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
