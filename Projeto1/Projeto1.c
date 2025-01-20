#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

typedef struct {
    int id;
    char nome[100];
    char email[100];
} Usuario;

typedef struct {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int totalLivros;
    int totalUsuarios;
} Biblioteca;

void adicionarLivro(Biblioteca *biblioteca);
void adicionarUsuario(Biblioteca *biblioteca);
void listarLivros(Biblioteca *biblioteca);
void listarUsuarios(Biblioteca *biblioteca);
int buscarLivroRec(Biblioteca *biblioteca, char *titulo, int index);

int main() {
    Biblioteca biblioteca = { .totalLivros = 0, .totalUsuarios = 0 };
    int opcao;

    do {
        printf("\n--- Sistema de Gerenciamento de Biblioteca ---\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Usuario\n");
        printf("3. Listar Livros\n");
        printf("4. Listar Usuarios\n");
        printf("5. Buscar Livro\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                adicionarLivro(&biblioteca);
                break;
            case 2:
                adicionarUsuario(&biblioteca);
                break;
            case 3:
                listarLivros(&biblioteca);
                break;
            case 4:
                listarUsuarios(&biblioteca);
                break;
            case 5: {
                char titulo[100];
                printf("Digite o titulo do livro para buscar: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; 
                int resultado = buscarLivroRec(&biblioteca, titulo, 0);
                if (resultado == -1) {
                    printf("Livro nao encontrado.\n");
                } else {
                    printf("Livro encontrado: %s, Autor: %s, Ano: %d\n",
                           biblioteca.livros[resultado].titulo,
                           biblioteca.livros[resultado].autor,
                           biblioteca.livros[resultado].ano);
                }
                break;
            }
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

void adicionarLivro(Biblioteca *biblioteca) {
    if (biblioteca->totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido.\n");
        return;
    }

    Livro novoLivro;
    novoLivro.id = biblioteca->totalLivros + 1;

    printf("Digite o titulo do livro: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0'; 

    printf("Digite o ano do livro: ");
    scanf("%d", &novoLivro.ano);
    getchar(); 

    biblioteca->livros[biblioteca->totalLivros] = novoLivro;
    biblioteca->totalLivros++;

    printf("Livro adicionado com sucesso!\n");
}

void adicionarUsuario(Biblioteca *biblioteca) {
    if (biblioteca->totalUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.id = biblioteca->totalUsuarios + 1;

    printf("Digite o nome do usuario: ");
    fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0'; 

    printf("Digite o email do usuario: ");
    fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
    novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0'; 

    biblioteca->usuarios[biblioteca->totalUsuarios] = novoUsuario;
    biblioteca->totalUsuarios++;

    printf("Usuario adicionado com sucesso!\n");
}

void listarLivros(Biblioteca *biblioteca) {
    if (biblioteca->totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Livros ---\n");
    for (int i = 0; i < biblioteca->totalLivros; i++) {
        Livro livro = biblioteca->livros[i];
        printf("ID: %d, Titulo: %s, Autor: %s, Ano: %d\n", 
               livro.id, livro.titulo, livro.autor, livro.ano);
    }
}

void listarUsuarios(Biblioteca *biblioteca) {
    if (biblioteca->totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Usuarios ---\n");
    for (int i = 0; i < biblioteca->totalUsuarios; i++) {
        Usuario usuario = biblioteca->usuarios[i];
        printf("ID: %d, Nome: %s, Email: %s\n", 
               usuario.id, usuario.nome, usuario.email);
    }
}

int buscarLivroRec(Biblioteca *biblioteca, char *titulo, int index) {
    if (index >= biblioteca->totalLivros) {
        return -1; 
    }

    if (strcmp(biblioteca->livros[index].titulo, titulo) == 0) {
        return index; 
    }

    return buscarLivroRec(biblioteca, titulo, index + 1); 
}
