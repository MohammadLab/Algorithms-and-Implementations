#include <stdio.h>

int main() {
    int year;

    // Read a year
    printf("Please enter a year: ");
    scanf("%d", &year);

    // Check if it's a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("The year %d is a leap year.\n", year);
    } else {
        printf("The year %d is not a leap year.\n", year);
    }

    return 0;
}
