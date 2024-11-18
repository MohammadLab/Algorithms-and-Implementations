#include <stdio.h>

int main() {
    long long isbn = 0;
    int sum = 0;

    // Read the first twelve digits of ISBN-13 without an array
    printf("Enter the first twelve digits of ISBN-13: ");
    for (int i = 0; i < 12; i++) {
        char digit;
        scanf("%1c", &digit);
        if (digit >= '0' && digit <= '9') {
            int num = digit - '0';
            isbn = isbn * 10 + num;
            if (i % 2 == 0) {
                sum += num;
            } else {
                sum += num * 3;
            }
        }
    }

    // Calculate the check digit
    int remainder = sum % 10;
    int checkDigit;
    if (remainder == 0) {
        checkDigit = 0;
    } else {
        checkDigit = 10 - remainder;
    }

    // Display the check digit
    printf("The check digit is %d.\n", checkDigit);

    return 0;
}
