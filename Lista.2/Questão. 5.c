#include <stdio.h>


int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int a = 0, b = 1, temp;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int n;

    printf("Digite o valor de n (n >= 0): ");
    while (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada invalida! Por favor, insira um numero inteiro nao negativo.\n");
        while (getchar() != '\n'); 
        printf("Digite novamente o valor de n: ");
    }

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}