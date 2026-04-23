//Linked List Length Even or Odd

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int listLength(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, i, x;
    struct Node *head = NULL, *prev = NULL, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        temp = newNode(x);

        if (head == NULL)
            head = temp;
        else
            prev->next = temp;

        prev = temp;
    }

    int len = listLength(head);

    if (len % 2 == 0)
        printf("Even length\n");
    else
        printf("Odd length\n");

    return 0;
}
