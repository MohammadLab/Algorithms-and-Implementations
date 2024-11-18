#include <stdio.h>
#include <math.h> // Include math library

// This function displays a menu of mathematical operation options and gets the user's choice
char displayMenuAndGetChoice(void)
{
    char choice;

    // Displaying the menu options
    printf("Select one of the following items:\n");
    printf("B) - Binary Mathematical Operations.\n");
    printf("U) - Unary Mathematical Operations.\n");
    printf("A) - Advanced Mathematical Operations, using variables.\n");
    printf("V) - Define variables and assign them values.\n");
    printf("E) - Exit\n");

    // Prompting the user to select a mode
    printf("Select Desired Mode:\n");

    // Reading the user's choice
    scanf(" %c", &choice);

    // Returning the user's choice
    return choice;
}

// This function performs binary mathematical operations based on the specified operation
float performBinaryOperation(float val1, float val2, char operation)
{
    float result = 0;

    // Using a switch statement to determine the operation to be performed
    switch (operation)
    {
    case '+':
        result = val1 + val2;
        break;
    case '-':
        result = val1 - val2;
        break;
    case '*':
        result = val1 * val2;
        break;
    case '/':
        // Checking for division by zero before performing division
        if (val2 != 0)
        {
            result = val1 / val2;
        }
        else
        {
            printf("Division by zero is not allowed.\n");
        }
        break;
    case '%':
        // Using the fmod function to calculate the remainder after division
        result = fmod(val1, val2);
        break;
    case 'P':
        // Using the pow function to calculate val1 raised to the power of val2
        result = pow(val1, val2);
        break;
    case 'X':
        // Ternary operator to find the maximum of val1 and val2
        result = (val1 > val2) ? val1 : val2;
        break;
    case 'I':
        // Ternary operator to find the minimum of val1 and val2
        result = (val1 < val2) ? val1 : val2;
        break;
    default:
        // Handling invalid binary operation
        printf("Invalid binary operation.\n");
        return 0;
    }

    // Returning the result of the binary operation
    return result;
}

// This function performs unary mathematical operations based on the specified operation
float performUnaryOperation(float unaryOperand, char operation)
{
    float result = 0;

    // Using a switch statement to determine the operation to be performed
    switch (operation)
    {
    case 'S':
        // Calculating the square root of the unary operand
        result = sqrt(unaryOperand);
        break;
    case 'L':
        // Calculating the natural logarithm of the unary operand
        result = log(unaryOperand);
        break;
    case 'E':
        // Calculating the exponential function raised to the power of the unary operand
        result = exp(unaryOperand);
        break;
    case 'C':
        // Rounding up to the nearest integer
        result = ceil(unaryOperand);
        break;
    case 'F':
        // Rounding down to the nearest integer
        result = floor(unaryOperand);
        break;
    default:
        // Handling invalid unary operation
        printf("Invalid unary operation.\n");
    }

    // Returning the result of the unary operation
    return result;
}

void exitProgram()
{
    // Print out parting message
    printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");
}

