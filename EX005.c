#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int vetor[6];
    int num;
    int repetido;
    int correto = 0;
    int i, x;
    int resp;
    
    for(i=0;i<6;i++) {
        
        do{
            repetido = 0;
            num = rand() % 20 + 1;
            for(x=0;x<i;x++) {
                if(num==vetor[x]) {
                    repetido += 1;
                }
            }    
        }while(repetido>0);
        vetor[i] = num;
    }
    printf("Digite um número de 1 a 20.: ");
    scanf("%d", &resp);
    
    for(i=0;i<6;i++) {
        if(resp==vetor[i]){
            correto += 1;
        }
    }
    
    if(correto!=0){
        printf("Numero encontrado!\n");
    } else {
        printf("Numero não encontrado!\n");
    }
    
    for(i=0;i<6;i++){
        printf("| %d ", vetor[i]);
    }
    printf("|");
   
}