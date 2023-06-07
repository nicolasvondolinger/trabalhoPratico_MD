#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITERATIONS 4  // Número de iterações desejadas
#define MAX_STRING_SIZE 100000  // Tamanho máximo da string
#define MAX_RULES 10  // Número máximo de regras

// Estrutura para armazenar uma regra
typedef struct {
    char symbol;
    char replacement[MAX_STRING_SIZE];
} Rule;

// Função para aplicar as regras e gerar a nova string
void applyRules(char *source, char *destination, Rule *rules, int numRules) {
    int i, j;
    char c;
    int ruleMatched;
    
    for (i = 0; i < strlen(source); i++) {
        c = source[i];
        ruleMatched = 0;
        
        for (j = 0; j < numRules; j++) {
            if (c == rules[j].symbol) {
                strcat(destination, rules[j].replacement);
                ruleMatched = 1;
                break;
            }
        }
        
        if (!ruleMatched) {
            strncat(destination, &c, 1);
        }
    }
}

int main() {
    int fractalNumber;
    char axiom[MAX_STRING_SIZE];
    int angle;
    Rule rules[MAX_RULES];
    int numRules;
    
    printf("Entrada 1 - Número do fractal correspondente: ");
    scanf("%d", &fractalNumber);
    
    printf("Entrada 2 - Axioma: ");
    scanf("%s", axiom);
    
    printf("Entrada 3 - Ângulo dado em graus: ");
    scanf("%d", &angle);
    
    printf("Entrada 4 - Número de regras: ");
    scanf("%d", &numRules);
    
    printf("Entrada das regras (símbolo e substituição separados por espaço):\n");
    for (int i = 0; i < numRules; i++) {
        printf("Regra %d: ", i + 1);
        scanf(" %c %s", &rules[i].symbol, rules[i].replacement);
    }
    
    char *result = (char *)malloc(MAX_STRING_SIZE * sizeof(char));  // String final do fractal
    memset(result, 0, MAX_STRING_SIZE);
    
    FILE *file = fopen("fractal.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            fprintf(file, "Iteração %d\n", i + 1);
            applyRules(axiom, result, rules, numRules);
            strncpy(axiom, result, MAX_STRING_SIZE - 1);
            memset(result, 0, MAX_STRING_SIZE);
            
            if (i == MAX_ITERATIONS - 1) {
                // Imprimir a última etapa sem 'X' e 'Y'
                for (int j = 0; j < strlen(axiom); j++) {
                    if (axiom[j] == 'X' || axiom[j] == 'Y') {
                        continue;
                    }
                    fprintf(file, "%c", axiom[j]);
                }
            } else {
                fprintf(file, "%s", axiom);
            }
            fprintf(file, "\n");
        }
        
        fclose(file);
        printf("Fractal gerado com sucesso e salvo no arquivo 'fractal.txt'.\n");
    } else {
        printf("Erro ao criar o arquivo.\n");
    }
    
    free(result);
    
    return 0;
}
