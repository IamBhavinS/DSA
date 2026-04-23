//program to find the intersection of two sorted singly linked lists and print the common elements.

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

struct Node* createList(int n) {
    struct Node *head = NULL, *prev = NULL, *temp;
    int i, x;

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = newNode(x);

        if(head == NULL)
            head = temp;
        else
            prev->next = temp;

        prev = temp;
    }

    return head;
}

void intersection(struct Node* h1, struct Node* h2) {
    while(h1 != NULL && h2 != NULL) {
        if(h1->data == h2->data) {
            printf("%d ", h1->data);
            h1 = h1->next;
            h2 = h2->next;
        }
        else if(h1->data < h2->data)
            h1 = h1->next;
        else
            h2 = h2->next;
    }
}

int main() {
    int n1, n2;
    struct Node *head1, *head2;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    printf("Enter elements of first sorted list:\n");
    head1 = createList(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    printf("Enter elements of second sorted list:\n");
    head2 = createList(n2);

    printf("Intersection elements:\n");
    intersection(head1, head2);

    return 0;
}