int main(void)
{
    char mode, operation, operator= 'O', element, var;        // declare character variables for future use
    float result = 0.0, val1 = 0.0, val2 = 0.0, unaryOperand; // declare float variables for future use
    float memory[5] = {0.0, 0.0, 0.0, 0.0, 0.0};              // create an array 5 large to represent a, b, c, d, e. initialize them to 0.0

    do
    {
        mode = displayMenuAndGetChoice(); // call function to print menu

        // switch in between all the modes
        switch (mode)
        {

            //  Case for binary calculations
        case 'B':
            // Input for the first number
            printf("Enter the first number: \n");
            while (scanf(" %f", &val1) != 1)
            {
                // Handling invalid input for the first number
                printf("Invalid input for the first number. Please enter a valid number: \n");
                while (getchar() != '\n')
                    ;
            }

            // Input for the binary operator
            printf("Enter the operator (+, -, *, /, %%, P, X, I): \n");
            while (1)
            {
                // Validating the binary operator
                scanf(" %c", &operation);
                if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'P' || operation == 'X' || operation == 'I')
                {
                    break;
                }
                else
                {
                    // Handling invalid binary operator
                    printf("Invalid binary operator. Please enter a valid operator: \n");
                    while (getchar() != '\n')
                        ;
                }
            }

            // Input for the second number
            printf("Enter the second number:\n");
            while (scanf(" %f", &val2) != 1)
            {
                // Handling invalid input for the second number
                printf("Invalid input for the second number. Please enter a valid number: \n");
                while (getchar() != '\n')
                    ;
            }

            // Loop for handling errors in calculation
            while (1)
            {
                result = performBinaryOperation(val1, val2, operation);
                if (!isnan(result))
                {
                    // Displaying the result
                    printf("The result is %.2f\n", result);
                    break;
                }
                else
                {
                    // Handling invalid operation
                    printf("Error: Invalid operation. Please enter a new set of numbers and operator: \n");

                    // Re-entering values for a new calculation
                    printf("Enter the first number: \n");
                    while (scanf(" %f", &val1) != 1)
                    {
                        printf("Invalid input for the first number. Please enter a valid number: \n");
                        while (getchar() != '\n')
                            ;
                    }

                    printf("Enter the operator: \n");
                    while (1)
                    {
                        // Validating the binary operator for the new calculation
                        scanf(" %c", &operator);
                        if (operator== '+' || operator== '-' || operator== '*' || operator== '/' || operator== '%' || operator== 'P' || operator== 'X' || operator== 'I')
                        {
                            break;
                        }
                        else
                        {
                            // Handling invalid binary operator
                            printf("Invalid binary operator. Please enter a valid operator: \n");
                            while (getchar() != '\n')
                                ;
                        }
                    }

                    // Re-entering the second number for the new calculation
                    printf("Enter the second number:\n");
                    while (scanf(" %f", &val2) != 1)
                    {
                        printf("Invalid input for the second number. Please enter a valid number: \n");
                        while (getchar() != '\n')
                            ;
                    }
                }
            }
            break;

            // Case for unary calculations
        case 'U':
            // Input for the unary operation
            printf("Please enter the unary operation (S=sqrt, L=log, E=exponentiation, C=ceiling, F=floor):\n");
            scanf(" %c", &operation);

            // Validating the unary operation
            if (operation != 'S' && operation != 'L' && operation != 'E' && operation != 'C' && operation != 'F')
            {
                printf("Invalid unary operation.\n");
                break;
            }

            // Input for the number
            printf("Please enter a number: \n");
            while (scanf(" %f", &unaryOperand) != 1)
            {
                // Handling invalid input for the number
                printf("Invalid input for the number. Please enter a valid number: \n");
                while (getchar() != '\n')
                    ;
            }

            // Checking special cases for certain unary operations
            if (unaryOperand < 0 && operation == 'S')
            {
                printf("Cannot find the square root of a number less than zero.\n");
                break;
            }
            else if (unaryOperand < 0 && operation == 'L')
            {
                printf("Cannot use the log function with a number less than zero.\n");
                break;
            }

            // Performing the unary operation
            result = performUnaryOperation(unaryOperand, operation);

            // Displaying the result
            printf("The result is %.2f\n", result);
            break;

        case 'A':

            // list out advanced menu
            printf("Select one of the following items:\n");
            printf("B) - Binary Operations with variables.\n");
            printf("U) - Unary Operations with variables.\n");
            printf("X) - Exit to the main menu.\n");
            printf("Select Desired Mode\n");
            scanf(" %c", &mode);

            // switch for the advanced menu items
            switch (mode)
            {
                // Case for binary calculations
            case 'B':
                do
                {
                    // Input for the first operand
                    printf("Please enter the first operand ('a', 'b', 'c', 'd', 'e', or number):\n");
                    if (scanf("%c", &var) == 1)
                    {
                        // Checking if the input is a variable
                        if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E'))
                        {
                            // Using the value stored in memory for the variable
                            val1 = memory[var - 'a'];
                            break;
                        }
                        else
                        {
                            // Checking if the input is a valid number
                            if (scanf("%f", &val1) == 1)
                            {
                                while (getchar() != '\n')
                                    ;
                                break;
                            }
                            else
                            {
                                // Handling invalid input
                                printf("If using a variable, type the variable again. If not, then invalid input\n");
                                while (getchar() != '\n')
                                    ;
                            }
                        }
                    }
                    else
                    {
                        // Handling invalid input
                        printf("Invalid input. Please enter a valid letter ('a' to 'e') or a number.\n");
                        while (getchar() != '\n')
                            ;
                    }
                } while (1);

                // Input for the binary operator
                printf("Enter operator (+, -, *, /, %%, P, X, I): ");
                scanf(" %c", &operation);

                do
                {
                    // Validating the binary operator
                    if (operation != '+' && operation != '-' && operation != '*' && operation != '/' &&
                        operation != '%' &&
                        operation != 'P' &&
                        operation != 'X' &&
                        operation != 'I')
                    {
                        // Handling invalid operator
                        printf("Invalid operator. Please enter a valid operator (+, -, *, /, %%, P, X, I): \n");
                        while (getchar() != '\n')
                            ;
                        scanf(" %c", &operation);
                    }
                    else
                    {
                        break;
                    }

                } while (1);

                do
                {
                    // Input for the second operand
                    printf("Please enter the second operand ('a', 'b', 'c', 'd', 'e', or number):\n");
                    if (scanf("%c", &var) == 1)
                    {
                        // Checking if the input is a variable
                        if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E'))
                        {
                            // Using the value stored in memory for the variable
                            val2 = memory[var - 'a'];
                            break;
                        }
                        else
                        {
                            // Checking if the input is a valid number
                            if (scanf("%f", &val2) == 1)
                            {
                                while (getchar() != '\n')
                                    ;
                                break;
                            }
                            else
                            {
                                // Handling invalid input
                                printf("If using a variable, type the variable again. If not, then invalid input\n");
                                while (getchar() != '\n')
                                    ;
                            }
                        }
                    }
                    else
                    {
                        // Handling invalid input
                        printf("Invalid input. Please enter a valid letter ('a' to 'e') or a number.\n");
                        while (getchar() != '\n')
                            ;
                    }
                } while (1);

                // Performing the binary operation
                result = performBinaryOperation(val1, val2, operation);
                printf("The result is %.2f\n", result);
                break;

                // Case for unary calculations
            case 'U':
                // Input for the unary operation
                printf("Please enter the unary operation (S=sqrt, L=log, E=exponentiation, C=ceiling, F=floor):\n");
                scanf(" %c", &operation);

                // Validating the unary operation
                if (operation != 'S' && operation != 'L' && operation != 'E' && operation != 'C' && operation != 'F')
                {
                    printf("Invalid unary operation.\n");
                    while (getchar() != '\n')
                        ;
                }

                // Input for the operand
                printf("Please enter the operand ('a', 'b', 'c', 'd', 'e'):\n");
                scanf(" %c", &var);

                // Checking if the operand is a variable
                if (var >= 'a' && var <= 'e')
                {
                    // Using the value stored in memory for the variable
                    unaryOperand = memory[var - 'a'];
                }
                else
                {
                    // Parsing the operand as a float
                    sscanf(&var, "%f", &unaryOperand);
                }

                // Checking special cases for certain unary operations
                if (unaryOperand < 0 && operation == 'S')
                {
                    printf("Cannot find the square root of a number less than zero.\n");
                    break;
                }
                else if (unaryOperand < 0 && operation == 'L')
                {
                    printf("Cannot use the log function with a number less than zero.\n");
                    break;
                }

                // Performing the unary operation
                result = performUnaryOperation(unaryOperand, operation);

                // Displaying the result
                printf("The result is %.2f\n", result);
                break;

            case 'X':
                // leave advanced menu
                break;

            default:
                printf("Invalid option. \n");
                break;
            }

            break;

            // Case for defining variables and assigning values
        case 'V':
            // Input for the memory element
            printf("Enter the memory element (a, b, c, d, e): \n");
            if (scanf(" %c", &element) != 1 || (element < 'a' || element > 'e'))
            {
                // Handling invalid memory element
                printf("Invalid memory element. Please enter a, b, c, d, or e.\n");
                while (getchar() != '\n')
                    ;
                break;
            }

            // Input for the value to save in memory
            printf("Please enter the value to save in memory slot '%c':\n", element);
            while (scanf("%f", &memory[element - 'a']) != 1)
            {
                // Handling invalid input for the value
                printf("Invalid input for the value. Please enter a valid number: \n");
                while (getchar() != '\n')
                    ;
            }
            break;

        // Case for exiting the program
        case 'E':
            exitProgram();
            break;

        default:
            // Handling invalid option
            printf("Invalid option. Please select a valid option.\n");
            while (getchar() != '\n')
                ;
        }
    } while (mode != 'E'); // loop until user inputs 'E' to close calculator, and terminate program

    return 0;
}
