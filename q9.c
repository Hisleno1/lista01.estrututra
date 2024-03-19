#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <GL/glut.h>

// Definindo os vértices do triângulo
float A[] = {0.0, 1.0};
float B[] = {-1.0, -1.0};
float C[] = {1.0, -1.0};

// Função para calcular o ponto médio entre dois pontos
void ponto_medio(float p1[], float p2[], float result[]) {
    result[0] = (p1[0] + p2[0]) / 2.0;
    result[1] = (p1[1] + p2[1]) / 2.0;
}

// Função para desenhar um ponto
void desenhar_ponto(float p[]) {
    glBegin(GL_POINTS);
    glVertex2f(p[0], p[1]);
    glEnd();
}

// Função para escolher um ponto aleatório dentro do triângulo
void ponto_aleatorio(float result[]) {
    float r1 = (float)rand() / RAND_MAX;
    float r2 = (float)rand() / RAND_MAX;
    if (r1 + r2 >= 1) {
        result[0] = (1 - r1) * A[0] + (r1 - r2) * B[0] + r2 * C[0];
        result[1] = (1 - r1) * A[1] + (r1 - r2) * B[1] + r2 * C[1];
    } else {
        result[0] = r1 * A[0] + (1 - r1 - r2) * B[0] + r2 * C[0];
        result[1] = r1 * A[1] + (1 - r1 - r2) * B[1] + r2 * C[1];
    }
}

// Função para desenhar o triângulo de Sierpinski
void sierpinski(int num_pontos) {
    float ponto_atual[2];
    ponto_aleatorio(ponto_atual);
    for (int i = 0; i < num_pontos; i++) {
        // Escolhe aleatoriamente um dos vértices do triângulo
        float* vertice;
        switch (rand() % 3) {
            case 0: vertice = A; break;
            case 1: vertice = B; break;
            case 2: vertice = C; break;
        }
        // Calcula o ponto médio entre o ponto atual e o vértice escolhido
        float ponto_novo[2];
        ponto_medio(ponto_atual, vertice, ponto_novo);
        // Desenha o ponto novo
        desenhar_ponto(ponto_novo);
        // Atualiza o ponto atual para o novo ponto calculado
        ponto_atual[0] = ponto_novo[0];
        ponto_atual[1] = ponto_novo[1];
    }
}

// Função de exibição
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Cor dos pontos (branco)
    sierpinski(10000); // Define o número de pontos a serem gerados
    glFlush();
}

// Função principal
int main(int argc, char **argv) {
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triângulo de Sierpinski");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -0.5, 1.5); // Define a região de visualização
    glClearColor(0.0, 0.0, 0.0, 1.0); // Cor de fundo preta
    glutMainLoop();
    return 0;
}
