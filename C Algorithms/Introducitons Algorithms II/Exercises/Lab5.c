#include <stdio.h>

int *select_ptr(int *A)
{
    int *min = A;
    for (; *A != 0; A++)
    {
        if (*A < *min)
            min = A;
    }
    return min;
}

int main()
{
    int A[10000];
    int n, i = 0;

    while (1)
    {
        scanf("%d", &A[i]);
        if (A[i] == 0)
        {
            break;
        }
        i++;
    }

    for (int j = 0; A[j] != 0; j++)
    {
        int *min_ptr = select_ptr(&A[j]);
        int temp = A[j];
        A[j] = *min_ptr;
        *min_ptr = temp;
    }

    for (int j = 0; A[j] != 0; j++)
    {
        printf("%d", A[j]);
        if (A[j + 1] != 0)
        {
            printf(" ");
        }
    }

    return 0;
}
