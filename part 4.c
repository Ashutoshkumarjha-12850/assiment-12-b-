#include <stdio.h>

enum MenuChoice { ADD = 1, SUBTRACT, MULTIPLY, DIVIDE, EXIT };

int main() {
    int choice;
    double num1, num2;

    do {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == EXIT) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        if (choice < ADD || choice > DIVIDE) {
            printf("Invalid menu choice. Please try again.\n");
            continue;
        }

        printf("Enter two numbers: ");
        if (scanf("%lf %lf", &num1, &num2) != 2) {
            printf("Invalid numbers entered.\n");
            break;
        }

        switch ((enum MenuChoice)choice) {
            case ADD:
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case SUBTRACT:
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case MULTIPLY:
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case DIVIDE:
                if (num2 == 0.0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                }
                break;
            default:
                break;
        }
    } while (1);

    return 0;
}