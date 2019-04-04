#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encryption(char *msg, int K);
void zero(char *x, int N);

int main() {
    int Z = 26;
    char alpha[Z];
    zero(alpha, Z);
    
    for(int i = 0; i < Z; i++){
        scanf("%c", &alpha[i]);
        if(alpha[i] >= 97 && alpha[i] <= 122){
            alpha[i]= alpha[i] - 32;      
       }
    }
    
    for(int i =0; i < Z; i++){
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