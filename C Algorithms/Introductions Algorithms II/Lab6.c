#include <stdio.h>

int first_positive(const int A[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            return A[i];
        }
    }
    return 0;
}

int main()
{
    int A[10000] = {0};
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("%d", first_positive(A, n));

    return 0;
}