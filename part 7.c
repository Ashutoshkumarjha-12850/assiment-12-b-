#include <stdio.h>

struct DeviceStatus {
    unsigned int power : 1;   // 1 bit (0 to 1)
    unsigned int mode : 2;    // 2 bits (0 to 3)
    unsigned int error : 1;   // 1 bit (0 to 1)
    unsigned int battery : 4; // 4 bits (0 to 15)
};

int main() {
    struct DeviceStatus dev;
    int p, m, e, b;

    printf("Enter power (0-1): ");
    scanf("%d", &p);
    printf("Enter mode (0-3): ");
    scanf("%d", &m);
    printf("Enter error status (0-1): ");
    scanf("%d", &e);
    printf("Enter battery level (0-15): ");
    scanf("%d", &b);

    // Validation
    dev.power = p & 1;
    dev.mode = (m >= 0 && m <= 3) ? m : 0;
    dev.error = e & 1;
    dev.battery = (b >= 0 && b <= 15) ? b : 0;

    printf("\n--- Device Status Summary ---\n");
    printf("Power   : %u\n", dev.power);
    printf("Mode    : %u\n", dev.mode);
    printf("Error   : %u\n", dev.error);
    printf("Battery : %u/15\n", dev.battery);
    
    printf("\nNote: The exact memory layout and packing order of bit-fields "
           "(e.g., left-to-right vs. right-to-left) are implementation-defined "
           "and compiler-dependent.\n");

    return 0;
}