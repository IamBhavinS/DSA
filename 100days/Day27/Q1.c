#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

int length(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* intersection(struct Node* h1, struct Node* h2) {
    int l1 = length(h1), l2 = length(h2);
    int diff = abs(l1 - l2);

    if (l1 > l2)
        while (diff--) h1 = h1->next;
    else
        while (diff--) h2 = h2->next;

    while (h1 && h2) {
        if (h1 == h2) return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

int main() {
    int n, m, x;

    scanf("%d", &n);
    struct Node *h1 = NULL, *t1 = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* node = newNode(x);
        if (!h1) h1 = t1 = node;
        else {
            t1->next = node;
            t1 = node;
        }
    }

    scanf("%d", &m);
    struct Node *h2 = NULL, *t2 = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* node = newNode(x);
        if (!h2) h2 = t2 = node;
        else {
            t2->next = node;
            t2 = node;
        }
    }

    int pos;
    scanf("%d", &pos);

    struct Node* ptr = h1;
    for (int i = 1; i < pos && ptr; i++)
        ptr = ptr->next;

    if (ptr) t2->next = ptr;

    struct Node* ans = intersection(h1, h2);

    if (ans) printf("%d\n", ans->data);
    else printf("No Intersection\n");

    return 0;
}
