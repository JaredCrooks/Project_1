#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encryption(char *msg, int K);
void zero(char *x, int N);

int main() {
    char alpha[4];
    zero(alpha, 4);
    
    for(int i = 0; i < 4; i++){
        scanf("%c", &alpha[i]);
       
    }
    
    for(int i =0; i < 4; i++){
        printf("%d\n", (int)alpha[i]);
    }

    return 0;
}

void encryption(char *str, int K){
    
}
void zero(char *x, int N){
    int i =0;
    for(i= 0; i < N; i++){
    x[i] = 0;
    }
}