#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 50

typedef struct {
    char username[30];
    char password[30];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

void cadastrarUsuario() {
    if (totalUsuarios < MAX_USUARIOS) {
        Usuario u;
        printf("Digite o nome de usuario: ");
        scanf(" %[^\n]", u.username);
        printf("Digite a senha: ");
        scanf(" %[^\n]", u.password);

        usuarios[totalUsuarios++] = u;
        printf("Usuario cadastrado com sucesso!\n");
    } else {
        printf("Limite de usuarios atingido!\n");
    }
}

int autenticarUsuario() {
    char username[30], password[30];
    printf("Digite o nome de usuario: ");
    scanf(" %[^\n]", username);
    printf("Digite a senha: ");
    scanf(" %[^\n]", password);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].username, username) == 0 &&
            strcmp(usuarios[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int opcao;

    do {
        printf("\nMenu do Sistema de Login:\n");
        printf("1 - Cadastrar Usuario\n");
        printf("2 - Fazer Login\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                if (autenticarUsuario()) {
                    printf("Login realizado com sucesso!\n");
                } else {
                    printf("Usuario ou senha invalidos!\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}