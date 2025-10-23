//////////// IMPLEMENTA FILA COM LISTA LIGADA ///////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    int numero;
    struct no *proximo; // Ponteiro NO
} NoListaLigada;


void enfileirar( NoListaLigada **cabecaFila, int valor ) {   // Insere o elemento no final da lista
    NoListaLigada *novoNo=NULL;
    NoListaLigada *p=NULL;

    novoNo = malloc( sizeof(NoListaLigada) );  // Alocando memoria para o NO
    if(!novoNo) {
        printf("Erro de alocação de memória");
        exit(-1);
    }

    novoNo->numero = valor;
    novoNo->proximo = NULL;

    p = *cabecaFila;   // Insere elemento ao final da lista

    if(p==NULL) {    // se lista vazia, é o primeiro NO
        *cabecaFila = novoNo;
        return;
    }
    while( p->proximo!=NULL ){  // se lista não vazia, percorre ela até o final e insere lá
        p = p->proximo;
    }
    p->proximo = novoNo;
}

int desinfileirar( NoListaLigada **cabecaFila ) {    // Remove o elemento do início da fila
    NoListaLigada *temp;
    int val;

    if( *cabecaFila==NULL ) {
        printf("\nFila vazia\n");
        return -1;
    }

    temp = *cabecaFila;
    val = temp->numero;
    *cabecaFila = temp->proximo;
    free(temp);
    return val;
}


int filaVazia(NoListaLigada *cabecaFila) {   // Checa se a fila está vazia
    return !cabecaFila;
}


int peek(NoListaLigada *cabecaFila, int *valor) {   // Retorna o primeiro elemento da fila (sem removê-lo)
    if (filaVazia(cabecaFila)) {
        return 0;  
    }
    *valor = cabecaFila->numero;
    return 1;     
}


void clear_stdin_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    NoListaLigada *fila = NULL;
    int valor;
    char op = 0;

    while (op != 'X') {
        printf("\nQual operação Enfileirar(E), Desinfileirar(D), Peek(P), FilaVazia(F) ou Sair(X): ");
        scanf(" %c", &op);
        op = toupper(op);
        clear_stdin_buffer();
        printf("Entrou com: %c\n", op);

        switch (op) {
            case 'E':
                printf("Entre com valor: ");
                scanf("%d", &valor);
                clear_stdin_buffer();
                enfileirar(&fila, valor);
                break;
            case 'D':
                valor = desinfileirar(&fila);
                if (valor != -1)
                    printf("Valor removido: %d\n", valor);
                else
                    printf("Fila vazia\n");
                break;
            case 'P':
                if (peek(fila, &valor))
                    printf("Valor na frente da fila: %d\n", valor);
                else
                    printf("Fila vazia\n");
                break;
            case 'F':   
                if (filaVazia(fila))
                    printf("A fila está vazia\n");
                else
                    printf("A fila não está vazia\n");
                break;
            case 'X':
                break;
            default:
                printf("Opção inválida: %c\n", op);
                break;
        }
    }

    return 0;
}