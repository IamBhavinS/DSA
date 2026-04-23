//Write a C program to perform linear search on an array

#include <stdio.h>

int main() {
    int n,find,i,found=0;

    printf("Enter number of elements:-");
    scanf("%d", &n);

    if (n<=0) {
        printf("size invalid.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:-\n",n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    printf("Enter element to search:-");
    scanf("%d",&find);

    for (i=0;i<n;i++) {
        if (arr[i]==find) {
            found=1;
            break;
        }
    }

    if (found)
        printf("Element found at position %d\n",i+1);
    else
        printf("Element not found\n");

    return 0;
}
