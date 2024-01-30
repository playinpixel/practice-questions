#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse a linked list iteratively
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    while (cur != NULL) {
        struct ListNode* forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }

    return prev; // 'prev' now points to the new head of the reversed list
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List: ");
    printList(head);

    // Reverse the list iteratively
    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    // Free the memory allocated for the nodes
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

