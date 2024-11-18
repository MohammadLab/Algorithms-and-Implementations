#include <stdio.h>

int main(void) {
    float num1;
    float num2;
    float sum;

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    sum = num1 + num2;

    // Part A: Display in the requested format
    printf("--------------------------------------------------\n");
    printf("|                                                |\n");
    printf("| %7.2f + %7.2f = %7.2f \t\t\t|\n", num1, num2, sum);
    printf("|                                                |\n");
    printf("--------------------------------------------------\n");

    // Part B: Use padding for the printed numbers
    printf("--------------------------------------------------\n");
    printf("|                                                |\n");
    printf("| %7.2f + %7.2f = %7.2f |\n", num1, num2, sum);
    printf("|                                                |\n");
    printf("--------------------------------------------------\n");

    // Part C: Include additional calculations
    float diff = num2 - num1;
    float prod = num1 * num2;
    float div = num1 / num2;

    printf("--------------------------------------------------\n");
    printf("| %7.2f - %7.2f = %7.2f |\n", num2, num1, diff);
    printf("| %7.2f * %7.2f = %7.2f |\n", num1, num2, prod);
    printf("| %7.2f / %7.2f = %7.2f |\n", num1, num2, div);
    printf("|                                                |\n");
    printf("--------------------------------------------------\n");

    return 0;
}
