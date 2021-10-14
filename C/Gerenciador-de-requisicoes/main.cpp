#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
int ordenado_por = 0; // se for 1 ordenado por nome, se for 2 ordenado por CPF e se for 0 não foi ordenada
typedef struct st_Valores Valores;

struct st_Valores
{
    char Nome[25];
    char Matricula[10];
    char CPF[15];
    char Solicitacao[50];
    int Cod;
    Valores *Proximo;
};

typedef struct st_Lista
{
    Valores *Primeiro;
    Valores *Ultimo;
    int Quantidade;
    int Contador;
} Lista;
// Função para ordenação do nome por Seleção
void selectionSort_nome(Lista *L1)
{
    system("clear");
    printf("Iniciando a Ordeção por Nome!\n");
    ordenado_por = 1;
    Valores aux;
    Valores *i;
    Valores *j;
    Valores *menor;
    int tam;
    char nome1[25];
    char nome2[25];
    if (L1->Primeiro != NULL)
    {
        if (L1->Quantidade == 1)
        {
            printf("Lista Unitária-Ordenada por padrão");
        }
        for (i = L1->Primeiro; i != NULL; i = i->Proximo)
        {
            strcpy(aux.Nome, i->Nome);
            strcpy(aux.Matricula, i->Matricula);
            strcpy(aux.CPF, i->CPF);
            strcpy(aux.Solicitacao, i->Solicitacao);
            aux.Cod = i->Cod;
            menor = i;
            if (L1->Quantidade == 2)
            {
                j = i->Proximo;
                strcpy(nome1, j->Nome);
                strcpy(nome2, menor->Nome);
                tam = strcasecmp(nome2, nome1);
                if (tam > 0)
                {
                    menor = j;
                }
                strcpy(i->Nome, menor->Nome);
                strcpy(i->Matricula, menor->Matricula);
                strcpy(i->CPF, menor->CPF);
                strcpy(i->Solicitacao, menor->Solicitacao);
                i->Cod = menor->Cod;

                strcpy(menor->Nome, aux.Nome);
                strcpy(menor->Matricula, aux.Matricula);
                strcpy(menor->CPF, aux.CPF);
                strcpy(menor->Solicitacao, aux.Solicitacao);
                menor->Cod = aux.Cod;
                break;
            }
            else
            {
                for (j = i->Proximo; j != NULL; j = j->Proximo)
                {
                    strcpy(nome1, j->Nome);
                    strcpy(nome2, menor->Nome);
                    tam = strcasecmp(nome2, nome1);
                    if (tam > 0)
                    {
                        menor = j;
                    }
                }
            }
            strcpy(i->Nome, menor->Nome);
            strcpy(i->Matricula, menor->Matricula);
            strcpy(i->CPF, menor->CPF);
            strcpy(i->Solicitacao, menor->Solicitacao);
            i->Cod = menor->Cod;

            strcpy(menor->Nome, aux.Nome);
            strcpy(menor->Matricula, aux.Matricula);
            strcpy(menor->CPF, aux.CPF);
            strcpy(menor->Solicitacao, aux.Solicitacao);
            menor->Cod = aux.Cod;
        }
        printf("Lista Ordenada Com Sucesso\n");
    }
}
// Função para ordenação do cpf por Seleção
void selectionSort_cpf(Lista *L1)
{
    system("clear");
    printf("Iniciando a Ordeção por CPF!\n");
    ordenado_por = 2;
    Valores aux;
    Valores *i;
    Valores *j;
    Valores *menor;
    int tam;
    char CPF1[15];
    char CPF2[15];
    if (L1->Primeiro != NULL)
    {
        if (L1->Quantidade == 1)
        {
            printf("Lista Unitária-Ordenada por padrão");
        }
        for (i = L1->Primeiro; i != NULL; i = i->Proximo)
        {
            strcpy(aux.Nome, i->Nome);
            strcpy(aux.Matricula, i->Matricula);
            strcpy(aux.CPF, i->CPF);
            strcpy(aux.Solicitacao, i->Solicitacao);
            aux.Cod = i->Cod;
            menor = i;
            if (L1->Quantidade == 2)
            {
                j = i->Proximo;
                strcpy(CPF1, j->CPF);
                strcpy(CPF2, menor->CPF);
                tam = strcasecmp(CPF2, CPF1);
                if (tam > 0)
                {
                    menor = j;
                }

                strcpy(i->Nome, menor->Nome);
                strcpy(i->Matricula, menor->Matricula);
                strcpy(i->CPF, menor->CPF);
                strcpy(i->Solicitacao, menor->Solicitacao);
                i->Cod = menor->Cod;

                strcpy(menor->Nome, aux.Nome);
                strcpy(menor->Matricula, aux.Matricula);
                strcpy(menor->CPF, aux.CPF);
                strcpy(menor->Solicitacao, aux.Solicitacao);
                menor->Cod = aux.Cod;
                break;
            }
            else
            {
                for (j = i->Proximo; j != NULL; j = j->Proximo)
                {
                    strcpy(CPF1, j->CPF);
                    strcpy(CPF2, menor->CPF);
                    tam = strcasecmp(CPF2, CPF1);
                    if (tam > 0)
                    {
                        menor = j;
                    }
                }
            }
            strcpy(i->Nome, menor->Nome);
            strcpy(i->Matricula, menor->Matricula);
            strcpy(i->CPF, menor->CPF);
            strcpy(i->Solicitacao, menor->Solicitacao);
            i->Cod = menor->Cod;

            strcpy(menor->Nome, aux.Nome);
            strcpy(menor->Matricula, aux.Matricula);
            strcpy(menor->CPF, aux.CPF);
            strcpy(menor->Solicitacao, aux.Solicitacao);
            menor->Cod = aux.Cod;
        }
        printf("Lista Ordenada Com Sucesso\n");
    }
}
//função para inserir alunos
void Inserir_Lista(Lista *L1)
{
    system("clear");
    char Nome[25];
    char Matricula[10];
    char CPF[15];
    int Solicitacao;
    int Cod;
    int opcao;
    opcao = 2;
    Valores *Alunos;
    Alunos = (Valores *)calloc(1, sizeof(Valores));

    system("clear");
    setbuf(stdin, NULL);
    printf("Nome: ");
    scanf("%s", Nome);
    setbuf(stdin, NULL);
    printf("Matrícula: ");
    scanf("%s", Matricula);
    setbuf(stdin, NULL);
    printf("CPF: ");
    scanf("%s", CPF);
    setbuf(stdin, NULL);
    opcao = 2;
    strcpy(Alunos->Nome, Nome);
    strcpy(Alunos->Matricula, Matricula);
    strcpy(Alunos->CPF, CPF);

    while (opcao == 2)
    {
        printf("Escolha a Solicitacao:\n");
        printf("1-Rematrícula\n2-Transferência\n3-Trancamento de Curso\n4-Registro de Documentos\n5-Pedido de Auxílio\nOpção: ");
        setbuf(stdin, NULL);
        scanf("%d", &Solicitacao);

        switch (Solicitacao)
        {
        case 1:
            strcpy(Alunos->Solicitacao, "Rematrícula");
            opcao = 1;
            break;
        case 2:
            strcpy(Alunos->Solicitacao, "Transferência");
            opcao = 1;
            break;
        case 3:
            strcpy(Alunos->Solicitacao, "Trancamento de Curso");
            opcao = 1;
            break;
        case 4:
            strcpy(Alunos->Solicitacao, "Registro de Documentos");
            opcao = 1;
            break;
        case 5:
            strcpy(Alunos->Solicitacao, "Pedido de Auxílio");
            opcao = 1;
            break;
        default:
            printf("Opção Inválida\n\n");
            opcao = 2;
            break;
        }
    }

    Alunos->Cod = L1->Contador + 1;
    Alunos->Proximo = NULL;

    if (L1->Primeiro == NULL)
    {
        L1->Primeiro = Alunos;
        L1->Ultimo = Alunos;
    }
    else
    {
        L1->Ultimo->Proximo = Alunos;
        L1->Ultimo = Alunos;
    }
    L1->Quantidade = L1->Quantidade + 1;
    L1->Contador = L1->Contador + 1;
}

