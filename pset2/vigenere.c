#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool VerifyArgs(int argc, char *argv[]);
void Vigenere(char key[], char plainText[]);

int
main(int argc, char *argv[])
{
    if (!VerifyArgs(argc, argv)){
        printf("Sumfin bad happen.\n");
        return 1;
    }
    
    string plainText;
    do{
        printf("String to encrypt: ");
        plainText = GetString();
    }
    while (strlen(plainText) <= 0);
    
    printf("%s\n", plainText);
    Vigenere(argv[1], plainText);
    return 0;
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

void
Vigenere(char key[], char plainText[])
{
    int keyElement, rotation = 0;
    int maxKey = strlen(key);
    int textLength = strlen(plainText);
    
    for (int i = 0; i < textLength; i++)
    {
        keyElement = keyElement % maxKey;
        
        if (isupper(key[keyElement]))
            rotation = (key[keyElement] - 'A');
        else
            rotation = (key[keyElement] - 'a');

        if (isupper(plainText[i])){
            printf("%c", ((plainText[i] - 'A' + rotation) % 26) + 'A');
            keyElement++;
        }
        else if (islower(plainText[i])){
            printf("%c", ((plainText[i] - 'a' + rotation) % 26) + 'a');
            keyElement++;
        }
        else
            printf("%c", plainText[i]);      
    }
    
    printf("\n");
}

