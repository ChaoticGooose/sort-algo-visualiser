#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void randomise(int* numbers, size_t* n)
{
    for (int i = 0; i < *n - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (*n - i) + 1);
        int t = numbers[j];
        numbers[j] = numbers[i];
        numbers[i] = t;
    }
}

bool sorted(int* numbers, size_t* n)
{

    for (int i = 1; i < *n; i++)
    {
        if (numbers[i-1] > numbers[i])
        {
            return false;
        }
    }
    return true;
}

int* bogoSort(int* numbers, size_t n)
{
    if (n < 1)
    {
        return numbers;
    }

    // check if array is sorted
    if (sorted(numbers,&n))
    {
        return numbers;
    }
    // randomise array
    while (!sorted(numbers, &n))
    {
        randomise(numbers, &n); 
    }

    return numbers;
}
