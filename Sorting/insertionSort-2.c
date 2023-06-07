#include <stdio.h>

void insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {8, 3, 2, 1, 6, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Input array: ");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
