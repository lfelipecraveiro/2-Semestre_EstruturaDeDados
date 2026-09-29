#include <stdio.h>

int dobro(int *prt) {
    int x;
    for(x=0;x<5;x++) {
        prt[x] = prt[x] * 2;
    }
}
int main() {

    int *P;
    int vetor[5];
    int y;

    P = vetor;

    for(y=0;y<5;y++) {
        printf("Digite o numero %d.: ", y+1);
        scanf("%d", &P[y]);
    }

    dobro(P);

    printf("Aqui esta o dobro dos numeros digitados.: \n");
    for(y=0;y<5;y++) {
        printf("%d,\n", P[y]);
    }
    return 0;
}