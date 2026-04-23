/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int i;

    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node *result = NULL, *temp = NULL;

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data <= l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }

    temp = result;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if (l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return result;
}

int main() {
    int n, m;
    struct node *list1, *list2, *merged, *temp;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list:\n");
    list1 = createList(n);

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list:\n");
    list2 = createList(m);

    merged = mergeLists(list1, list2);

    temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}
