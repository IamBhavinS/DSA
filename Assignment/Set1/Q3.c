//Delete a Node in Single Linked

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

struct Node* deleteAtPosition(struct Node* head, int x) {
    struct Node *temp = head, *prev = NULL;
    int i = 1;

    if (x == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp != NULL && i < x) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }

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
    int n, x, i, val;
    struct Node *head = NULL, *prev = NULL, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = newNode(val);

        if (head == NULL)
            head = temp;
        else
            prev->next = temp;

        prev = temp;
    }

    printf("Enter position to delete: ");
    scanf("%d", &x);

    head = deleteAtPosition(head, x);

    printf("Linked list after deletion:\n");
    printList(head);

    return 0;
}
