#include <stdio.h>
#include <math.h>

#define WIDTH 80    // largura do terminal
#define HEIGHT 24   // altura do terminal
#define PI 3.14159265359

void clear_screen() {
    printf("\033[H\033[J"); // limpa o terminal
}

int main() {
    double A = 0, B = 0; // ângulos de rotação
    double cA = cos(A), sA = sin(A);
    double cB = cos(B), sB = sin(B);

    while (1) {
        double z[HEIGHT][WIDTH] = {0}; // matriz para armazenar a profundidade dos pontos

        // calcular a rosquinha (toroide)
        for (double j = 0; j < 6.28; j += 0.07) { // ângulo theta
            for (double i = 0; i < 6.28; i += 0.02) { // ângulo phi
                double c = sin(i);
                double d = cos(j);
                double e = sin(A);
                double f = sin(j);
                double g = cos(A);
                double h = d + 2;
                double D = 1 / (c * h * e + f * g + 5);
                double l = cos(i);
                double m = cos(B);
                double n = sin(B);
                double t = c * h * g - f * e;

                int x = WIDTH / 2 + 10 * D * (l * h * m - t * n);
                int y = HEIGHT / 2 + 15 * D * (l * h * n + t * m);
                int o = x + WIDTH * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                if (HEIGHT > y && y > 0 && x > 0 && WIDTH > x && D > z[o]) {
                    z[o] = D;
                    printf("\033[%d;%dH", y, x);
                    putchar(N > 0 ? ".,-~:;=!*#$@"[N] : ' ');
                }
            }
        }

        // ajustar ângulos para a próxima iteração
        A += 0.04;
        B += 0.02;
        cA = cos(A);
        sA = sin(A);
        cB = cos(B);
        sB = sin(B);

        // pausa para a animação ser visível
        usleep(30000);

        // limpar a tela para o próximo quadro
        clear_screen();
    }

    return 0;
}