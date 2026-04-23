//Print Linked List elements

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

void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }

    printf("\n");
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

    printf("Linked list elements:\n");
    printList(head);

    return 0;
}
