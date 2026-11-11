#include <stdio.h>

// Structure using ordinary unsigned int members
struct OrdinaryFlags {
    unsigned int flag1;
    unsigned int flag2;
    unsigned int flag3;
    unsigned int flag4;
};

// Structure using one-bit bit-fields
struct BitFieldFlags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int flag4 : 1;
};

int main() {
    printf("Size comparison of structures with 4 Boolean-like flags:\n");
    printf("----------------------------------------------------\n");
    printf("Size of Ordinary Structure : %zu bytes\n", sizeof(struct OrdinaryFlags));
    printf("Size of Bit-field Structure  : %zu bytes\n", sizeof(struct BitFieldFlags));
    
    printf("\nKey Observation:\n");
    printf("- The ordinary structure typically allocates a full word (usually 4 bytes each) "
           "for every member, resulting in a larger footprint.\n");
    printf("- The bit-field structure packs the flags into fewer bytes (often packed into a "
           "single 4-byte container, or potentially less depending on alignment).\n");
    printf("- Note that memory layout guarantees are language-dependent, and exact "
           "padding/alignment rules vary across different compilers and architectures.\n");

    return 0;
}