#include "data.h"

void initializeList(LIST *l)
{
    l->first = NULL;
    l->last = NULL;
}

void readList(LIST l)
{
    NODO *search = l.first;
    printf("------------------------Users------------------------\n\n");
    while (search)
    {
        printf("------------\nName: %s\nLast Name: %s\nYears: %d\n", search->user.name, search->user.last_name, search->user.years);
        search = search->next_nodo;
    }
    printf("\n-----------------------------------------------------\n\n");
}

void saveDataList(LIST *l, DATA newUser)
{
    // First element
    if (l->first == NULL && l->last == NULL)
    {
        l->first = (NODO *) malloc(sizeof(NODO));
        l->last = l->first;
        l->first->user = newUser;
        l->first->next_nodo = l->first->previous_nodo = NULL;
    }
    else // +1 element
    {
        l->last->next_nodo = (NODO *) malloc(sizeof(NODO));
        l->last->next_nodo->next_nodo = NULL;
        l->last->next_nodo->previous_nodo = l->last;
        l->last->next_nodo->user = newUser;

        l->last = l->last->next_nodo;
    }
}

void readDataFile(FILE *file, LIST *l)
{
    DATA user;
    while(fscanf(file, "%s %s %2d", user.name, user.last_name, &user.years) != EOF)
        saveDataList(l, user);
}

void saveDataFile(FILE *file, LIST l)
{
    NODO *saveNode = l.first;
    while (saveNode)
    {
        fprintf(file, "%s %s %d\n", saveNode->user.name, saveNode->user.last_name, saveNode->user.years);
        saveNode = saveNode->next_nodo;
    }
}

