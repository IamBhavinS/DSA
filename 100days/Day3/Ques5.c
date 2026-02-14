#include <stdio.h>

int main() {
    int n, i, k, count = 0, f = -1;
    int arr[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        count++;
        if(arr[i] == k) {
            f = i;
            break;
        }
    }

    if(f != -1) {
        printf("Found at index %d\n", f);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", count);

    return 0;
}