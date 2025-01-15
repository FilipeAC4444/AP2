#include <stdio.h>
#include <string.h>


struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

struct Aluno {
    char nome[50];
    int matricula;
    float nota1, nota2;
};

struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
};

struct Produto {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
};

void cadastrarFuncionario() {
    struct Funcionario func;

    printf("\n--- Cadastro de Funcionario ---\n");
    printf("Nome: ");
    fgets(func.nome, 50, stdin);
    func.nome[strcspn(func.nome, "\n")] = 0; 

    printf("Idade: ");
    scanf("%d", &func.idade);

    printf("Salario: ");
    scanf("%f", &func.salario);

    printf("\n--- Informacoes do Funcionario ---\n");
    printf("Nome: %s\nIdade: %d\nSalario: %.2f\n", func.nome, func.idade, func.salario);
}

void cadastrarAluno() {
    struct Aluno aluno;

    printf("\n--- Cadastro de Aluno ---\n");
    getchar(); 
    printf("Nome: ");
    fgets(aluno.nome, 50, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = 0;

    printf("Matricula: ");
    scanf("%d", &aluno.matricula);

    printf("Nota 1: ");
    scanf("%f", &aluno.nota1);

    printf("Nota 2: ");
    scanf("%f", &aluno.nota2);

    float media = (aluno.nota1 + aluno.nota2) / 2;

    printf("\n--- Informacoes do Aluno ---\n");
    printf("Nome: %s\nMatricula: %d\nMedia: %.2f\n", aluno.nome, aluno.matricula, media);
}

void cadastrarLivro() {
    struct Livro livro;

    printf("\n--- Cadastro de Livro ---\n");
    getchar(); // Limpa buffer do teclado
    printf("Titulo: ");
    fgets(livro.titulo, 100, stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(livro.autor, 50, stdin);
    livro.autor[strcspn(livro.autor, "\n")] = 0;

    printf("Ano de Publicacao: ");
    scanf("%d", &livro.ano_publicacao);

    printf("\n--- Informações do Livro ---\n");
    printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n", livro.titulo, livro.autor, livro.ano_publicacao);
}

void cadastrarProduto() {
    struct Produto produto;

    printf("\n--- Cadastro de Produto ---\n");
    getchar(); 
    printf("Nome: ");
    fgets(produto.nome, 50, stdin);
    produto.nome[strcspn(produto.nome, "\n")] = 0;

    printf("Codigo: ");
    scanf("%d", &produto.codigo);

    printf("Preco: ");
    scanf("%f", &produto.preco);

    printf("Quantidade: ");
    scanf("%d", &produto.quantidade);

    float valorTotal = produto.preco * produto.quantidade;

    printf("\n--- Informacoes do Produto ---\n");
    printf("Nome: %s\nCódigo: %d\nValor Total em Estoque: %.2f\n", produto.nome, produto.codigo, valorTotal);
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Cadastrar Aluno\n");
        printf("3. Cadastrar Livro\n");
        printf("4. Cadastrar Produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario();
                break;
            case 2:
                cadastrarAluno();
                break;
            case 3:
                cadastrarLivro();
                break;
            case 4:
                cadastrarProduto();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
