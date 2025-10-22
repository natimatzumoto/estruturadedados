#### Recebe um número inteiro N de valores a serem submetidos e a série de N números. Retorna os valores máximo e mínimo, a média, a mediana, 
o desvio-padrão (populacional) dos valores. ####



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num;

    float soma = 0.0;
    float *vetor;

    printf("\nQuantos números na sua série (N): ");
    scanf("%d", &num);

    vetor = malloc(num * sizeof(float));
    if (vetor == NULL) { //ERRO DE ALOCAÇÃO DE MEMÓRIA!
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA!\n");
        exit(-1);
    }

    printf("Entre com os números:\n");
    for (int i = 0; i < num; i++) {
        printf("> ");
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    float media = soma / num; // DEFININDO A MÉDIA

    float minimo = vetor[0];
    float maximo = vetor[0];
    for (int i = 1; i < num; i++) { // DEFININDO MÍNIMO E MÁXIMO
        if (vetor[i] < minimo) minimo = vetor[i];
        if (vetor[i] > maximo) maximo = vetor[i];
    }

    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                float temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp; // ORDENANDO OS TERMOS
            }
        }
    }

    float mediana; // DEFININDO MEDIANA
    if (num % 2 == 0) {
        mediana = (vetor[num/2 - 1] + vetor[num/2]) / 2.0f;
    } else {
        mediana = vetor[num/2];
    }

    float variancia = 0.0; // DEFININDO VARIÂNCIA
    for (int i = 0; i < num; i++) {
        variancia += powf(vetor[i] - media, 2.0f);
    }
    variancia /= (num - 1);
    float dp = sqrtf(variancia); // DEFININDO DESVIO-PADRÃO

    printf("\nValor mínimo: %.2f\n", minimo);
    printf("Valor máximo: %.2f\n", maximo);
    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desvio padrão: %.6f\n", dp);

    free(vetor); // LIBERANDO ESPAÇO

    return 0;
}
