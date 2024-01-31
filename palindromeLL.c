bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;  // An empty list or a list with one node is considered a palindrome
    }

    // Find the middle of the linked list using the slow and fast pointers
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    struct ListNode *prev = NULL;
    struct ListNode *temp;

    while (slow != NULL) {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Compare the reversed second half with the first half
    struct ListNode *left = head;
    struct ListNode *right = prev;

    while (right != NULL) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}
