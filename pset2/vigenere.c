#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool VerifyArgs(int argc, char *argv[]);

int
main(int argc, char *argv[])
{
    if (!VerifyArgs(argc, argv)){
        printf("Sumfin bad happen.\n");
        return 1;
    }
}

bool
VerifyArgs(int argc, char *argv[])
{
    //Check that we have a single argument (ie, two including program name)
    if (argc != 2){
        printf("Invalid number of arguments! Just give me one number, bra.\n");
        return false;
    }
    
    //Check that argument is a string...
    int argLength = strlen(argv[1]); 
    for (int i = 0; i < argLength; i++){
        if (!isalpha(argv[1][i])){
            printf("Character %d is not a character! What're you tryin to pull....\n", i + 1);
            return false;
        }
    }
    return true;
}
