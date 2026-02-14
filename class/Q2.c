#include <stdio.h>

int main() {
int arr[100];
int n;

printf("Enter no.of elements:-");
scanf("%d",&n);

printf("Enter %d elements:-\n", n);
for (int i=0; i<n; i++) {
scanf("%d",&arr[i]);
}

printf("elements are:-\n");
for (int i=0; i<n; i++) {
printf("%d ",arr[i]);
    }
return 0;
}
