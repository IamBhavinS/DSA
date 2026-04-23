//Find length of Loop

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

int loopLength(struct Node *head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            fast = fast->next;

            while (fast != slow) {
                count++;
                fast = fast->next;
            }

            return count;
        }
    }

    return 0;
}

int main() {
    int n, pos, i, x;
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

    printf("Enter position where loop starts (0 for no loop): ");
    scanf("%d", &pos);

    if (pos > 0) {
        temp = head;
        for (i = 1; i < pos; i++)
            temp = temp->next;

        prev->next = temp;
    }

    int length = loopLength(head);

    if (length > 0)
        printf("Loop length = %d\n", length);
    else
        printf("No loop found\n");

    return 0;
}
