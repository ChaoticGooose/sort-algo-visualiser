#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lib/sort.h"

#include <time.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./visulise <elements>");
        return 1;
    }
    
    size_t n = atoi(argv[1]);
    int list[n];

    for (int i = 0; i < n; i++)
    {
        list[i] = i;
    }
    
    randomise(list, &n);

    clock_t t; 
    t = clock();
    int* sorted = selectionSort(list, n);
    t = clock() - t;
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    
    for (int i = 0; i < n; i++)
    {
        printf("%i ", sorted[i]);
    }
    printf("\n");

    printf("took %f seconds to execute \n", time_taken); 
}
