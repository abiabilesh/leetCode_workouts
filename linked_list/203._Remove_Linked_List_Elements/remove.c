/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* newHead = head;
    struct ListNode* iter = head;
    
    //Special handling for the head containing the value
    while(iter != NULL){
        if(iter->val == val){
            newHead = iter->next;
            free(iter);
            iter = newHead;
        }else{
            break;
        }
    }
    
    while(iter){
        if((iter->next) && (iter->next->val == val)){
            struct ListNode* temp = iter->next;
            
            //hooking the next's next
            iter->next = temp->next;
            
            //freeing the next node
            free(temp);
        }else{
            //incrementing the iter to the next to next node
            iter = iter->next;
        }
    }
    
    return newHead;
}
