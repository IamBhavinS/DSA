#include <stdio.h>

int main() {
int arr[100];
int n, value;

printf("no.of elements:-");
scanf("%d",&n);

printf("Enter %d elements:-\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("Enter the no. insert at beginning:-");
scanf("%d", &value);

for (int i=n; i>0; i--) {
arr[i] = arr[i-1];
}

arr[0] = value;
n++;

printf("Array after insertion:\n");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
return 0;
}
