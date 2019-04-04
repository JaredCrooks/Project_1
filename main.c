#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encryption(char *msg, int K); //function prototypes 
void zero(char *x, int N);

/*------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------*/

int main() {
    int Z = 26; /* length of the message YET TO COMPLETE: auto find legth*/
    char alpha[Z]; //set up array to store message
    zero(alpha, Z); // zero the array 
    
    for(int i = 0; i < Z; i++){ // runs for the length of the message
        scanf("%c", &alpha[i]); //taking values from stdin and storing them in aphla
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      
       }
    }
    
    for(int i =0; i < Z; i++){
        printf("%d\n", (int)alpha[i]); //print the array
    }

    return 0;
}

/*------------MAIN CODE ENDS HERE------------MAIN CODE ENDS HERE------------MAIN CODE ENDS HERE------------*/


void encryption(char *str, int K){ //YET TO COMPLETE: rewirte encyrption code into this function
    
}
void zero(char *x, int N){ // function to set all values of an array to zero 
    int i =0;
    for(i= 0; i < N; i++){
    x[i] = 0;
    }
}