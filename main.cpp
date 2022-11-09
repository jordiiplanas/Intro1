#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Header.h"

void RandomList(int pInt[5], int i, int i1);

int main()
{
    srand(time(NULL));
    const int size = 10;

    int array[size];
    RandomList(array, size, 0, 10);
    PrintList(array, size);

    // Write a function to calculate the average of an int array
    printf("Average: %f\n", AverageList(array, size));

    // Write a function to find the mode of an int array (values 0-10)
    printf("Mode of Array: %i\n", ModeOf(array, size));

    // Write a function to find the intersection between 2 arrays

    int array2[size];
    RandomList(array2, size, 0, 10);
    // In this case I will print the intersections
    Intersection(array, array2, size);

    // Write a function that removes duplicate values from an array (setting them to -1)
    RemoveDuplicates(array, size);

    // Write a function that reverses an array
    ReverseArray(array, size);

    // Write a function to shift all elements of an array (to the right)
    ShiftArray(array, size);
}

void PrintList(int list[], int size)
{
    for (int i = 0 ; i < size ; i++)
        printf("Element [%i] = %i\n", i, list[i]);
}
void RandomList(int list[], int size, int min, int max)
{
    for (int i = 0 ; i < size ; i++)
        list[i] = RandomNumber(min, max);
}
int RandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
float AverageList(int list[], int size)
{
    int sum = 0;
    for(int i = 0 ; i < size ; i++)
        sum += list[i];
    return (float)sum / (float) size;
}
int ModeOf(int list[], int size)
{
    int count[11] = {0,0,0,0,0,0,0,0,0,0,0}; //El tamaño está determinado por el maximo y el minimo.
    for (int i=0; i < size; i++) {
        count[list[i]]++;
    }
    int position = 0;
    int max = count[0];
    for (int i=1; i<=size; i++){
        if (count[i] > max)
        {
            position = i;
            max = count[i];
        }
    }
    return position;
}
void Intersection (int list[], int list2[], int size)
{
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0 ; j < size ; j++)
        {
            if (list[i] == list2[j])
            {
                printf("Intersection found! Element: \n\t\tlist1[%i] %i \n\t\tlist2[%i] %i\n", i, list[i],j, list2[j]);
            }
        }
    }
}
void RemoveDuplicates (int list[], int size)
{
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0 ; j < size ; j++)
        {
            if (list[i] == list[j] && i != j)
            {
                list[j] = -1;
            }
        }
    }
}
void ReverseArray(int list[], int size)
{
    int list2[size];
    int counter = 0;
    for (int i = size -1 ; i >= 0  ; i--)
    {
        list2[counter++] = list[i];
    }
    for (int i = 0 ; i < size  ; i++)
    {
        list[i] = list2[i];
    }
}
void ShiftArray(int list[], int size)
{
    for (int i = size ; i > 0 ; i--)
    {
        list[i] = list[i-1];
    }
    list[0] = 0;
}

