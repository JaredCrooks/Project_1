/* ------------------------------------------------------------------------------------------------------------------
PLEASE READ ME  
        
     --input file--
        THIS CAN BE IGNORED IF TERMINAL IS USED TO RUN PROGRAM 
        Place two integers seperated by a space The first selects program (Run program to give options)
        the second is a rotation amount leave as zero if not needed
    --/input file--
    
     --Output.txt--
        alongside the ternimal printf, The results get placed in this file.
    --/Output.txt--
    
    --Message file--
        Just paste your message to be encoded or decoded in the Message file
        lower cased letters will be forced to uppercase upon printing 
    --/Message file--

    --Key.txt--
        The is the key for subsitution encryption/decryption.
        Only place 26 charaters in there upper or lowercase.
        the first letter placed will be assigned to A the 
        next letter assigned to B and so on alphabetically.
    --/Key.txt--

    --main.c--
        Running the program will greet you with the options 
        Running again with RunInput and non-zero values in input file will perform the desired operation
        Using the terminal will prompt you and take values (if running either functions 3, 4 or 5 just hit enter on the second input)
        
        The program will both write to the terminal and to a file Output.txt
        
        Lowercase letters will be made uppercase
        rotation amount cannot exceed 26 cypher or be negitive, it is read as an integer 
        
    --/main.c--
--------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function prototypes 
void encryption1(char *alpha, int K, int Z); 
void Dcryption1(char *alpha, int K, int Z);
void encryption2(char *alpha, int Z);
void decryption2(char *alpha, int Z);
int BruteForce(char *alpha, int Z);
void dcyrypt(char *alpha, int K, int Z);
char mode(char *alpha, int Z);
void zero(char *x, int N);

/*------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------MAIN CODE STARTS HERE------------*/
int main() { 
    int K = 0;  // the Key (rotation amount) keep under 27
    int Z = 2048; /* length of the message*/
    char msg[Z];    //set up array to store message
    zero(msg, Z);   // zero the array 
    
    printf("Please first write message in Message file then select action by typying: \n");
    printf("<1> For encyrption of a rotaion cypher FOLLOWED by rotation amount\n");
    printf("<2> For decyrption of a rotaion cypher FOLLOWED by rotation amount\n");
    printf("<3> For encyrption of a subsitution cypher after entering the key in KEY.txt\n");
    printf("<4> For decyrption of a subsitution cypher after entering the key in KEY.txt\n");
    printf("<5> For decyrption of a rotaion cypher without a Key\n");
    int c;
    
    scanf("%d %d", &c, &K);
    if(K > 26 || K < 0 ){
        printf("error rotation amount not inside 0-26\n");
        return 0;
    }
    switch(c){
        case 1:
            encryption1(msg, K, Z);  //takes the array, the value of the key and the length of the array
            break;
        case 2:
            Dcryption1(msg, K, Z);   //takes the array, the value of the key and the length of the array
            break;
        case 3:
            encryption2(msg, Z);
            break;
        case 4:
            decryption2(msg, Z);
            break;
        case 5:
            dcyrypt(msg, K, Z);
            break;
    }
    FILE *out;
    out = fopen("Output.txt", "w"); //opening file to produce output message
    for(int i =0; i < Z; i++){
        printf("%c", (int)msg[i]);  //print the array. CHANGE TO %c FOR LETTER, %d FOR ASCII
        fprintf(out, "%c", (int)msg[i]);
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

does not change non-letters
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
Substituion cyher encryption

It requires an array and its length 

This function takes two files of letter one message the other the 
key, forces the letters all to uppercase.

compares the  message with the key and then places the encyrpted 
message in the array

does not change non-letters
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
            char tmp = alpha[i] - 65;       //setting A to 0, B to 1, C to 2 and etc in a temporary varible
            alpha[i] = CODE[(int)tmp];      //replace the value of the array with the letter from the key corresponding the temporary value
        }
    }
}

/* ---------------------------------------------------------------
Substituion cyher DECRYPTION

It requires an array and its length 

This function takes two files of letter one message the other the 
key, forces the letters all to uppercase.

compares the encrypted message with the key and then places the dcrypted 
message in the array

does not change non-letters
-----------------------------------------------------------------*/

