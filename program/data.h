#ifndef TYPES_H
    // libraries
    #include <stdio.h>
    #include <stdlib.h>

    // constants
    #define TYPES_H
    #define N 20
    #define LN 40

    // structurs
    typedef struct {
        char name[N];
        char last_name[LN];
        int years;
    } DATA;

    typedef struct nodo {
        DATA user;
        struct nodo *next_nodo, *previous_nodo;
    } NODO;

    typedef struct
    {
        NODO *first;
        NODO *last;
    } LIST;
    
    // prototypes
    void initializeList(LIST *);
    void readList(LIST);
    void saveDataList(LIST *, DATA);
    void readDataFile(FILE *, LIST *);
    void saveDataFile(FILE *, LIST);

#endif