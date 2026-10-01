/***
Autor.: L. Felipe Craveiro
Data.: 01/10/2026
Objetivo.: Criar uma lista simplesmente encadeada
 ***/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cd_func;
    char nm_func;
    float sal_func
} reg_func;

typedef struct TipoItem *L;

typedef struct TipoItem {
    reg_func conteudo;
    L prox;
} TipoItem;

typedef struct {
    L pri;
    L ult;
} TipoLista;


int main() {
    
    int *P;
    int *R;

    P = (L) malloc (sizeof(TipoItem));
    
    L->pri=P;
    L->ult=P;
    P->prox=NULL;//Aterramento

    //Adicionar no início
    P->prox = L->pri;
    L->pri=P;

    //Adicionar no fim
    L->ult->prox=P;
    L->ult=P;
    P->prox=NULL;

    //Retirar o único elemento da lista
    if (L->pri->prox==NULL) {
        free(L->pri);
        L->pri=NULL;
        L->ult=NULL;
    };

    //Retirar o primeiro da lista
    P = L->pri;
    L->pri= P->prox;
    free(P);

    //Retirar o ultimo da lista
    R = L->pri;
    P = R->prox;
    while(P->prox != NULL) {
        P = P->prox;
        R = R->prox;
    }
    free(P);
    R->prox = NULL;
    L->ult = R;

    //Inserir em uma posição
    R = (L) malloc (sizeof(TipoItem));
    P->L->pri;
    for(x:=1; ) {

    }

    //Remover uma posição

    free(P);
    free(R);
}