#include<stdio.h>
#include<stdlib.h>

#define MAX_PROD 50

typedef float Precos;

typedef enum prod{
    TV = 1,     //recebe número 10
    SOM,    //recebe número 20
    CELULAR //recebe número 30
}Produto;

// enum prod lista_de_produtos[MAX_PROD]; - dessa forma também está correto
Produto lista_de_produtos[MAX_PROD];
Precos lista_de_precos[MAX_PROD];

void imprimirProdutos(int qnt)
{
    for(int i = 0; i < qnt; i++)
    {
        switch(lista_de_produtos[i])
        {
            case TV:
                printf("O produto %d eh uma TV e custa R$%.2f.\n", 
                        i, lista_de_precos[i]);
                break;
            case SOM:
                printf("O produto %d eh um SOM e custa R$%.2f.\n", 
                        i, lista_de_precos[i]);
                break;
            case CELULAR:
                printf("O produto %d eh um CELULAR e custa R$%.2f.\n",
                        i, lista_de_precos[i]);
                break;
            default:
                printf("algo errado.\n");
        }
    }
}

int addProduto(Produto prod, Precos preco)
{
    static int idx = 0;
    lista_de_produtos[idx] = prod;
    lista_de_precos[idx] = preco;
    idx++;

    return idx;
}

Produto tela(){
    Produto escolha;
    
    printf("Escolha um produto:\n");
    printf("1 para TV\n2 para SOM\n3 para CELULAR\n0 para sair\n");
    scanf("%u", &escolha);
    
    return escolha;
}

int main()
{
    int indice;
    Produto prod;

    do
    {
        prod = tela();
        if(prod != 0)
        {
            indice = addProduto(prod, 999.99);
        }
    }while(prod != 0);

    imprimirProdutos(indice);
}