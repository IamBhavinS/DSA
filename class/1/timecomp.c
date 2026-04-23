//Write a C program to demonstrate different time complexities (O(1), O(n), O(log n), O(n²)) using loops

#include <stdio.h>

int main() {
    int choice, n, i, j, k;

    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter case (1-5): ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: // O(1)
            printf("UPES\n");
            break;

        case 2: // O(n)
            for (i = 1; i <= n; i++) {
                printf("UPES\n");
            }
            break;

        case 3: // O(log n)
            for (i = n; i > 1; i = i / 2) {
                printf("UPES\n");
            }
            break;

        case 4: // O(n)
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= 100; j++) {
                    printf("UPES\n");
                }
            }
            break;

        case 5: // O(n^2)
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    for (k = 1; k <= 100; k++) {
                        printf("UPES\n");
                    }
                }
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
