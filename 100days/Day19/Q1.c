/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    int arr[1000];
    int i, left, right;
    int minSum, sum;
    int x, y;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    left = 0;
    right = n - 1;
    minSum = arr[left] + arr[right];
    x = arr[left];
    y = arr[right];

    while (left < right) {
        sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", x, y);

    return 0;
}
