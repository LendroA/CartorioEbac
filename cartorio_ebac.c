#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() // Função responsavel por cadastrar usuários no sistema
{
    // inicio de variáveis /string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
    scanf("%s", cpf);                          //%s refere-se a string

    strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings

    FILE *file;                 // Cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "W" de write  siginifica escrever
    fprintf(file, "%s", cpf);   // Salva o valor da variavel
    fclose(file);               // Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Arquivo não localizado ");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    //remove(cpf)

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O usuário não se encontra no sistema! \n");
        system("pause");
        return 0;
    }

    fclose(file);

    if (remove(cpf) == 0)
    {
        printf("Usuário deletado com sucesso!\n");
    }

    else
    {
        printf("Erro ao remover arquivo.\n");
    }

    system("pause");
    return 0;
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;
    for (laco = 1; laco == 1;)
    {

        system("cls");

        setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

        printf("### Cartório da EBAC ###\n\n"); // Inicío do menu
        printf("Escolha a opção desejado no menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");

        printf("opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenamento de escolha do usuário

        system("cls"); // Responsavel por limpar a tela, ele vai deletar tudo aquilo que estiver escrito

        switch (opcao) // inicio da seleção do menu
        {
        case 1:
            registro(); // chamada de funções
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        case 4:
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;    

        default:
            printf("Essa opção não existe!\n");
            system("pause");
            break;
        }
    }
}