#include <stdio.h>
#include "array.h"
#include <fstream>
#include <iostream>

Array* array_create_and_read(FILE* input)
{
    int n;
    fscanf(input, "%d", &n);
    /* Create array */
    Array* arr = array_create(n);
    /* Read array data */
    for (int i = 0; i < n; ++i)
    {
        int x;
        fscanf(input, "%d", &x);
        array_set(arr, i, x);
    }
    return arr;
}

void task1(Array* arr)
{
    if (!arr) return;
    size_t n = array_size(arr);
    int max_i = 0, min_i = 0;
    int sum = 0;
    for (int i = 1;i < n;i++) {
        if (array_get(arr, max_i) < array_get(arr, i))
            max_i = i;
        if (array_get(arr, min_i) > array_get(arr, i))
            min_i = i;
    }
    if (min_i > max_i) {
        for (int i = max_i + 1; i < min_i;i++) {
            sum += array_get(arr, i);
        }
    }
    else {
        for (int i = min_i + 1; i < max_i;i++) {
            sum += array_get(arr, i);
        }
    }
    std::cout << sum;
}

int main(int argc, char** argv)
{
    Array* arr = NULL;
    FILE* input = fopen(argv[1], "r");
    arr = array_create_and_read(input);
    task1(arr);
    array_delete(arr);
    fclose(input);
}
