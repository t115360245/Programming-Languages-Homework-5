#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringReverse(const char strArray[]);

int main(void)
{
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }

    printf("The string printed backward is: ");
    stringReverse(str);
    printf("\n");

    system("pause");
    return 0;
}

void stringReverse(const char strArray[])
{
    if (strArray[0] == '\0')
    {
        return;
    }

    stringReverse(&strArray[1]);
    putchar(strArray[0]);
}