//função para listar os consultórios
void Listar_Lista(Valores *temp, Lista L1)
{
    system("clear");
    printf("Há %d solicitações\n", L1.Quantidade);
    temp = L1.Primeiro;
    while (temp != NULL)
    {
        printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n\n", temp->Nome, temp->Matricula, temp->CPF, temp->Solicitacao, temp->Cod);
        temp = temp->Proximo;
    }
}

//remover da lista
int Remover_Lista(Lista *L1)
{
    system("clear");
    Valores *anterior, *proximo, *atual;
    int cont = 1;
    int cod_deletar;
    atual = L1->Primeiro;
    int tam;
    char CPF_busca[15];
    char CPF[15];
    char Nome_busca[25];
    char nome[25];

    if (L1->Quantidade == 0)
    {
        printf("Não existem elementos na lista");
        return 0;
    }
    else if (L1->Quantidade == 1)
    {
        printf("Removendo Cadastro: \n");
        printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", atual->Nome, atual->Matricula, atual->CPF, atual->Solicitacao, atual->Cod);
        L1->Primeiro = NULL;
        L1->Ultimo = NULL;
        free(atual);
        L1->Quantidade--;
        return 0;
    }
    else if (ordenado_por == 1)
    {
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%s", Nome_busca);

        strcpy(nome, atual->Nome);
        tam = strcasecmp(Nome_busca, nome);
        if (tam == 0)
        {
            printf("Removendo Cadastro: \n");
            printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", atual->Nome, atual->Matricula, atual->CPF, atual->Solicitacao, atual->Cod);
            L1->Primeiro = atual->Proximo;
            free(atual);
            L1->Quantidade--;
            return 0;
        }
        else if (L1->Quantidade > 1)
        {
            while (atual != NULL)
            {
                strcpy(nome, atual->Nome);
                tam = strcasecmp(Nome_busca, nome);
                if (tam == 0)
                {
                    printf("Removendo Cadastro: \n");
                    printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", atual->Nome, atual->Matricula, atual->CPF, atual->Solicitacao, atual->Cod);
                    anterior->Proximo = atual->Proximo;
                    free(atual);
                    L1->Quantidade--;
                    printf("Solicitação removida com sucesso");
                    return true;
                }
                else if (tam < 0)
                {
                    printf("Busca não encontrada!");
                    return 0;
                }
                anterior = atual;
                atual = atual->Proximo;
            }
            return 0;
        }
    }
    else if (ordenado_por == 2)
    {
        printf("CPF: ");
        setbuf(stdin, NULL);
        scanf("%s", CPF_busca);

        strcpy(CPF, atual->CPF);
        tam = strcasecmp(CPF_busca, CPF);
        if (tam == 0)
        {
            printf("Removendo Cadastro: \n");
            printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", atual->Nome, atual->Matricula, atual->CPF, atual->Solicitacao, atual->Cod);
            L1->Primeiro = atual->Proximo;
            free(atual);
            L1->Quantidade--;
            return 0;
        }
        else if (L1->Quantidade > 1)
        {
            while (atual != NULL)
            {
                strcpy(CPF, atual->CPF);
                tam = strcasecmp(CPF_busca, CPF);
                if (tam == 0)
                {
                    printf("Removendo Cadastro: \n");
                    printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", atual->Nome, atual->Matricula, atual->CPF, atual->Solicitacao, atual->Cod);
                    anterior->Proximo = atual->Proximo;
                    free(atual);
                    L1->Quantidade--;
                    printf("Solicitação removida com sucesso");
                    return true;
                }
                else if (tam < 0)
                {
                    printf("Busca não encontrada!");
                    return 0;
                }
                anterior = atual;
                atual = atual->Proximo;
            }
            return 0;
        }
    }
    return 0;
}
// Função para pesquisar na lista
bool Pesquisar_Lista(Lista L1)
{
    system("clear");
    Valores *temp;
    int Cod_busca;
    char Nome_busca[25];
    char CPF_busca[15];
    temp = L1.Primeiro;
    int tam;
    char CPF[15];
    char nome[25];

    if (ordenado_por == 1)
    {
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%s", Nome_busca);
        while (temp != NULL)
        {
            strcpy(nome, temp->Nome);
            tam = strcasecmp(Nome_busca, nome);

            if (tam == 0)
            {
                printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", temp->Nome, temp->Matricula, temp->CPF, temp->Solicitacao, temp->Cod);
                return true;
            }
            else if (tam < 0)
            {
                printf("Busca não encontrada!");
                return 0;
            }
            temp = temp->Proximo;
        }
    }
    else if (ordenado_por == 2)
    {
        printf("CPF: ");
        setbuf(stdin, NULL);
        scanf("%s", CPF_busca);
        while (temp != NULL)
        {
            strcpy(CPF, temp->CPF);
            tam = strcasecmp(CPF_busca, CPF);
            if (tam == 0)
            {
                printf("Nome: %s\nMatrícula: %s\nCPF: %s\nSolicitação: %s\nCódigo: %i\n", temp->Nome, temp->Matricula, temp->CPF, temp->Solicitacao, temp->Cod);
                return true;
            }
            else if (tam < 0)
            {
                printf("Busca não encontrada!");
                return 0;
            }
            temp = temp->Proximo;
        }
    }
    else
    {
        printf("Lista não ordenada!\nOrdene antes de pesquisar!!\n");
    }

    return 0;
}

