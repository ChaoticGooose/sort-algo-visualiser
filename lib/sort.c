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

    for (int i = 0; i < n-1; i++)
    {
        /* assume min is first elem */
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (numbers[j] < numbers[min])
            {
                min = j;
                continue;
            }
        }

        /* swap i and min */
        if (min != i)
        {
            int tmp = numbers[min];
            numbers[min] = numbers[i];
            numbers[i] = tmp;
        }
    }

    return numbers;
}

int* bubbleSort(int* numbers, size_t n)
{
    if (sorted(numbers, &n))
    {
        return numbers;
    }

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (numbers[j] > numbers[j+1])
            {
                /* swap numbers */
                int tmp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = tmp;
            }
        }
    }

    return numbers;
}
