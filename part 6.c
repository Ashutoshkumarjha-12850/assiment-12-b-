#include <stdio.h>

struct Flags {
    unsigned int isOn : 1;
    unsigned int isReady : 1;
};

int main() {
    struct Flags f;
    int val1, val2;

    printf("Enter value for isOn (0 or 1): ");
    scanf("%d", &val1);
    printf("Enter value for isReady (0 or 1): ");
    scanf("%d", &val2);

    // Input validation restricting to 0 or 1
    f.isOn = (val1 != 0) ? 1 : 0;
    f.isReady = (val2 != 0) ? 1 : 0;

    printf("\nStored Bit-field Values:\n");
    printf("isOn  = %u\n", f.isOn);
    printf("isReady = %u\n", f.isReady);

    return 0;
}