#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// #define maxSize 10

void heapify(int heap[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, size, largest);
    }
}

void BuildMaxHeap(int heap[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, size, i);
    }
}

int isEmpty(int size)
{
    return size == 0;
}

int insert(int k, int heap[], int size)
{
    /*
    if (size >= maxSize)
    {
        printf("MAX HEAP OVERFLOW\n");
        return size;
    }
*/
    heap[size] = k;
    size++;

    int i = size - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

    return size;
}

void removeMin(int heap[], int size)
{
    if (isEmpty(size))
    {
        printf("Heap is empty\n");
        return;
    }

    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (heap[i] < heap[minIndex])
        {
            minIndex = minIndex;
        }
    }

    heap[minIndex] = heap[size - 1];
    heapify(heap, size - 1, minIndex);
}

void heapSort(int heap[], int size)
{
    BuildMaxHeap(heap, size);

    for (int i = size - 1; i > 0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        heapify(heap, i, 0);
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
    for (int x = 6; x <= 20; x++)
    {
        int heapSize = pow(2, x);
        int heap[heapSize];
        generateArray(heap, heapSize);
        int size = heapSize;

        clock_t begin = clock();
        heapSort(heap, size);
        clock_t end = clock();

        double time_spent = (double)(end - begin) * 1000000000 / CLOCKS_PER_SEC;
        printf("%d %f\n", heapSize, time_spent);
    }

    return 0;
}
