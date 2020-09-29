#include <stdio.h>

int main (void) {
    int n;
    int line = 1;
    printf("Enter size: ");
    scanf("%d", &n);
    
    for (; line <= n; line++) {
        int length = 1;
        for (int row = 1; row <= n; row++) {
            if ((row == 2 * length - 1 && line != 2 * length && line < n - 2 * length + 1) || (row == n - line && line % 2 == 0 && row < n - 2 * length ) || (row > n - 2 * length && row % 2 == 1 && row != line - 1)) {
                printf("*");
                length += 1;
            } else if ((line % 2 == 1 && row >= line - 1 && row <= n - line + 1) || ((line > n / 2 + 1) && (line % 2 == 1 && row <= line && row >= n - line + 1))) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
    }
