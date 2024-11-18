#include <stdio.h>
#include <ctype.h>
#include <string.h>

int extract_digits(const char in[], char out[])
{
    int count = 0, sum = 0;
    int length = strlen(in);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(in[i]))
        {
            sum = sum + in[i] - '0';
            out[count++] = in[i];
        }
    }
    out[count] = '\0';
    return sum;
}

int main(void)
{
    char in[1000], out[1000];
    scanf("%s", in);
    int sum = extract_digits(in, out);
    printf("%s %d\n", out, sum);
}