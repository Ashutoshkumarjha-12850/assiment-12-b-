#include <stdio.h>

enum Type { INT_VALUE, FLOAT_VALUE, CHAR_VALUE };

struct TaggedValue {
    enum Type tag;
    union {
        int iVal;
        float fVal;
        char cVal;
    } data;
};

void printValue(struct TaggedValue tv) {
    switch (tv.tag) {
        case INT_VALUE:
            printf("Integer Value: %d\n", tv.data.iVal);
            break;
        case FLOAT_VALUE:
            printf("Float Value: %.2f\n", tv.data.fVal);
            break;
        case CHAR_VALUE:
            printf("Character Value: %c\n", tv.data.cVal);
            break;
        default:
            printf("Unknown tag type.\n");
    }
}

int main() {
    struct TaggedValue v1, v2, v3;

    v1.tag = INT_VALUE;
    v1.data.iVal = 42;

    v2.tag = FLOAT_VALUE;
    v2.data.fVal = 3.14f;

    v3.tag = CHAR_VALUE;
    v3.data.cVal = 'Z';

    printValue(v1);
    printValue(v2);
    printValue(v3);

    return 0;
}