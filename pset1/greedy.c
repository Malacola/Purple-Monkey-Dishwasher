#include <cs50.h>
#include <stdio.h>
#include <math.h>

int
main(void)
{
    printf("How much change owed?: ");
    float changeOwed = GetFloat();
    
    if (!changeOwed > 0)
    {
        do{
        printf("Nice try, but change owed must be greater than zero: ");
        changeOwed = GetFloat();
        } while (!changeOwed > 0);
    }
    
    int cents = round(changeOwed * 100);
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
       
    while (cents >= 25){
        quarters = cents / 25;
        cents = cents % 25;
    }
    printf("Quarters given: %d \n", quarters);
        
    while (cents >= 10){
        dimes = cents / 10;
        cents = cents % 10;
    }
    printf("Dimes given: %d\n", dimes);
        
    while (cents >= 5){
        nickels = cents / 5;
        cents = cents % 5;
    }
    printf("Nickels given: %d \n", nickels);
        
    while (cents >= 1){
        pennies = cents / 1;
        cents = cents % 1;
    }
    printf("Pennies given: %d \n", pennies);
    
    int totalCoins = quarters+nickels+dimes+pennies;
    printf("I owe you %d coins \n", totalCoins); 
}
