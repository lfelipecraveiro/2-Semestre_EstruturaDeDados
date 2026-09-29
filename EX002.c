/***
Autor: L. Felipe Craveiro
Data: 22/09/2026
Objetivo: calcular a média de quatro notas e retornar o valor e se foi aprovado ou não.
***/
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *Fn;
    float *Fmedia;
    int i;

    Fn = (int*)malloc(4*sizeof(int));
    Fmedia = (float*)malloc(sizeof(float));

    for (i=0;i<4;i++) {
        printf("Digite nota %d.: ", i+1);
        scanf("%d", &Fn[i]);
        if (Fn[i]<0 || Fn[i]>100) {
            printf("Valor invalido!\nDigite novamente:\n");
            i-=1;
        }
    }
    
    for(i=0;i<4;i++) {
        *Fmedia += Fn[i];
    }
    *Fmedia = *Fmedia/4;

    printf("A media e.: %.2f\n", *Fmedia);
    if (*Fmedia<70.0) {
        printf("Reprovado!\n");
    } else if (*Fmedia<90.0) {
        printf("Aprovado!\n");
    } else {
        printf("Aprovado com merito!\n");
    }


    free(Fmedia);
    free(Fn);

    return 0;
}