#include <stdio.h>

int main() {
    int n;
    int checkIfPrime = 1;  

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n <= 1) {
        checkIfPrime = 0;
    } else if (n > 2) {
        if (n % 2 == 0) {
            checkIfPrime = 0;
        } else {
            for (int x = 3; x * x <= n; x += 2) {
                if (n % x == 0) {
                    checkIfPrime = 0;
                    break;
                }
            }
        }
    }

    if (checkIfPrime) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
