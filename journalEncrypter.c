#include <stdio.h>
#include <time.h>

#define MAX 10000

char journalEntry[MAX];

void getEntry(char journalEntry[]);
void openFile(char journalEntry[]);
void decryptEntry(char journalEntry[]);

int main(void){
    
    int selection = 0;
    
    puts("Are you going to be writing an entry (1) or decrypting a previous entry (2)?");
    while (scanf("%d", &selection) != 1 || (selection != 1 && selection != 2)){
        puts("Please enter 1 or 2!");
        fflush(stdin);
    }
    fflush(stdin);

    if (selection == 1){
        getEntry(journalEntry);
        
    }
    else {
        decryptEntry(journalEntry);
        printf("%s", journalEntry);
    }
    return 0;  
}

void getEntry(char journalEntry[]){

    

    FILE *fp;
    fp = fopen("yes.txt", "w");
    
    // get journal entry.

    puts("Start typing your journal entry:");
    fgets(journalEntry, MAX, stdin);

    // define encryption function

    for (int i = 0; (i < MAX && journalEntry[i] != '\0'); i++){
        journalEntry[i] = journalEntry[i] + 4;
    }

    fprintf(fp, "%s", journalEntry);
}

void decryptEntry(char journalEntry[]){

    puts("Enter your previous journal entry:");
    fgets(journalEntry, MAX, stdin);
    
    // define decryption function 
    for (int i = 0; (i < MAX && journalEntry[i] != '\0'); i++){
        journalEntry[i] = journalEntry[i] - 4;
    }
}