#include <stdio.h>

enum Result { FAIL, PASS, DISTINCTION };

enum Result getResultStatus(float average) {
    if (average >= 75.0f) {
        return DISTINCTION;
    } else if (average >= 40.0f) {
        return PASS;
    } else {
        return FAIL;
    }
}

int main() {
    float marks;
    printf("Enter the student's average marks: ");
    if (scanf("%f", &marks) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    enum Result res = getResultStatus(marks);

    printf("Result Status: ");
    switch (res) {
        printf("Result Status: ");
        case FAIL:
            printf("FAIL (Numeric value: %d)\n", res);
            break;
        case PASS:
            printf("PASS (Numeric value: %d)\n", res);
            break;
        case DISTINCTION:
            printf("DISTINCTION (Numeric value: %d)\n", res);
            break;
    }

    return 0;
}