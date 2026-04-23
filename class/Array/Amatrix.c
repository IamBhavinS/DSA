//Write a C program to perform addition and multiplication of two matrices.

#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    int A[r1][c1], B[r2][c2], result[50][50];

    // Input first matrix
    printf("\nEnter elements of first matrix:\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input second matrix
    printf("\nEnter elements of second matrix:\n");
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    printf("\nChoose operation:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        if(r1 != r2 || c1 != c2) {
            printf("Addition not possible. Dimensions must match.\n");
        } else {
            for(int i = 0; i < r1; i++)
                for(int j = 0; j < c1; j++)
                    result[i][j] = A[i][j] + B[i][j];

            printf("\nResult (Addition):\n");
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j < c1; j++)
                    printf("%d ", result[i][j]);
                printf("\n");
            }
        }
    }
    else if(choice == 2) {
        if(c1 != r2) {
            printf("Multiplication not possible. Columns of A must equal rows of B.\n");
        } else {
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j < c2; j++) {
                    result[i][j] = 0;
                    for(int k = 0; k < c1; k++) {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            printf("\nResult (Multiplication):\n");
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j < c2; j++)
                    printf("%d ", result[i][j]);
                printf("\n");
            }
        }
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}

