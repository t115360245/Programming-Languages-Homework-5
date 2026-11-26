#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

int binarySearch(const int b[], int low, int high, int searchKey);
void printHeader(void);
void printRow(const int b[], int low, int mid, int high);

int main(void)
{
    int a[SIZE];
    int key;
    int result;

    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = 2 * i;
    }

    printf("Enter a number between 0 and 28: ");
    scanf_s("%d", &key);

    printHeader();
    result = binarySearch(a, 0, SIZE - 1, key);

    if (result != -1)
    {
        printf("\n%d found in array element %d\n", key, result);
    }
    else
    {
        printf("\n%d not found\n", key);
    }

    system("pause");
    return 0;
}

int binarySearch(const int b[], int low, int high, int searchKey)
{
    if (low > high)
    {
        return -1;
    }

    int middle = (low + high) / 2;
    printRow(b, low, middle, high);

    if (searchKey == b[middle])
    {
        return middle;
    }
    else if (searchKey < b[middle])
    {
        return binarySearch(b, low, middle - 1, searchKey);
    }
    else
    {
        return binarySearch(b, middle + 1, high, searchKey);
    }
}

void printHeader(void)
{
    printf("\nSubscripts:\n");

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%3d ", i);
    }

    printf("\n");

    for (int i = 1; i <= 4 * SIZE; ++i)
    {
        printf("-");
    }

    printf("\n");
}

void printRow(const int b[], int low, int mid, int high)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (i < low || i > high)
        {
            printf("    ");
        }
        else if (i == mid)
        {
            printf("%3d*", b[i]);
        }
        else
        {
            printf("%3d ", b[i]);
        }
    }

    printf("\n");
}
