/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* nextNode = node->next;
    int temp = node->val;
    node->val = nextNode->val;
    node->next = nextNode->next;
}
