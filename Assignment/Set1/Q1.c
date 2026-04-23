//Remove loop in Linked List

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

int removeCycle(struct Node *head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;
            return 1;
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

    printf("Enter position where cycle starts (0 for no cycle): ");
    scanf("%d", &pos);

    if (pos > 0) {
        temp = head;
        for (i = 1; i < pos; i++)
            temp = temp->next;

        prev->next = temp;
    }

    if (removeCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
