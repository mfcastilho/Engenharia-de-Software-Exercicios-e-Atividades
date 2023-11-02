#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>



struct  Atendimento {
    char nome[50];
    char cpf [11];
    char setor[50];
};

void cadastrarAtendimento(struct Atendimento atendimentos[], int *totaldeAtendimentos) {
	system("cls");
    struct Atendimento atendimento;
    int respMenu;

    printf("Cadastre o nome do cliente:\n");
    gets(atendimento.nome);
    fflush(stdin);

    printf("Cadastre o cpf do cliente: \n");
    gets(atendimento.cpf);
    fflush(stdin);

    printf("Escolha o setor do atendimento: \n");
    printf("1 - Abertura de Conta \n");
    printf("2 - Caixa \n");
    printf("3 - Gerente Pessoa FÃ­sica \n");
    printf("4 - Gerente Pessoa JurÃ­dica \n");
    printf("Resp:");
    scanf("%d", &respMenu);
    fflush(stdin);

    switch (respMenu) {
        case 1:
            strcpy(atendimento.setor, "Abertura de Conta");
            break;
        case 2:
            strcpy(atendimento.setor, "Caixa");
            break;
        case 3:
            strcpy(atendimento.setor, "Gerente Pessoa Física");
            break;
        case 4:
            strcpy(atendimento.setor, "Gerente Pessoa Jurídica");
            break;
    }

    atendimentos[*totaldeAtendimentos] = atendimento;
    (*totaldeAtendimentos)++;
}

void imprimirAtendimentos(struct  Atendimento atendimentos[], int *totalDeAtendimentos) {
	system("cls");
	printf("===Todos os Atendimentos===\n");
    for(int i = 0; i < *totalDeAtendimentos; i++) {
        printf("Nome: %s", atendimentos[i].nome);
        printf("\nCPF: %s", atendimentos[i].cpf);
        printf("\nTipo Atendimento - %d - %s\n", i+1, atendimentos[i].setor);
        printf("===============================\n");
    }
    system("pause");
}

void listarPorSetor(struct  Atendimento atendimentos[], int *totalDeAtendimentos) {

	system("cls");
    int respMenu;
    int c = 0;


    printf("Escolha o setor que deseja listar: \n");
    printf("1 - Abertura de Conta \n");
    printf("2 - Caixa \n");
    printf("3 - Gerente Pessoa Física \n");
    printf("4 - Gerente Pessoa Jurí­dica \n");
    printf("Resp:");
    scanf("%d", &respMenu);
    fflush(stdin);


    switch (respMenu) {
        case 1:
        	system("cls");
        	printf("===Lista de Atendimentos - Abertura de Conta===\n");
            for(int i = 0; i < *totalDeAtendimentos; i++) {
                if(strcmp(atendimentos[i].setor, "Abertura de Conta") == 0){
                    printf("Nome: %s", atendimentos[i].nome);
                    printf("\nCPF: %s", atendimentos[i].cpf);
                    printf("\nTipo Atendimento - %d - %s\n", c+1, atendimentos[i].setor);
                    printf("===============================\n");
                    c++;
                }
            }
			if(c == 0) {
                printf("Lista se encontra vazia.\n");
            }
            system("pause");
            break;
        case 2:
        	system("cls");
        	printf("===Lista de Atendimentos - Caixa===\n");
            for(int i = 0; i < *totalDeAtendimentos; i++) {
                if(strcmp(atendimentos[i].setor, "Caixa") == 0){
                    printf("Nome: %s", atendimentos[i].nome);
                    printf("\nCPF: %s", atendimentos[i].cpf);
                    printf("\nTipo Atendimento - %d - %s\n", c+1, atendimentos[i].setor);
                    printf("===============================\n");
                    c++;
                }
            }
            if(c == 0) {
                printf("Lista se encontra vazia.\n");
            }
            system("pause");
            break;
        case 3:
        	system("cls");
        	printf("===Lista de Atendimentos - Gerente Pessoa Física===\n");
            for(int i = 0; i < *totalDeAtendimentos; i++) {
                if(strcmp(atendimentos[i].setor, "Gerente Pessoa Física") == 0){
                    printf("Nome: %s", atendimentos[i].nome);
                    printf("\nCPF: %s", atendimentos[i].cpf);
                    printf("\nTipo Atendimento - %d - %s\n", c+1, atendimentos[i].setor);
                    printf("===============================\n");
                    c++;

                }
            }
            if(c == 0) {
                printf("Lista se encontra vazia.\n");
            }
            system("pause");
            break;
        case 4:
        	system("cls");
        	printf("===Lista de Atendimentos - Gerente Pessoa Jurídica===\n");
            for(int i = 0; i < *totalDeAtendimentos; i++) {
                if(strcmp(atendimentos[i].setor, "Gerente Pessoa Jurídica") == 0){
                    printf("Nome: %s", atendimentos[i].nome);
                    printf("\nCPF: %s", atendimentos[i].cpf);
                    printf("\nTipo Atendimento - %d - %s\n", c+1, atendimentos[i].setor);
                    printf("===============================\n");
                    c++;
                }
            }
            if(c == 0) {
                printf("Lista se encontra vazia.\n");
            }
            system("pause");
            break;
        default:
            printf("Opção inválida.");
            break;
    }
}


int main() {

    setlocale(LC_ALL, "");

    int tamanhoArrayAtendimento = 100;
    int totalDeAtendimentos = 0;
     //    struct Atendimento  *atendimentos = malloc(tamanhoArrayAtendimento * sizeof(struct Atendimento));

    struct Atendimento  atendimentos[tamanhoArrayAtendimento];


    int respMenu;

    bool rodandoMenu = true;

    while (rodandoMenu == true) {
    	system("cls");
        printf("Bem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");
        printf("Resp:");
        scanf("%d", &respMenu);
        getchar();

        switch (respMenu) {
            case 1:
                cadastrarAtendimento(atendimentos, &totalDeAtendimentos);
                break;
            case 2:
                imprimirAtendimentos(atendimentos, &totalDeAtendimentos);
                break;
            case 3:
                listarPorSetor(atendimentos, &totalDeAtendimentos);
                break;
            case 4:
                rodandoMenu = false;
                break;
            default:
                printf("Opção inválida.");
                break;
        }
    }
    
    printf("Programa finalizado...");


    return 0;
}

