/* ------------------------------------------------------------------------------------------------------------------

TODOO Run Program and be greeted by an user interface


--------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function prototypes 
void encryption1(char *alpha, int K, int Z); 
void Dcryption1(char *alpha, int K, int Z);
void zero(char *x, int N);

/*------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------*/
	/*FILE *key;
	key = fopen("Key.txt", "r");
	char C;
	while(feof(key)==0){
	    fscanf(key, "%c", &C);
	    printf("%c\n", C);
	} */
 
int main() {  
    int K = 19;  // the Key (rotation amount)
    int Z = 1000; /* length of the message YET TO COMPLETE: auto find legth*/
   
   
    char msg[Z];    //set up array to store message
    zero(msg, Z);   // zero the array 
    
    
    encryption1(msg, K, Z);  //takes the array, the value of the key and the length of the array
    //Dcryption1(msg, K, Z);   //takes the array, the value of the key and the length of the array


    
    for(int i =0; i < Z; i++){
        printf("%c", (int)msg[i]); //print the array CHANGE TO %c FOR LETTER, %d FOR ASCII
    }
    
    return 0;
}

/*------------MAIN CODE ENDS HERE------------MAIN CODE ENDS HERE------------MAIN CODE ENDS HERE------------*/

/* ---------------------------------------------------------------
This function takes an array letters, and the length of the array 
 and forces the letters all to uppercase. 

It then takes the key and moves the ASCII values by the value of the
key. This shifts input letter to another letter (values of key) spaces 
along the alphabet.

The function corrects for the values going outside ASCII 
corrisponding to letters by either adding or subtracting 26 to the
value encrypted letter. 

Currently there is no provision for non letter charaters 
-----------------------------------------------------------------*/

void encryption1(char *alpha, int K, int Z){ 
    for(int i = 0; i < Z; i++){ // runs for the length of the message
        scanf("%c", &alpha[i]); //taking values from stdin and storing them in aphla
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      
       }
       if(alpha[i] > 64 && alpha[i] < 91){ //preventing non letters from being changed 
           alpha[i]= alpha[i] + K;      //rotating by the value of the key
           if(alpha[i] > 90){
               alpha[i] = alpha[i] - 26; //if value exceeds the value for Z return to A
           }
           if(alpha[i] < 65){
               alpha[i] = alpha[i] + 26; //if value proceeds the value for A return to Z
            }
        }
    }
}

/* ---------------------------------------------------------------
Exactly the same to the encryption function except it substracts 
the value of the key hence decrypting
-----------------------------------------------------------------*/

void Dcryption1(char *alpha, int K, int Z){ 
    for(int i = 0; i < Z; i++){ // runs for the length of the message
        scanf("%c", &alpha[i]); //taking values from stdin and storing them in aphla
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      
       }
       if(alpha[i] > 64 && alpha[i] < 91){
           alpha[i]= alpha[i] - K; // unrotating by the value of the key
           if(alpha[i] > 90){
               alpha[i] = alpha[i] - 26; //if value exceeds the value for Z return to A
           }
           if(alpha[i] < 65){
               alpha[i] = alpha[i] + 26; //if value proceeds the value for A return to Z
           }
        }
    }
}

/* ---------------------------------------------------------------
function to set all values of an array to zero 

It takes and array of type char and modifies it
-----------------------------------------------------------------*/

void zero(char *x, int N){ 
    int i =0;
    for(i= 0; i < N; i++){
    x[i] = 0;
    }
}