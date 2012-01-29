#include <cs50.h>
#include <stdio.h>

int
main(void)
{
    printf("Number of Days in month: ");
    int days = GetInt();
    
    if ((days > 31) || (days < 28))
    {
        do{
        printf("Try again. Months cannot have >31 or <28 days: ");
        days = GetInt();
        } while ((days > 31) || (days < 28));
    }
    
    printf("Number of pennies: ");
    long long pennies = GetLongLong();
    
    if (pennies < 0)
    {
        do{
        printf("Try again. Must be non-negative amount of pennies: ");
        pennies = GetLongLong();
        } while (pennies < 0);
    }
      
    for (int i = 0; i < days; i++)
        pennies = pennies*2;
    
    pennies = pennies/100;
        
    printf("$%.1lld \n", pennies);
}

