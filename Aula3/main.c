#include<stdio.h>

#define NUM_PRECOS 5

float precos[NUM_PRECOS] = {1.0, 1.0, 1.0, 1.0, 1.0};
float precos_rotacionados[NUM_PRECOS];

int solicitaPreco()
{
    int idx = 0;
    do
    {
        printf("digite um valor: ");
        scanf("%f", &precos[idx]);
        idx++;
    }while(idx < NUM_PRECOS && precos[idx-1] != -1);

    if (precos[idx-1] == -1)
    {
        idx--;
    }
    
    return idx;
}

void printVetorGlobal(int qnt_elem)
{
    int idx = 0;
    while(idx < qnt_elem)
    {
        printf("O preco do elemento %i eh: %f\n", idx, precos[idx]);
        idx++; // o mesmo que idx = idx + 1;
    }
}

void rotacionaVetor()
{
    int j = NUM_PRECOS - 1;
    
    for(int i = 0; i < NUM_PRECOS; i++)
    {
        precos_rotacionados[i] = precos[j];
        j--;
    }

    for (int i = 0; i < NUM_PRECOS; i++)
    {
        precos[i] = precos_rotacionados[i];
    }
}

int main()
{
    printf("vetor original\n");
    printVetorGlobal(NUM_PRECOS);

    int qnt = solicitaPreco();

    printf("Vetor que digitamos\n");
    printVetorGlobal(qnt);
    
    rotacionaVetor();

    printf("vetor rotacionado\n");
    printVetorGlobal(NUM_PRECOS);

    // printf("O valor como int %i \n", 75);
    // printf("O valor como int %c \n", 75);
    // printf("O valor como int %c \n", 107);
    // printf("O valor como int %c \n", 'a');
    // printf("O valor como int %i \n", 'a');
    return 0;
}