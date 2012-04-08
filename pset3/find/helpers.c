/**************************************************************************** 
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{  
    int max = n - 1;
    int min = 0;
    int mid = 0;
    
    while (max >= min)
    {
        mid = (min + max) / 2;
        if (array[mid] < value)
            min = mid + 1;
        else if (array[mid] > value)
            max = mid - 1;
        else
            return true;
    }
    
    return false;
}


/*
 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
    bool swapped = false;
    
    //for (int i = 0; i < n; i++)
    //    printf("%d ", values[i]);
    
    printf("\n");

    for (int x = 0, length = n - 1; x < length; x++){
        swapped = false;
        for (int i = 0, p = length; i < p; i++){
            if (values[i] > values[i + 1])
            {
                int tmp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    
    //for (int i = 0; i < n; i++)
    //    printf("%d ", values[i]);
        
    return;
}
