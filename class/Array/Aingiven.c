//Write a C program to insert an element at a given position in an array.

#include <stdio.h>

int main() {
    int arr[100], n, i, x, pos;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &x, &pos);

    for(i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = x;
    n++;

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
