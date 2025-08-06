#include <stdio.h>

void imprimePares(int arr[], int n) {
    // Dois loops aninhados percorrem o array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Par: (%d, %d)\n", arr[i], arr[j]);
        }
    }
}

int main() {
    int vetor[3] = {1, 2, 3};
    int tamanho = 3;
    imprimePares(vetor, tamanho);
    return 0;

}
