#include <stdio.h>

struct Permissions {
    unsigned int read : 1;
    unsigned int write : 1;
    unsigned int execute : 1;
    unsigned int admin : 1;
};

int main() {
    struct Permissions p;
    int r, w, x, a;

    printf("Enter permissions (0 or 1) for Read, Write, Execute, Admin:\n");
    printf("Read: "); scanf("%d", &r);
    printf("Write: "); scanf("%d", &w);
    printf("Execute: "); scanf("%d", &x);
    printf("Admin: "); scanf("%d", &a);

    p.read = r ? 1 : 0;
    p.write = w ? 1 : 0;
    p.execute = x ? 1 : 0;
    p.admin = a ? 1 : 0;

    printf("\nPermission Record (rwxA format): ");
    printf("%c", p.read ? 'r' : '-');
    printf("%c", p.write ? 'w' : '-');
    printf("%c", p.execute ? 'x' : '-');
    printf("%c\n", p.admin ? 'A' : '-');

    return 0;
}