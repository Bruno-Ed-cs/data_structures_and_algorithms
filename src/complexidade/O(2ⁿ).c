#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5;
    printf("Fibonacci de %d: %d\n", n, fibonacci(n));
    return 0;
}
/*Cada chamada de Fibonacci gera duas novas chamadas, formando uma árvore binária.

Para fibonacci(5) já são 31 chamadas!

Complexidade: O(2ⁿ)*/