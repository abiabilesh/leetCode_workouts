/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode prev = {-1, NULL};
    struct ListNode *iter1 = list1;
    struct ListNode *iter2 = list2;
    struct ListNode *iterPrev = &prev;
    
    if(list1 && !list2){
        prev.next = list1;
    }else if(!list1 && list2){
        prev.next = list2;
    }
    
    for(; iter1 != NULL && iter2 != NULL; ){
        if(iter1->val <= iter2->val){
            iterPrev->next = iter1;
            iter1 = iter1->next;
            iterPrev = iterPrev->next;
            if(iter1 == NULL){
                iterPrev->next = iter2;
            }
        }else{
            iterPrev->next = iter2;
            iter2 = iter2->next;
            iterPrev = iterPrev->next;
            if(iter2 == NULL){
                iterPrev->next = iter1;
            }
        }
    }
    
    return prev.next;
    
}
