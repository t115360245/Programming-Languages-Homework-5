#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int recursiveMaximum(const int array[], int size);

int main(void)
{
    int a[SIZE] = { 37, 2, 6, 4, 89, 8, 10, 12, 68, 45 };

    printf("Array elements:\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }
    printf("\n");

    int maxVal = recursiveMaximum(a, SIZE);
    printf("Maximum value in the array is: %d\n", maxVal);

    system("pause");
    return 0;
}

int recursiveMaximum(const int array[], int size)
{
    if (size == 1)
    {
        return array[0];
    }

    int maxOfRest = recursiveMaximum(array, size - 1);
    return (array[size - 1] > maxOfRest) ? array[size - 1] : maxOfRest;
}
