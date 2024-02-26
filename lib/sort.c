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

int* selectionSort(int* numbers, size_t n)
{
    if (sorted(numbers, &n))
    {
        return numbers;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }

    return numbers;
}
