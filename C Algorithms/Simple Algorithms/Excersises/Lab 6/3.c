#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer value for triangle dimensions: ");
    scanf("%d", &n);

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= x; y++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
