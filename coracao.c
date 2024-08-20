#include <stdio.h>
#include <unistd.h> // para usleep() - ajuste para Windows se necessário

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

int main() {
    int i;
    int position = 0;
    int direction = 1;
    char heart[] = "\
  ♥   ♥   \n\
 ♥♥♥♥♥♥ \n\
♥♥♥♥♥♥♥♥\n\
 ♥♥♥♥♥♥ \n\
  ♥♥♥♥  \n\
   ♥♥   ";

    // Loop para fazer o coração girar
    for (i = 0; i < 100; i++) {
        clear_screen(); // Limpa a tela antes de desenhar novamente
        printf("%*s", position, " "); // Espaços para ajustar a posição inicial

        // Imprime o coração
        printf("%s", heart);

        // Atualiza a posição para a próxima iteração
        position += direction;

        // Inverte a direção ao atingir os limites do terminal
        if (position >= 40 || position < 0) {
            direction = -direction;
        }

        // Pequena pausa para efeito visual
        usleep(100000); // Ajuste o tempo conforme necessário
    }

    return 0;
}