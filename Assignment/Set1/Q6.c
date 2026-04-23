// Check if linked list is circular

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int isCircular(struct Node* head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

int main()
{
    int n, i, x, pos;
    struct Node *head = NULL, *prev = NULL, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);

        temp = newNode(x);

        if (head == NULL)
            head = temp;
        else
            prev->next = temp;

        prev = temp;
    }

    printf("Enter position to make circular (0 for no circle): ");
    scanf("%d", &pos);

    if (pos > 0 && pos <= n)
    {
        temp = head;

        for (i = 1; i < pos; i++)
            temp = temp->next;

        prev->next = temp;
    }

    if (isCircular(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
