#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encryption(char *alpha, int K, int Z); //function prototypes 
void Dcryption(char *alpha, int K, int Z);
void zero(char *x, int N);

/*------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------*/

int main() {
    int K = 5; // the Key (rotation amount)
    int Z = 26; /* length of the message YET TO COMPLETE: auto find legth*/
   
    char msg[Z]; //set up array to store message
    zero(msg, Z); // zero the array 
    encryption(msg, K, Z);
    Dcryption(msg, K, Z);
    
    for(int i =0; i < Z; i++){
        printf("%c", (int)msg[i]); //print the array CHANGE TO %c FOR LETTER, %d FOR ASCII
    }

    return 0;
}

/*------------MAIN CODE ENDS HERE------------MAIN CODE ENDS HERE------------MAIN CODE ENDS HERE------------*/


void encryption(char *alpha, int K, int Z){ //YET TO COMPLETE: rewirte encyrption code into this function
    for(int i = 0; i < Z; i++){ // runs for the length of the message
        scanf("%c", &alpha[i]); //taking values from stdin and storing them in aphla
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      
       }
       alpha[i]= alpha[i] + K;
       if(alpha[i] > 90){
           alpha[i] = alpha[i] - 26;
       }
       if(alpha[i] < 65){
           alpha[i] = alpha[i] + 26;
       }

    }
}
void Dcryption(char *alpha, int K, int Z){ //YET TO COMPLETE: rewirte encyrption code into this function
    for(int i = 0; i < Z; i++){ // runs for the length of the message
        scanf("%c", &alpha[i]); //taking values from stdin and storing them in aphla
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      
       }
       alpha[i]= alpha[i] - K;
       if(alpha[i] > 90){
           alpha[i] = alpha[i] - 26;
       }
       if(alpha[i] < 65){
           alpha[i] = alpha[i] + 26;
       }

    }
}
void zero(char *x, int N){ // function to set all values of an array to zero 
    int i =0;
    for(i= 0; i < N; i++){
    x[i] = 0;
    }
}