#include <stdio.h>
#include "reserva.h"

void exibirMenu() {
    printf("===== Sistema de Reservas =====\n");
    printf("1. Fazer Reserva\n");
    printf("2. Listar Reservas\n");
    printf("0. Sair\n");
    printf("================================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    const char *nomeArquivo = "reservas.txt";
    int opcao;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, insira um numero.\n");
            while (getchar() != '\n'); /
            continue;
        }

        getchar(); 

        switch (opcao) {
            case 1:
                fazerReserva(nomeArquivo);
                break;
            case 2:
                printf("\n===== Lista de Reservas =====\n");
                listarReservas(nomeArquivo);
                printf("=============================\n");
                break;
            case 0:
                printf("Encerrando o programa. Ate mais!\n");
                break;
            default:
                printf("Opção invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}