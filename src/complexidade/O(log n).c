#include <stdio.h>

// Busca binária — só funciona em arrays ordenados
int buscaBinaria(int arr[], int n, int alvo) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (arr[meio] == alvo)
            return meio;
        else if (arr[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int posicao = buscaBinaria(vetor, tamanho, 9);
    printf("Posição do elemento: %d\n", posicao);
    return 0;
}
 
/* Explicação:
A cada passo, o algoritmo divide o problema pela metade.

Exemplo: com 8 elementos, ele verifica no máximo 3 vezes (2³ = 8).

Complexidade: O(log n)*/