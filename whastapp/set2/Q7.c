#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    struct node *newnode, *temp;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int isPalindrome() {
    struct node *slow = head;
    struct node *fast = head;
    struct node *secondHalf;
    struct node *copySecond;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    secondHalf = reverse(slow);
    copySecond = secondHalf;

    struct node *firstHalf = head;

    while(secondHalf != NULL) {
        if(firstHalf->data != secondHalf->data)
            return 0;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverse(copySecond);

    return 1;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    if(isPalindrome())
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
