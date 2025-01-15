#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

void adicionarAluno() {
    if (totalAlunos < MAX_ALUNOS) {
        Aluno a;
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", a.nome);
        printf("Digite a matrícula do aluno: ");
        scanf("%d", &a.matricula);
        printf("Digite a primeira nota: ");
        scanf("%f", &a.nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &a.nota2);

        alunos[totalAlunos++] = a;
        printf("Aluno adicionado com sucesso!\n");
    } else {
        printf("Limite de alunos atingido!\n");
    }
}

void listarAlunos() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }

    printf("\nLista de Alunos:\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("Nome: %s, Matrícula: %d, Nota 1: %.2f, Nota 2: %.2f\n",
               alunos[i].nome, alunos[i].matricula, alunos[i].nota1, alunos[i].nota2);
    }
}

void calcularMedia() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado para calcular a média!\n");
        return;
    }

    for (int i = 0; i < totalAlunos; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
        printf("Aluno: %s, Matrícula: %d, Média: %.2f\n",
               alunos[i].nome, alunos[i].matricula, media);
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu de Gerenciamento de Alunos:\n");
        printf("1 - Adicionar Aluno\n");
        printf("2 - Listar Alunos\n");
        printf("3 - Calcular Média das Notas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                calcularMedia();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}