#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
int contador_lista_consultorio = 0;
typedef struct cadastro NO;
struct cadastro
{
    char nome[50];
    char cpf[14];
    char cartao[19];
    NO *proximo;
};

typedef struct fila
{
    NO *inicio;
    NO *fim;
} FILA;

void inicializaFila(FILA *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enfileirar(FILA *fila)
{
    NO *ptr = (NO *)malloc(sizeof(NO));
    if (ptr == NULL)
    {
        printf("Erro de Alocação\n");
        return;
    }
    else
    {
        printf("Insira o nome do Paciente:\n");
        scanf("%s", ptr->nome);

        printf("Insira o CPF do Paciente:\n");
        scanf("%s", ptr->cpf);

        printf("Insira o Número do Cartão DuniMed do Paciente:\n");
        scanf("%s", ptr->cartao);
        ptr->proximo = NULL;
        if (fila->inicio == NULL)
        {
            fila->inicio = ptr;
        }
        else
        {
            fila->fim->proximo = ptr;
        }
        fila->fim = ptr;
        return;
    }
}

int desenfileirar(FILA *fila)
{
    NO *ptr = fila->inicio;
    char nome[50];
    char cpf[14];
    char cartao[19];

    if (ptr != NULL)
    {
        printf("Paciente %s removido\n", ptr->nome);
        fila->inicio = ptr->proximo;

        strcpy(nome, ptr->nome);

        strcpy(cpf, ptr->cpf);

        strcpy(cartao, ptr->cartao);

        ptr->proximo = NULL;

        free(ptr);
        if (fila->inicio == NULL)
        {
            fila->fim = NULL;
        }
        return 0;
    }
    else
    {
        printf("Fila Vazia\n");
        return 0;
    }
}

void imprimirFila(FILA *fila)
{
    NO *ptr = fila->inicio;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("Paciente %s CPF numero %s Cartão numero %s\n", ptr->nome, ptr->cpf, ptr->cartao);
            ptr = ptr->proximo;
        }
    }
    else
    {
        printf("Fila Vazia\n");
        return;
    }
}
//----------------------------------------------------------------------------------------------------------
typedef struct st_Valores Valores;

struct st_Valores
{
    char Consultorio[25];
    char Medico[30];
    int Cod;
    Valores *Anterior;
    Valores *Proximo;
};

typedef struct st_Lista
{
    Valores *Primeiro;
    Valores *Ultimo;
    int Quantidade;
} Lista;

void InsereLista(char consultorio[25], char medico[30], int cod, Lista *L)
{
    Valores *V1;

    V1 = (Valores *)calloc(1, sizeof(Valores));

    strcpy(V1->Consultorio, consultorio);
    strcpy(V1->Medico, medico);
    V1->Cod = cod;
    V1->Proximo = NULL;
    V1->Anterior = NULL;

    if (L->Primeiro == NULL)
    {
        L->Primeiro = V1;
        L->Ultimo = V1;
    }
    else
    {
        V1->Anterior = L->Ultimo;
        L->Ultimo->Proximo = V1;
        L->Ultimo = V1;
    }
}

//função para listar os consultórios
void listar_lista(Valores *temp, Lista L1)
{
    printf("Há %d consultórios abertos\n", contador_lista_consultorio);
    temp = L1.Primeiro;
    while (temp != NULL)
    {
        printf("Consultório: %s\nMédico: %s\n\n", temp->Consultorio, temp->Medico);
        temp = temp->Proximo;
    }
}

