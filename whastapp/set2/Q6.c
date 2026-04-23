#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertEnd(struct node **head, int value) {
    struct node *newnode = createNode(value);
    struct node *temp;

    if(*head == NULL) {
        *head = newnode;
        return;
    }

    temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void display(struct node *head) {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

struct node* mergeLists(struct node *l1, struct node *l2) {
    struct node *result = NULL;
    struct node *temp = NULL;

    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->data <= l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }

    temp = result;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return result;
}

int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    struct node *merged = NULL;

    int n1, n2, value;

    printf("Enter number of nodes for first sorted list: ");
    scanf("%d", &n1);

    for(int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    printf("Enter number of nodes for second sorted list: ");
    scanf("%d", &n2);

    for(int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    merged = mergeLists(list1, list2);

    printf("Merged list:\n");
    display(merged);

    return 0;
}