void decryption2(char *alpha, int Z){ 
    
    FILE *key;
    key = fopen("Key.txt", "r");        // open the key file for read
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
    msg = fopen("Message", "r");        // open mesasge file for read            
    for(int i = 0; i < Z; i++){         // runs for the length of the message
        
        if(!feof(msg)){                 //while not at end of file
            alpha[i] = (char)fgetc(msg);//take value from file message and put into array alpha
        }
        
        if(alpha[i] >= 97 && alpha[i] <= 122){// if lowercase make uppercase
            alpha[i]= alpha[i] - 32;      //performing math on ascii values to make uppercase
        }
        
        if(alpha[i] > 64 && alpha[i] < 91){ //preventing non letters from being changed 
            // Main code to decyrpt goes here
            char tmp = alpha[i]; 
            for(int k=0; k<26; k++ ){
                if(tmp == CODE[k]){     //if value in the array matches value from the key
                    alpha[i] = k + 65;  //then store the decyrpted value of that key letter 
                    break;   //break to remove redunadant processing as the letter has already been dcrypted
                }                
            }
        }
    }
}
/* ---------------------------------------------------------------
Bute forces a rotation cipher

It takes and array of type char and length of the array 

returns the rotation amount for decryption
-----------------------------------------------------------------*/
int BruteForce(char *alpha, int Z){
    for(int i =0; i<26; i++){           //for each possible rotation amount
        Dcryption1(alpha, i, Z);        //run the decyrption function
        for(int k = 0; k < Z; k++){     //loop to run through the decrypted array 
            int a = k + 1;          //2nd letter of a possible word
            int b = k + 2;          //3rd letter of a possible word
            int c = k + 3;          //4th letter of a possible word
            /* 
                This next bit of code checks for english words
                It works by checking the ascii value of a sequence of letters  
                in the array
            */
            if(alpha[k] == 84 && alpha[a] == 72 && alpha[b] == 69){     //THE
                return i; // return 
            }
            if(alpha[k]==65 && alpha[a]==78 && alpha[b]==68){           //AND  
                return i;
            }
            if(alpha[k] == 84 && alpha[a] == 72 && alpha[b] == 65 && alpha[c] == 84){   //THAT
                return i;
            }
            if(alpha[k] == 72 && alpha[a] == 65 && alpha[b] == 86 && alpha[c] == 69){   //HAVE
                return i;
            }
            if(alpha[k] == 89 && alpha[a] == 79 && alpha[b] == 85){     //YOU
                return i;
            }
            if(alpha[k] == 84 && alpha[a] == 72 && alpha[b] == 73 && alpha[c] == 83){   //THIS
                return i;
            }
            if(alpha[k] == 70 && alpha[a] == 82 && alpha[b] == 79 && alpha[c] == 77){   //FROM
                return i; 
            }
            if(alpha[k] == 84 && alpha[a] == 72 && alpha[b] == 69 && alpha[c] == 89){   //THEY
                return i;
            }
            if(alpha[k] == 87 && alpha[a] == 72 && alpha[b] == 65 && alpha[c] == 84){   //WHAT
                return i;
            }
            if(alpha[k] == 84 && alpha[a] == 73 && alpha[b] == 77 && alpha[c] == 69){   //TIME
                return i;
            }//if any of these words are found then it will return the roation amount that created this message.
        }
    }
    return 42;            //the answer to everything including why your code broke
}

//function to package brute force decryption for rotation cyphers
void dcyrypt(char *alpha, int K, int Z){
    K = BruteForce(alpha, Z); //changes the rotation amount by the valued discovered by the brtue force method   
    Dcryption1(alpha, K, Z);   //takes the array, the value of the key and the length of the array
}

/* ---------------------------------------------------------------
function to set all values of an array to zero 

It takes and array of type char and modifies it to equal 0 
for every value upto the number given(N)
-----------------------------------------------------------------*/

void zero(char *x, int N){  //takes pointer and number of charaters in arrary 
    int i =0; 
    for(i= 0; i < N; i++){  //start loop that increments 
    x[i] = 0;               //set value to zero
    }                       //repeat lopp
}
