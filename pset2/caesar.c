#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//cipher formula: c(i) = (p(i)+k)%26
    //have to verify command line argument
        //argv[1] must be non negative int
        //argc must == 1
    //have to convert argument to number...
        //int i = atoi(someString);
int
main(int argc, char *argv[])
{
    //We want a single argument (two counting the program name)
    if (argc != 2)
    {
        printf("Invalid number of arguments! Just give me one number, bra.\n");
        return 1;
    }
    
    //Check that argument is an int...
    int argLength = strlen(argv[1]); 
    for (int i = 0; i < argLength; i++){
        if (!isdigit(argv[1][i])){
            printf("Character %d is not a digit! What're you tryin to pull....\n", i + 1);
            return 2;
        }
    }
    
    int key = atoi(argv[1]);
    
    printf("The key is... %d\n", key);
        
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);

}
