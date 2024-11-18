#include <stdio.h>

int main() {

    int n;
    printf("Enter an integer from 1-1000): ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        printf("Invalid, input must be between an integer 1-1000.\n");
    } else {
        int sum;
        for (int x = 1; x <= n; x++) {
            sum += x;
        }

        double average = (double) sum / n;
        printf("sum=%d, average=%.2lf\n", sum, average);
    }

    return 0;
}