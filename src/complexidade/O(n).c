#include <stdio.h>

void imprimeTodos(int arr[], int n) {
    // Percorre o array uma única vez
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    imprimeTodos(vetor, tamanho);
    return 0;
}
