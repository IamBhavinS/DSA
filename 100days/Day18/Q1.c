/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

#include <stdio.h>

int main() {
    int n, k;
    int a[100], temp[100];
    int i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    for (i = 0; i < n; i++) {
        temp[(i + k) % n] = a[i];
    }

    printf("Rotated array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    printf("\n");

    return 0;
}
