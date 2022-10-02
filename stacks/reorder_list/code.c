/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct stack{
    int capacity;
    int top;
    struct ListNode** items;
};

struct stack* newStack(int cap){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->capacity = cap;
    st->top = -1;
    st->items = (struct ListNode**)malloc(sizeof(struct ListNode*) * cap);
    return st;
}

int size(struct stack *pt) {
    return pt->top + 1;
}

int isEmpty(struct stack *pt) {
    return pt->top == -1;
}

int isFull(struct stack *pt) {
    return pt->top == pt->capacity - 1;
}

void push(struct stack *pt, struct ListNode* x){
    if(!isFull(pt)){
        printf("Pushing: %d\n",x->val);
        pt->items[++pt->top] = x; 
    }else{
        printf("Stack overflow\n");
        return NULL;
    }
}

struct ListNode* pop(struct stack *pt){
    if(!isEmpty(pt)){
        printf("Popping: %d\n", pt->items[pt->top]->val);
        return pt->items[pt->top--];
    }else{
        printf("Stack empty\n");
        return NULL;
    }
}

void reorderList(struct ListNode* head){
    
    struct ListNode *iter = head;
    int listLength = 0;
    
    while(iter != NULL){
        iter = iter->next;
        listLength++;
    }
    
    struct stack* nStack = newStack(listLength);
    iter = head;
    
    while(iter != NULL){
        push(nStack, iter);
        iter = iter->next;
    }
    
    iter = head;
    
    while(iter != NULL){
        struct ListNode *next = iter->next;
        struct ListNode *end  = pop(nStack);
        iter->next = end;
        end->next = next;
        iter = next;
        
        if(iter != NULL && iter->next == end){
            iter->next = NULL;
            break;
        }
    }

    
}
