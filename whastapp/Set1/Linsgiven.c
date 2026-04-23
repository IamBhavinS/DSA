//write a program to insert  a node at the given position 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, value, i, pos, newValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &newValue);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newValue;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            printf("Invalid position\n");
            return 0;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