//remover da lista
int remover_lista(Lista *L1)
{
    Valores *anterior, *proximo, *atual;
    int cont = 1;
    int cod_deletar;
    atual = L1->Primeiro;
    printf("Códigos:\n1-Cardiologia\n2-Clínica Geral\n3-Dermatologia\n4-Geriatria\n5-Ginecologia\n\n");
    printf("Insira o código do consultório a ser fechado: ");
    scanf("%i", &cod_deletar);
    if (contador_lista_consultorio == 0)
    {
        return 0;
    }
    else if (contador_lista_consultorio == 1)
    {
        L1->Primeiro = NULL;
        L1->Ultimo = NULL;
        free(atual);
        contador_lista_consultorio--;
        return 0;
    }
    else if (cod_deletar == atual->Cod)
    {
        L1->Primeiro = atual->Proximo;
        free(atual);
        contador_lista_consultorio--;
        return 0;
    }
    else if (contador_lista_consultorio > 1)
    {

        while (cod_deletar != atual->Cod && atual != NULL)
        {
            anterior = atual;
            atual = atual->Proximo;
            if (atual == NULL)
            {
                printf("Não foi encontrado seu consultório!\n");
                return 0;
            }
        }
        anterior->Proximo = atual->Proximo;
        atual->Anterior = anterior;

        free(atual);
        contador_lista_consultorio--;
        printf("Consultório removido com sucesso");
        return 0;
    }
}
//---------------------------------------------------------------------------------------------------------
void acesso_cardiologia(FILA *cardiologia)
{
    int opcao_fila;
    imprimirFila(cardiologia);
    printf("O que você quer fazer?\n");
    printf("1-para inserir um paciente\n");
    printf("2-para remover um paciente\n");
    scanf("%i", &opcao_fila);
    switch (opcao_fila)
    {
    case 1:
        enfileirar(cardiologia);
        break;
    case 2:
        desenfileirar(cardiologia);
        break;
    default:
        break;
    }
}
void acesso_clinica_geral(FILA *geral)
{
    int opcao_fila;
    imprimirFila(geral);
    printf("O que você quer fazer?\n");
    printf("1-para inserir um paciente\n");
    printf("2-para remover um paciente\n");
    scanf("%i", &opcao_fila);
    switch (opcao_fila)
    {
    case 1:
        enfileirar(geral);
        break;
    case 2:
        desenfileirar(geral);
        break;
    default:
        break;
    }
}
void acesso_dermatologia(FILA *dermatologia)
{
    int opcao_fila;
    imprimirFila(dermatologia);
    printf("O que você quer fazer?\n");
    printf("1-para inserir um paciente\n");
    printf("2-para remover um paciente\n");
    scanf("%i", &opcao_fila);
    switch (opcao_fila)
    {
    case 1:
        enfileirar(dermatologia);
        break;
    case 2:
        desenfileirar(dermatologia);
        break;
    default:
        break;
    }
}
void acesso_geriatria(FILA *geriatria)
{
    int opcao_fila;
    imprimirFila(geriatria);
    printf("O que você quer fazer?\n");
    printf("1-para inserir um paciente\n");
    printf("2-para remover um paciente\n");
    scanf("%i", &opcao_fila);
    switch (opcao_fila)
    {
    case 1:
        enfileirar(geriatria);
        break;
    case 2:
        desenfileirar(geriatria);
        break;
    default:
        break;
    }
}
void acesso_ginecologia(FILA *ginecologia)
{
    int opcao_fila;
    imprimirFila(ginecologia);
    printf("O que você quer fazer?\n");
    printf("1-para inserir um paciente\n");
    printf("2-para remover um paciente\n");
    scanf("%i", &opcao_fila);
    switch (opcao_fila)
    {
    case 1:
        enfileirar(ginecologia);
        break;
    case 2:
        desenfileirar(ginecologia);
        break;
    default:
        break;
    }
}

bool pesquisar_lista(Lista L1, int cod_busca)
{
    Valores *temp;

    temp = L1.Primeiro;
    while (temp != NULL)
    {
        if (temp->Cod == cod_busca)
        {
            //printf("Consultório: %s com Médico: %s foi encontrado\n\n", temp->Consultorio, temp->Medico);
            return true;
        }
        else
        {
            return false;
        }
        temp = temp->Proximo;
    }
}

