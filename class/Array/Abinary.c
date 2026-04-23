//Write a C program to search for an element in an array using binary search.

#include <stdio.h>

int main() {
    int n,find;

    printf("Enter number of elements:-");
    scanf("%d",&n);

    if (n<=0) {
        printf("size invalid.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:-\n",n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (int i=0; i<n-1;i++) {
        for (int j=0; j<n-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j + 1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Enter element to search:-");
    scanf("%d",&find);

    int low=0, high=n-1;
    int found=0;

    while (low<=high) {
        int mid=low+(high-low)/2;

        if (arr[mid]==find) {
            printf("Element found at position %d\n", mid + 1);
            found=1;
            break;
        }
        else if (find<arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
