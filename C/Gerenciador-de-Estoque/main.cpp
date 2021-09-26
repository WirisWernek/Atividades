// Testado no Online GDB como C++17 e No Replit
// Disponível em: https://replit.com/join/ieezgctela-wiriswernek
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_produto Produto;

struct st_produto
{
    char Nome[20];
    int Codigo;
    float Preco_Custo;
    float Preco_Venda;
    int Quantidade;
    Produto *Esquerda;
    Produto *Direita;
    Produto *Pai;
};

typedef struct st_Arvore
{
    int Quantidade;
    Produto *Raiz;
} Arvore;

void Listar(Produto *P)
{
    if (P == NULL)
    {
        return;
    }
    printf("Produto: %s - Codigo: %d - Custo: R$ %.2f - Venda: R$ %.2f - Quantidade: %d\n", P->Nome, P->Codigo, P->Preco_Custo, P->Preco_Venda, P->Quantidade);
    Listar(P->Esquerda);
    Listar(P->Direita);
}
void ModoInventario(Produto *P)
{
    if (P == NULL)
    {
        return;
    }
    printf("Produto: %s - Quantidade: %d\n", P->Nome, P->Quantidade);
    ModoInventario(P->Esquerda);
    ModoInventario(P->Direita);
}

void InserirRecursivo(Produto *Inserir, Produto *Atual)
{
    if (strcmp(Inserir->Nome, Atual->Nome) < 0)
    {
        if (Atual->Esquerda == NULL)
        {
            Atual->Esquerda = Inserir;
        }
        else
        {
            InserirRecursivo(Inserir, Atual->Esquerda);
        }
    }
    else
    {
        if (Atual->Direita == NULL)
        {
            Atual->Direita = Inserir;
        }
        else
        {
            InserirRecursivo(Inserir, Atual->Direita);
        }
    }
}

void InserirOrdenado(Produto *P, Arvore *C)
{
    if (C != NULL)
    {
        if (C->Raiz != NULL)
        {
            if (P != NULL)
            {
                InserirRecursivo(P, C->Raiz);
                C->Quantidade++;
            }
        }
        else
        {
            C->Raiz = P;
            C->Quantidade++;
        }
    }
}
Produto *PesquisarRecursivo(char *Nome, Produto *Atual)
{
    if (Atual == NULL)
    {
        return NULL;
    }
    if (strcmp(Atual->Nome, Nome) == 0)
    {
        return Atual;
    }
    else
    {
        if (strcmp(Atual->Nome, Nome) < 0)
        {
            return PesquisarRecursivo(Nome, Atual->Direita);
        }
        else
        {
            return PesquisarRecursivo(Nome, Atual->Esquerda);
        }
    }
}

Produto *Pesquisar(char *Nome, Arvore *C)
{
    if (C != NULL)
    {
        if (C->Raiz != NULL)
        {
            return PesquisarRecursivo(Nome, C->Raiz);
        }
    }
    return NULL;
}

int main()
{
    system("clear");
    char name[20];
    int cod;
    float cost;
    float sale;
    int amount;
    char namesearch[20];
    Produto *P;
    Produto *Pesq;
    Arvore *Arv = (Arvore *)calloc(1, sizeof(Arvore));
    Arv->Raiz = NULL;
    Arv->Quantidade = 0;
    int opcao = -1;
    int modify = -1;

    while (true)
    {
        printf("Menu\nDigite 1 para Inserir um Produto\nDigite 2 para Listar os Produtos\nDigite 3 para Procurar um Produto\nDigite 4 para Modificar um Produto\nDigite 5 para Ver o Inventário\nDigite 0 para Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            system("clear");
            P = (Produto *)calloc(1, sizeof(Produto));
            printf("Nome do Produto: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", name);
            printf("Código do Produto: ");
            scanf("%d", &cod);
            printf("Preço de Custo: ");
            scanf("%f", &cost);
            printf("Preço de Venda: ");
            scanf("%f", &sale);
            printf("Quantidade: ");
            scanf("%d", &amount);
            strcpy(P->Nome, name);
            P->Codigo = cod;
            P->Preco_Custo = cost;
            P->Preco_Venda = sale;
            P->Quantidade = amount;
            InserirOrdenado(P, Arv);
            system("clear");
        }
        else if (opcao == 2)
        {
            system("clear");
            printf("Listando...\n");
            Listar(Arv->Raiz);
            printf("\n\n");
        }
        else if (opcao == 3)
        {
            system("clear");
            printf("Nome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", namesearch);
            system("clear");
            printf("Pesquisando...\n");
            Pesq = Pesquisar((char *)namesearch, Arv);
            if (Pesq != NULL)
            {
                printf("Produto %s existe e foi encontrado no sistema\n", Pesq->Nome);
            }
            else
            {
                printf("Produto %s não existe ou não foi encontrado no sistema\n", Pesq->Nome);
            }
        }
        else if (opcao == 4)
        {
            system("clear");
            printf("Nome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", namesearch);
            printf("Deseja:\n1-Incrementar Quantidade\n2-Decrementar Quantidade\n3-Modificar Valor de Custo\n4-Modificar Valor de Venda\nOpção: ");
            scanf("%d", &modify);
            system("clear");
            printf("Pesquisando...\n");
            Pesq = Pesquisar((char *)namesearch, Arv);
            if (Pesq != NULL)
            {
                int modquant;
                float modvalor;
                if (modify == 1)
                {
                    printf("Produto: %s - Quantidade Atual: %d", Pesq->Nome, Pesq->Quantidade);
                    printf("\nQuanto deseja incrementar: ");
                    scanf("%d", &modquant);
                    Pesq->Quantidade = Pesq->Quantidade + modquant;

                    printf("Retornou pro sistema Produto %s com %d Unidades\n", Pesq->Nome, Pesq->Quantidade);
                }
                else if (modify == 2)
                {
                    printf("Produto: %s - Quantidade Atual: %d", Pesq->Nome, Pesq->Quantidade);
                    printf("\nQuanto deseja decrementar: ");
                    scanf("%d", &modquant);
                    Pesq->Quantidade = Pesq->Quantidade - modquant;
                    printf("Retornou pro sistema Produto %s com %d Unidades\n", Pesq->Nome, Pesq->Quantidade);
                }
                else if (modify == 3)
                {
                    printf("Produto: %s - Valor de Custo Atual: %.2f", Pesq->Nome, Pesq->Preco_Custo);
                    printf("\nQual o novo valor: ");
                    scanf("%f", &modvalor);
                    Pesq->Preco_Custo = modvalor;
                    printf("Retornou pro sistema Produto %s com Preço de Custo de R$ %.2f\n", Pesq->Nome, Pesq->Preco_Custo);
                }
                else if (modify == 4)
                {
                    printf("Produto: %s - Valor de Venda Atual: %.2f", Pesq->Nome, Pesq->Preco_Venda);
                    printf("\nQual o novo valor: ");
                    scanf("%f", &modvalor);
                    Pesq->Preco_Venda = modvalor;
                    printf("Retornou pro sistema Produto %s com Preço de Venda de R$ %.2f\n", Pesq->Nome, Pesq->Preco_Venda);
                }
                printf("Operação Concluida\n");
            }
            else
            {
                printf("Produto %s não existe ou não foi encontrado no sistema\n", Pesq->Nome);
            }
        }
        else if (opcao == 5)
        {
            system("clear");
            printf("Listando Inventário...\n");
            ModoInventario(Arv->Raiz);
            printf("\n\n");
        }
        else if (opcao == 0)
        {
            return 0;
        }
        else
        {
            printf("Opção Inválida!!\n");
        }
    }
}