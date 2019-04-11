/* ------------------------------------------------------------------------------------------------------------------

TODOO Run Program and be greeted by an user interface


--------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function prototypes 
void encryption1(char *alpha, int K, int Z); 
void Dcryption1(char *alpha, int K, int Z);
void encryption2(char *alpha, int Z);
void zero(char *x, int N);

/*------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------*/
int main() {
    
    
	
    int K = 0;  // the Key (rotation amount)
    int Z = 1024; /* length of the message*/
   
   
    char msg[Z];    //set up array to store message
    zero(msg, Z);   // zero the array 
    
    
    //encryption1(msg, K, Z);  //takes the array, the value of the key and the length of the array
    //Dcryption1(msg, K, Z);   //takes the array, the value of the key and the length of the array
    encryption2(msg, Z);

    
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
    FILE *key;
    key = fopen("Message", "r");
    for(int i = 0; i < Z; i++){         // runs for the length of the message
        if(!feof(key)){                 //while not at end of file
            alpha[i] = (char)fgetc(key);//take value from file and put into array alpha
        }
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      //performing math on ascii values to make uppercase
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
    FILE *key;
    key = fopen("Message", "r");
    for(int i = 0; i < Z; i++){ // runs for the length of the message
        if(!feof(key)){                 //while not at end of file
            alpha[i] = (char)fgetc(key);//take value from file and put into array alpha
        }
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
Substituion cyher

This function takes an array letters, and the length of the array 
 and forces the letters all to uppercase. 
-----------------------------------------------------------------*/

void encryption2(char *alpha, int Z){ 
    
    
    
    
    FILE *key;
    key = fopen("Key.txt", "r");
    char CODE[26];                      // array to store Key code
    for(int i =0; i < 26; i++){
        if(!feof(key) && i < 26){                 //while not at end of file
            CODE[i] = (char)fgetc(key);//take value from file Key and put into array CODE
        } 
        
        if(CODE[i] >= 97 && CODE[i] <= 122){// if lowercase make uppercase
            CODE[i]= CODE[i] - 32;      //performing math on ascii values to make uppercase
        }         
    }
    
    
    FILE *msg;
    msg = fopen("Message", "r");                    
    for(int i = 0; i < Z; i++){         // runs for the length of the message
        
        if(!feof(msg)){                 //while not at end of file
            alpha[i] = (char)fgetc(msg);//take value from file message and put into array alpha
        }
        
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      //performing math on ascii values to make uppercase
        }
        
        if(alpha[i] > 64 && alpha[i] < 91){ //preventing non letters from being changed 
            // Main code to encyrpt goes here
            char tmp = alpha[i] - 65;
            alpha[i] = CODE[(int)tmp];
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
