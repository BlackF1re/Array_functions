#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

void error()
{
    printf("Вы все сломали. В следующий раз вводите корректные значения.");
    exit(1);
}

void print(int length, int* array)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
}

int sumOfAll(int length, int* array) //A1
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum;
}

int sumOfPositives(int length, int* array) //A2
{
    int sumOfPositives = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] > 0)
            sumOfPositives += array[i];
    }
    return sumOfPositives;
}

int countOfZeros(int length, int* array) //A4
{
    int zeroCounter = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] == 0)
        {
            zeroCounter++;
        }
    }
    return zeroCounter;
}

int sumMinMax(int length, int* array) //A5
{
    int min = array[0];
    for (int i = 0; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    int max = array[0];
    for (int i = 0; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return min + max;
}

int lesserThan(int length, int* array, int a1) //M1
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] < a1)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    system("chcp 1251");
    printf("Выполнено Левицким Павлом, группа 423-2\nВариант 11.\n");
    int lengthOfX, lengthOfY, isDigit;

    printf("\nВведите количество элементов массива X:\t");
    isDigit = scanf_s("%d", &lengthOfX);
    if (lengthOfX < 1 || isDigit != 1)
        error();
    printf("\nВведите количество элементов массива Y:\t");
    isDigit = scanf_s("%d", &lengthOfY);
    if (lengthOfY < 1 || isDigit != 1)
        error();
    srand(time(0));

    int* arrayX = calloc(lengthOfX, sizeof(int));
    for (int i = 0; i < lengthOfX; i++)
    {
        arrayX[i] = rand() % 20 - 10;
    }
    printf("\nМассив X:\n");
    print(lengthOfX, arrayX);
    printf("\n");

    int* arrayY = calloc(lengthOfY, sizeof(int));
    for (int i = 0; i < lengthOfY; i++)
    {
        arrayY[i] = rand() % 20 - 10;
    }
    printf("\nМассив Y:\n");
    print(lengthOfY, arrayY);

    int a1x = sumOfAll(lengthOfX, arrayX); 

    if (a1x < 0)
    {
        printf("\n\nСумма элементов массива X (A1(X)):\t%d\t", a1x);
        int a2x = sumOfPositives(lengthOfX, arrayX);
        printf("\nСумма положительных элементов массива X (A2(X)):\t%d\t", a2x);
        int a4x = countOfZeros(lengthOfX, arrayX);
        printf("\nКол-во нулевых элементов массива X (A4(X)):\t%d\t", a4x);
        int m1x = lesserThan(lengthOfX, arrayX, a1x);
        printf("\nКол-во элементов массива X меньше суммы элементов массива X (M1(X)):\t%d\t", m1x);
        int a2y = sumOfPositives(lengthOfY, arrayY);
        printf("\nСумма положительных элементов массива Y (A2(Y)):\t%d\t\n", a2y);
        float z1 = (a2x + 2.8 * pow(10, -3) * a4x) / (0.3 + m1x * a2y);
        //float z1 = (sumOfPositives(lengthOfX, arrayX) + 2.8 * pow(10, -3) * countOfZeros(lengthOfX, arrayX)) / (0.3 + lesserThan(lengthOfX, arrayX, a1x) * sumOfPositives(lengthOfY, arrayY));
        printf("\nZ1 = %f", z1);
    }
    else printf("\n\nZ1: не было выполнено условие: A1(X) < 0\n");

    if (a1x >= 0)
    {
        int a1y = sumOfAll(lengthOfY, arrayY);
        printf("\nСумма элементов массива Y (A1(Y)):\t%d\t", a1y);
        int m1y = lesserThan(lengthOfY, arrayY, a1y);
        printf("\nКол-во элементов массива Y меньше суммы элементов массива Y (M1(Y)):\t%d\t", m1y);
        int a5x = sumMinMax(lengthOfX, arrayX);
        printf("\nСумма максимального и минимального элементов массива X (A5(X)):\t%d\t\n", a5x);
        float z2 = 0.000135 * a5x + m1y;
        printf("\nZ2 = %f", z2);
    }
    else printf("\n\nZ2: не было выполнено условие: A1(X) >= 0\n");
    free(arrayX);
    free(arrayY);
    return 0;
}