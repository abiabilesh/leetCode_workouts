
struct stack{
    int capacity;
    int top;
    char **items;
};

struct stack* newStack(int cap){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->capacity = cap;
    st->top = -1;
    
    st->items =  (char**)malloc(sizeof(char*) * cap);
    for(int i = 0; i < cap; i++){
        st->items[i] = (char*)malloc(sizeof(char*) * 500);
    }
    
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

int push(struct stack *pt, char *x){
    if(!isFull(pt)){
        printf("Pushing: %s\n", x);
        strcpy(pt->items[++pt->top], x); 
    }else{
        printf("Stack overflow\n");
        return -1;
    }
    
    return 0;
}

char* pop(struct stack *pt){
    if(!isEmpty(pt)){
        printf("Popping: %s\n", pt->items[pt->top]);
        return pt->items[pt->top--];
    }else{
        printf("Stack empty\n");
        return NULL;
    }
}



char * simplifyPath(char * path){
    struct stack *spStack = newStack(strlen(path));
    char *temp = (char*)malloc(sizeof(char) * (strlen(path)+1));
    strcpy(temp,"/");
    
    if(strlen(path) == 1)
        return temp;
    
    //printf("check 1");
    for(char *dlm = strtok(path, "/"); dlm != NULL; dlm = strtok(NULL, "/")){
        //printf("%s\n", dlm);
        if(!strcmp(dlm, "..")){
            pop(spStack);
        }else if(!strcmp(dlm, ".")){
            printf("Doing nothing\n");
            //do nothing
        }else{
            push(spStack, dlm);
        }
    }
    
    for(int i = 0; i <= spStack->top; i++){
        strcat(temp, spStack->items[i]);
        if(i != spStack->top)
            strcat(temp,"/");
    }
    
    return temp;
}
