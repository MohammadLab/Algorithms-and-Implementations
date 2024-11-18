#include <stdio.h>

int main(void) {
    int num1, num2, num3;

    // Read three integer values separated by commas
    printf("Please enter 3 numbers (comma separated): ");
    scanf("%d, %d, %d", &num1, &num2, &num3);

    // Find the largest and smallest numbers
    int largest, smallest;
    largest = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);
    smallest = num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3);

    printf("The largest is %d.\n", largest);
    printf("The smallest is %d.\n", smallest);

}
