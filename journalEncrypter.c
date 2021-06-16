#include <stdio.h>
#include <time.h>

// define symbolic constant that will be used to denote the max length of the string inputted

#define MAX 10000

// define an array journalEntry with size MAX

char journalEntry[MAX];

// prototypes for functions defined below

void getEntry(char journalEntry[]);
void openFile(char journalEntry[]);
void decryptEntry(char journalEntry[]);

// main function

int main(void){

    // create a variable that will be used to determine if user wants to encrypt a journal entry or decrypt a previous one
    
    int selection = 0;

    // ask for input and get it.  Check it.
    
    puts("Are you going to be writing an entry (1) or decrypting a previous entry (2)?");
    while (scanf("%d", &selection) != 1 || (selection != 1 && selection != 2)){
        puts("Please enter 1 or 2!");
        fflush(stdin);
    }
    fflush(stdin);

    // selection structure going to the appropriate functions

    if (selection == 1){
        getEntry(journalEntry);
        
    }
    else {
        decryptEntry(journalEntry);
        printf("%s", journalEntry);
    }
    return 0;  
}

// function getEntry that will get an entry from the user and save it as .txt file.

void getEntry(char journalEntry[]){

    // create a file

    FILE *fp;
    fp = fopen("file.txt", "w");
    
    // get journal entry.

    puts("Start typing your journal entry:");
    fgets(journalEntry, MAX, stdin);

    // define encryption and use a loop

    for (int i = 0; (i < MAX && journalEntry[i] != '\0'); i++){
        journalEntry[i] = journalEntry[i] + 4;
    }

    // save journalEntry in the file.

    fprintf(fp, "%s", journalEntry);
}

void decryptEntry(char journalEntry[]){

    // get previous entry 

    puts("Enter your previous journal entry:");
    fgets(journalEntry, MAX, stdin);
    
    // define decryption and use a loop 
    
    for (int i = 0; (i < MAX && journalEntry[i] != '\0'); i++){
        journalEntry[i] = journalEntry[i] - 4;
    }
}