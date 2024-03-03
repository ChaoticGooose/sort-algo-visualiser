#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void randomise(int* numbers, size_t* n)
{
    srand(time(NULL));
    for (int i = 0; i < *n - 1; i++) 
    {
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
    // randomise array
    while (!sorted(numbers, &n))
    {
        randomise(numbers, &n);
    }

    return numbers;
}

int* insertionSort(int* numbers, size_t n)
{
    if (sorted(numbers, &n))
    {
        return numbers;
    }

    for (int i = 1; i < n; i++)
    {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key)
        {
            numbers[j+1] = numbers[j];
            j = j - 1;
        }
        numbers[j+1] = key;
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

int* mergeSort(int* numbers, size_t n)
{
    if (n < 2)
    {
        return numbers;
    }

    /* split array into two */
    int left_n = n/2;
    int *left = malloc(left_n * sizeof(int));
    memcpy(left, numbers, left_n * sizeof(int));

    int right_n = n - left_n;
    int *right = malloc(right_n * sizeof(int));
    memcpy(right, numbers + left_n, right_n * sizeof(int));

    // recursively sort left and right arrays
    left = mergeSort(left, left_n);
    right = mergeSort(right, right_n);


    return numbers;
}

int* quickSort(int* numbers, size_t n)
{
    // base case
    if (n < 2)
    {
        return numbers;
    }

    int pivot = n-1;
    int i = -1;
    int j = 0;

    while (j < pivot)
    {
        if (numbers[j] < numbers[pivot])
        {
            // swap numbers[i] and numbers[j]
            i++;
            int tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;
        }
        j++;
    }
    
    // Swap numbers[i+1] and numbers[pivot]
    i++;
    int tmp = numbers[i];
    numbers[i] = numbers[pivot];
    numbers[pivot] = tmp;

    quickSort(numbers, i);
    quickSort(numbers + i, n - i);

    return numbers;
}
