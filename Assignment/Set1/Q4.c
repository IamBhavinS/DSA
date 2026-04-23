//Linked List Insertion

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

struct Node* insertEnd(struct Node* head, int val) {
    struct Node* temp = newNode(val);

    if (head == NULL)
        return temp;

    struct Node* cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    return head;
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
    struct Node *head = NULL;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Linked list:\n");
    printList(head);

    return 0;
}
