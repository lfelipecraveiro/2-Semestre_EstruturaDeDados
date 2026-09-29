#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float *sal;
    float *tot_sal;
    float *maior_sal;
    float *media_sal;
    float *percentual_menor_mil;

    int *media_filho;
    int *menor_mil;
    int *tot_pessoa;
    int *filho;
    int *tot_filho;

    sal = (float*)malloc(sizeof(float));
    tot_sal = (float*)malloc(sizeof(float));
    maior_sal = (float*)malloc(sizeof(float));
    media_sal = (float*)malloc(sizeof(float));
    percentual_menor_mil = (float*)malloc(sizeof(float));

    menor_mil = (int*)malloc(sizeof(int));
    media_filho = (int*)malloc(sizeof(int));
    filho = (int*)malloc(sizeof(int));
    tot_filho = (int*)malloc(sizeof(int));
    tot_pessoa = (int*)malloc(sizeof(int));

    *tot_pessoa = 0;
    *tot_filho = 0;
    *filho = 0;
    *media_filho = 0;
    *menor_mil = 0;
    *percentual_menor_mil = 0;
    *tot_sal = 0;
    *maior_sal = 0;


    do {
        do{
            printf("Digite o salario.: ");
            scanf("%f", sal);
        
            if(*sal>0) {
                printf("Digite a quantidade de filhos.: ");
                scanf("%d", filho);
                *tot_filho+=*filho;
            } else if (*sal==0) {
                printf("Valor invalido!\n");
            }
        }while(*sal==0);

        if(*sal>0) {        
            if(*sal>*maior_sal) {
                *maior_sal = *sal;
            }
            if(*sal<1000) {
                *menor_mil += 1;
            }
                *tot_sal = *tot_sal+*sal;
                *tot_pessoa = *tot_pessoa+1;
            }

    } while(*sal>=0);

    *media_sal = *tot_sal / *tot_pessoa;
    *media_filho = *tot_filho / *tot_pessoa;
    *percentual_menor_mil = ((float)*menor_mil / *tot_pessoa)*100;

    printf("\n=======RESULTADOS=======\n");
    printf("1. Media salarial.: %.2f\n", *media_sal);
    printf("2. Media de filhos.: %d\n", *media_filho);
    printf("3. Maior salario.: %.2f\n", *maior_sal);
    printf("4. Percentual de pessoas com salarios menores que mil.: %.1f\n", *percentual_menor_mil);

    free(sal);
    free(tot_sal);
    free(maior_sal);
    free(media_sal);
    free(percentual_menor_mil);
    free(filho);
    free(tot_filho);
    free(media_filho);
    free(menor_mil);
    free(tot_pessoa);

    return 0;
}