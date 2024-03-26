#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_SCREENS 3

typedef struct screen
{
    char menu[100];
    char options[100];
    int choice;
}Screen;

Screen App_Screen[NUMBER_OF_SCREENS] = {
    {"Trabalho de PA \nGrupo do Professor\n", "1 para continuar \n2 para sair\n", 0},
    {"Teste", "Teste 2", 0},
    {"Teste", "Teste 3", 0}
};

void displayScreen(int screen_number)
{
    printf("%s", App_Screen[screen_number].menu);
    printf("%s", App_Screen[screen_number].options);
}

int getChoice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int choice = 0;

    do
    {
        displayScreen(choice);
        choice = getChoice();
        system("clear");
    } while (choice != 2);  

    return 0;
}