int main()
{
    char Consultorio[25];
    char Medico[30];
    int opcao_inicio;
    int opcao_fila;
    int opcao_lista;
    int cod_consultorio;
    char continuar;
    char finalizar;
    char busca_consultorio[25];

    FILA *cardiologia = (FILA *)malloc(sizeof(FILA));
    FILA *geral = (FILA *)malloc(sizeof(FILA));
    FILA *dermatologia = (FILA *)malloc(sizeof(FILA));
    FILA *ginecologia = (FILA *)malloc(sizeof(FILA));
    FILA *geriatria = (FILA *)malloc(sizeof(FILA));
    Valores *temp;

    Lista L1;

    do
    {
        finalizar = 'y';

        //apenas abrir

        //getc(stdin);
        system("clear");
        listar_lista(temp, L1);
        printf("O que você quer fazer?\nDigite a opcao desejada:\n\n");
        printf("1-Apenas abrir o Consultório de Cardiologia\n");
        printf("2-Apenas abrir a Clínica Geral\n");
        printf("3-Apenas abrir o Consultório de Dermatologia\n");
        printf("4-Apenas abrir o Consultório de Geriatria\n");
        printf("5-Apenas abrir o Consultório de Ginecologia\n");
        //apenas acessar
        printf("6-Apenas acessar o Consultório de Cardiologia\n");
        printf("7-Apenas acessar a Clínica Geral\n");
        printf("8-Apenas acessar o Consultório de Dermatologia\n");
        printf("9-Apenas acessar o Consultório de Geriatria\n");
        printf("10-Apenas acessar o Consultório de Ginecologia\n");
        //abrir e acessar
        printf("11-Abrir e acessar o Consultório de Cardiologia\n");
        printf("12-Abrir e acessar a Clínica Geral\n");
        printf("13-Abrir e acessar o Consultório de Dermatologia\n");
        printf("14-Abrir e acessar o Consultório de Geriatria\n");
        printf("15-Abrir e acessar o Consultório de Ginecologia\n");
        printf("16-Remover um consultório\n");
        //fechar
        scanf("%i", &opcao_inicio);

        getc(stdin);
        system("clear");

        if (opcao_inicio == 1)
        {

            if (cardiologia == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Cardiologia
                strcpy(Consultorio, "Cardiologia");
                strcpy(Medico, "Dra. Cristina Yang");
                InsereLista(Consultorio, Medico, 1, &L1);
                inicializaFila(cardiologia);
                printf("Sucesso na criação");
                getc(stdin);
                system("clear");
                contador_lista_consultorio++;
            }
        }
        else if (opcao_inicio == 2)
        {

            if (geral == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Clínica Geral
                strcpy(Consultorio, "Clínica Geral");
                strcpy(Medico, "Dra. Meredith Grey");
                InsereLista(Consultorio, Medico, 2, &L1);
                inicializaFila(geral);
                printf("Sucesso na criação");
                getc(stdin);
                system("clear");
                contador_lista_consultorio++;
            }
        }
        else if (opcao_inicio == 3)
        {

            if (dermatologia == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Dermatologia
                strcpy(Consultorio, "Dermatologia");
                strcpy(Medico, "Dr. Jackson Avery");
                InsereLista(Consultorio, Medico, 3, &L1);
                inicializaFila(dermatologia);
                printf("Sucesso na criação");
                getc(stdin);
                system("clear");
                contador_lista_consultorio++;
            }
        }
        else if (opcao_inicio == 4)
        {

            if (geriatria == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Geriatria
                strcpy(Consultorio, "Geriatria");
                strcpy(Medico, "Dra. Erica Hahn");
                InsereLista(Consultorio, Medico, 4, &L1);
                inicializaFila(geriatria);
                printf("Sucesso na criação");
                getc(stdin);
                system("clear");
                contador_lista_consultorio++;
            }
        }
        else if (opcao_inicio == 5)
        {

            if (ginecologia == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Ginecologia
                strcpy(Consultorio, "Ginecologia");
                strcpy(Medico, "Dra. Addison Montgomery");
                InsereLista(Consultorio, Medico, 5, &L1);
                inicializaFila(ginecologia);
                printf("Sucesso na criação");
                getc(stdin);
                system("clear");
                contador_lista_consultorio++;
            }
        }
        else if (opcao_inicio == 6)
        {
            do
            {
                if (pesquisar_lista(L1, 1))
                {
                    acesso_cardiologia(cardiologia);
                    printf("Deseja continuar na cardiologia?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                }
                else
                {
                    printf("Epa, esse consultório ainda não existe\n");
                }

            } while (continuar == 's');
        }
        else if (opcao_inicio == 7)
        {
            do
            {
                if (pesquisar_lista(L1, 2))
                {
                    acesso_clinica_geral(geral);
                    printf("Deseja continuar na clínica geral?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                }
                else
                {
                    printf("Epa, esse consultório ainda não existe\n");
                }

            } while (continuar == 's');
        }
        else if (opcao_inicio == 8)
        {
            do
            {
                if (pesquisar_lista(L1, 3))
                {
                    acesso_dermatologia(dermatologia);
                    printf("Deseja continuar na dermatologia?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                }
                else
                {
                    printf("Epa, esse consultório ainda não existe\n");
                }

            } while (continuar == 's');
        }
        else if (opcao_inicio == 9)
        {
            do
            {
                if (pesquisar_lista(L1, 4))
                {
                    acesso_geriatria(geriatria);
                    printf("Deseja continuar na geriatria?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                }
                else
                {
                    printf("Epa, esse consultório ainda não existe\n");
                }

            } while (continuar == 's');
        }
        else if (opcao_inicio == 10)
        {
            do
            {
                if (pesquisar_lista(L1, 5))
                {
                    acesso_ginecologia(ginecologia);
                    printf("Deseja continuar na ginecologia?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                }
                else
                {
                    printf("Epa, esse consultório ainda não existe\n");
                }

            } while (continuar == 's');
        }
        else if (opcao_inicio == 11)
        {

            if (cardiologia == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Cardiologia
                strcpy(Consultorio, "Cardiologia");
                strcpy(Medico, "Dra. Cristina Yang");
                InsereLista(Consultorio, Medico, 1, &L1);
                contador_lista_consultorio++;
                inicializaFila(cardiologia);
                do
                {
                    acesso_cardiologia(cardiologia);
                    printf("Deseja continuar na cardiologia?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                } while (continuar == 's');
            }
        }
        else if (opcao_inicio == 12)
        {

            if (geral == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Clínica Geral
                strcpy(Consultorio, "Clínica Geral");
                strcpy(Medico, "Dra. Meredith Grey");
                InsereLista(Consultorio, Medico, 2, &L1);
                contador_lista_consultorio++;
                inicializaFila(geral);
                do
                {
                    acesso_clinica_geral(geral);
                    printf("Deseja continuar na clinica geral?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                } while (continuar == 's');
            }
        }
        else if (opcao_inicio == 13)
        {

            if (dermatologia == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {

                //Abre o Consultório de Dermatologia
                strcpy(Consultorio, "Dermatologia");
                strcpy(Medico, "Dr. Jackson Avery");
                InsereLista(Consultorio, Medico, 3, &L1);
                contador_lista_consultorio++;
                inicializaFila(dermatologia);
                do
                {
                    acesso_dermatologia(dermatologia);
                    printf("Deseja continuar na dermatologia?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                } while (continuar == 's');
            }
        }
        else if (opcao_inicio == 14)
        {

            if (geriatria == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Geriatria
                strcpy(Consultorio, "Geriatria");
                strcpy(Medico, "Dra. Erica Hahn");
                InsereLista(Consultorio, Medico, 4, &L1);
                contador_lista_consultorio++;
                inicializaFila(geriatria);
                do
                {
                    acesso_geriatria(geriatria);
                    printf("Deseja continuar na geriatria?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                } while (continuar == 's');
            }
        }
        else if (opcao_inicio == 15)
        {

            if (ginecologia == NULL)
            {
                printf("Erro de Alocação");
            }
            else
            {
                //Abre o Consultório de Ginecologia
                strcpy(Consultorio, "Ginecologia");
                strcpy(Medico, "Dra. Addison Montgomery");
                InsereLista(Consultorio, Medico, 5, &L1);
                contador_lista_consultorio++;
                inicializaFila(ginecologia);
                do
                {
                    acesso_ginecologia(ginecologia);
                    printf("Deseja continuar na ginecologia?(s/n) ");
                    setbuf(stdin, NULL);
                    scanf("%c", &continuar);
                    setbuf(stdin, NULL);
                    system("clear");
                } while (continuar == 's');
            }
        }
        else if (opcao_inicio == 16)
        {
            remover_lista(&L1);
        }
        else
        {
            printf("Ocorreu um erro");
        }

        system("clear");
        getc(stdin);
        printf("Deseja continuar no sistema?(s/n) ");
        setbuf(stdin, NULL);
        scanf("%c", &finalizar);
        setbuf(stdin, NULL);
        system("clear");
    } while (finalizar == 's');
    return 0;
}