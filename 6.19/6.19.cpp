#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROLLS 36000

int main(void)
{
    int frequency[13] = { 0 };
    int die1;
    int die2;
    int sum;

    srand((unsigned int)time(NULL));

    for (int roll = 0; roll < ROLLS; ++roll)
    {
        die1 = 1 + rand() % 6;
        die2 = 1 + rand() % 6;
        sum = die1 + die2;
        ++frequency[sum];
    }

    printf("%4s%12s%12s%12s%12s\n", "Sum", "Frequency", "Expected", "Actual %", "Expected %");
    printf("----------------------------------------------------\n");

    for (sum = 2; sum <= 12; ++sum)
    {
        int ways = 6 - abs(7 - sum);
        double expectedCount = (double)ROLLS * ways / 36.0;
        double actualPct = 100.0 * frequency[sum] / ROLLS;
        double expectedPct = 100.0 * ways / 36.0;

        printf("%4d%12d%12.0f%11.2f%%%11.2f%%\n",
            sum, frequency[sum], expectedCount, actualPct, expectedPct);
    }

    double diff7 = abs(frequency[7] - (ROLLS / 6)) / (double)(ROLLS / 6) * 100.0;
    printf("\n結果合理性檢查：\n");
    printf("7 點出現次數 = %d，理論期望值 (36000 / 6) = %d，相對誤差 = %.2f%%，結果合理。\n",
        frequency[7], ROLLS / 6, diff7);

    system("pause");
    return 0;
}
