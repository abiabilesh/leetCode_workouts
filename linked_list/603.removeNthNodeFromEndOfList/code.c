/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int length = 0;
    int indexToRemove = 0;
    struct ListNode* newHead = head;
    
    for(struct ListNode* i = head; i != NULL; i = i->next){
        length++;
    }
    
    printf("The Length of the node is %d\n", length);
    printf("The index that I have to remove is %d\n", length - n);
    
    indexToRemove = length - n;
    
    if(indexToRemove == 0){
        newHead = head->next;
        free(head);
        return newHead;
    }
    
    struct ListNode* temp = head;
    int iter = 0;
    while(temp){
        if(iter == (indexToRemove - 1)){
            struct ListNode* t = temp->next;
            temp->next = t->next;
            free(t);
        }else{
            temp = temp->next;
        }
        iter++;
    }
        
    return head;
}
