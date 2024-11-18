#include <stdio.h>
#include <stdbool.h>

bool matrix_mirrored(const int n, const int A[][5])
{
    for (int i = 0; i < n; i++)
    {
        bool palindrome = true;
        int length = 5;

        for (int j = 0; j < length / 2; j++)
        {
            if (A[i][j] != A[i][length - j - 1])
            {
                palindrome = false;
                break;
            }
        }

        if (palindrome == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    int A[n][5];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    if (matrix_mirrored(n, A))
    {
        printf("Y");
    }
    else
    {
        printf("N");
    }
    return 0;
}