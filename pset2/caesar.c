#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//cipher formula: c(i) = (p(i)+k)%26
        
bool VerifyArgs(int argc, char *argv[]);
void Caesar(int key, char plainChar);

int
main(int argc, char *argv[])
{    
    if (!VerifyArgs(argc, argv)){
        printf("Sumfin bad happen.\n");
        return 1;
    }
    
    int key = atoi(argv[1]);    
    printf("The key is... %d\n", key);
    
    printf("Okay, now gimme a phrase to encrypt...: ");
    string plainText = GetString();
    
    if (strlen(plainText) == 0){
        do{
        printf("Did you bump enter by mistake? Try again: ");
        plainText = GetString();
        } while (strlen(plainText)== 0);
    }
    
    printf("Encryptings.....\n");
    printf("%s\n", plainText);
    int x = strlen(plainText);  
    for (int i = 0; i < x; i++)
    {
        Caesar(key, plainText[i]);
    }
    printf("\n");
    printf("All Done!\n");
}

bool
VerifyArgs(int argc, char *argv[])
{
    //Check that we have a single argument (ie, two including program name)
    if (argc != 2){
        printf("Invalid number of arguments! Just give me one number, bra.\n");
        return false;
    }
    
    //Check that argument is an int...
    int argLength = strlen(argv[1]); 
    for (int i = 0; i < argLength; i++){
        if (!isdigit(argv[1][i])){
            printf("Character %d is not a digit! What're you tryin to pull....\n", i + 1);
            return false;
        }
    }
    return true;
}

void
Caesar(int key, char plainChar)
{
    char cryptoChar;
    if (islower(plainChar))
        cryptoChar = ((plainChar - 'a' + key) % 26) + 'a';
    else if (isupper(plainChar))
        cryptoChar = ((plainChar - 'A' + key) % 26) + 'A';
    else 
        cryptoChar = plainChar;
        
    printf("%c", cryptoChar);
}
