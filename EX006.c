#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int vetor[6];
    int num;
    int i, x;
    int resp;
    
    for(i=0;i<6;i++) {
        
        while(vetor[i]==num) {
            num = rand() % 20 + 1;
        }
        vetor[i] = num;
        
    }
    
   
}