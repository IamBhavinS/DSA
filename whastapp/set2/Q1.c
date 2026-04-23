//reverse singly linked list

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

void display() {
    struct node *temp = head;
    
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

void reverseList() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    
    while(current != NULL) {
        next = current->next;   // save next node
        current->next = prev;   // reverse pointer
        
        prev = current;         // move prev forward
        current = next;         // move current forward
    }
    
    head = prev; // new head
}

int main() {
    int n;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    createList(n);
    
    printf("\nOriginal List:\n");
    display();
    
    reverseList();
    
    printf("\nReversed List:\n");
    display();
    
    return 0;
}
