#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
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

void generateArray(int A[], int arraySize)
{
    for (int x = 0; x < arraySize; x++)
    {
        A[x] = rand() % 100;
    }
}

int main()
{
    srand(time(NULL));

    int arraySize = 64;
    int A[arraySize];
    generateArray(A, arraySize);

    printf("before sorted: \n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // insertionSort(A, arraySize);
    // quickSort(A, 0, arraySize);
    mergeSort(A, 0, arraySize - 1);
    printf("after sorted: \n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", A[i]);
    }
    reverseArray(A, 0, arraySize - 1);
    printf("\n after reversed: \n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
