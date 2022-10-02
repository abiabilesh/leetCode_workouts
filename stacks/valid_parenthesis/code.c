struct stack{
    int capacity;
    int top;
    int *items;
};

struct stack* newStack(int cap){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->capacity = cap;
    st->top = -1;
    st->items = (int*)malloc(sizeof(int) * cap);
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

void push(struct stack *pt, int x){
    if(!isFull(pt)){
        pt->items[++pt->top] = x; 
    }else{
        printf("Stack overflow\n");
        return -1;
    }
}

int pop(struct stack *pt){
    if(!isEmpty(pt)){
        printf("%d\n", pt->items[pt->top]);
        return pt->items[pt->top--];
    }else{
        printf("Stack empty\n");
        return -1;
    }
}

bool isValid(char * s){
    int slen = strlen(s);
    
    struct stack *pStack = newStack(slen);
    
    for(int i = 0; i < slen; i++){
        if(s[i] == '('){
            push(pStack, 0);
        }else if(s[i] == ')'){
            int ret = pop(pStack);
            if(ret != 0 || ret == -1)
                return false;
        }else if(s[i] == '{'){
            push(pStack, 1);
        }else if(s[i] == '}'){
            int ret = pop(pStack);
            if(ret != 1 || ret == -1)
                return false;
        }else if(s[i] == '['){
            push(pStack, 2);
        }else if(s[i] == ']'){
            int ret = pop(pStack);
            if(ret != 2 || ret == -1)
                return false;
        }
    }
    
    if(!isEmpty(pStack))
        return false;
    
    return true;
}
