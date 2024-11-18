#include <stdio.h>


float calculateCircleArea(float radius)
{
    return 3.14 * radius * radius;
}

int calculateFactorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * calculateFactorial(n - 1);
    }
}

void decimalToBinary(int decimalNumber)
{
    if (decimalNumber > 0)
    {
        decimalToBinary(decimalNumber / 2);
        printf("%d", decimalNumber % 2);
    }
}


int main()
{
    float radius, area;
    int n, decimalNumber, factorial;

    // Get the radius of the circle from the user
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Get a positive integer for factorial calculation from the user
    printf("Enter a positive integer for factorial calculation: ");
    scanf("%d", &n);

    // Get a positive decimal number for binary conversion from the user
    printf("Enter a positive decimal number for binary conversion: ");
    scanf("%d", &decimalNumber);

    // Calculate the area of the circle using the provided radius
    area = calculateCircleArea(radius);

    // Calculate the factorial of the given integer
    factorial = calculateFactorial(n);

    // Print the binary representation of the decimal number
    printf("Binary representation: ");
    decimalToBinary(decimalNumber);
    printf("\n");

    // Print the calculated area of the circle
    printf("Area of the circle: %.2f\n", area);

    // Print the calculated factorial of the integer
    printf("Factorial of %d: %d\n", n, factorial);

    return 0;
}
