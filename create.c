#include <stdio.h>

void gerar_regra_von_koch(int estagio, int n) {
    // Condição de parada
    if (estagio == n) {
        return;
    }
    // Escreve a sequência de caracteres para o estágio atual
    if (estagio == 0) {
        printf("F-F++F-F");
    } else {
        printf("F-F++F-F");
        gerar_regra_von_koch(estagio + 1, n);
        printf("++");
        gerar_regra_von_koch(estagio + 1, n);
        printf("F-F--F-F");
        gerar_regra_von_koch(estagio + 1, n);
        printf("--");
        gerar_regra_von_koch(estagio + 1, n);
        printf("F-F++F-F");
    }
}

int main() {
    int n = 4; // número de estágios desejado
    FILE *arquivo;
    arquivo = fopen("regra_von_koch.txt", "w"); // cria um arquivo .txt para escrita
    gerar_regra_von_koch(0, n);
    fclose(arquivo);
    return 0;
}