int main()
{
    int opcao;
    Valores *temp;
    Lista L1;
    L1.Quantidade = 0;
    L1.Contador = 0;
    L1.Primeiro=NULL;
    L1.Ultimo=NULL;

    system("clear");
    while (true)
    {
        printf("Opções:\n1-Inserir\n2-Listar\n3-Remover\n4-Pesquisar\n5-Sair\n6-Ordenar por Nome\n7-Ordenar por CPF\nOpção: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 1:
            Inserir_Lista(&L1);
            setbuf(stdin, NULL);
            system("clear");
            break;
        case 2:
            Listar_Lista(temp, L1);
            setbuf(stdin, NULL);
            getc(stdin);
            system("clear");
            break;
        case 3:
            Remover_Lista(&L1);
            setbuf(stdin, NULL);
            getc(stdin);
            system("clear");
            break;
        case 4:
            Pesquisar_Lista(L1);
            setbuf(stdin, NULL);
            getc(stdin);
            system("clear");
            break;
        case 5:
            printf("Até a proxima");
            printf("\n");
            return 0;
        case 6:
            selectionSort_nome(&L1);
            setbuf(stdin, NULL);
            getc(stdin);
            system("clear");
            break;
        case 7:
            selectionSort_cpf(&L1);
            setbuf(stdin, NULL);
            getc(stdin);
            system("clear");
            break;
        default:
            printf("Opção Incorreta!\n");
            setbuf(stdin, NULL);
            getc(stdin);
            system("clear");
            break;
        }
    }
    return 0;
}

print
