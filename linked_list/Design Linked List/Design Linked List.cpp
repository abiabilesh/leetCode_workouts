class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    //Constructor
    Node(int val) : val{val}, next{NULL}, prev{NULL} {}
};

class MyLinkedList {
    Node *head;
    int lsize;
public:
    MyLinkedList() {
        head = NULL;
        lsize = 0;
    }
    
    int get(int index) {
        if(lsize == 0){
            printf("The list is empty");
            return -1;
        }else{
            if(index >= lsize){
                printf("Out of index\n");
                return -1;
            }else{
                int iter = 0;
                Node *indexTmp = head;
                while(iter != index){
                    iter++;
                    indexTmp = indexTmp->next;
                }
                
                return indexTmp->val;
            }
        }
    }
    
    void addAtHead(int val) {
        if(lsize == 0){
            printf("The list is empty and adding a new head with val %d\n", val);
            head = new Node(val);
        }else{
            printf("Added a new node at head with val %d\n", val);
            Node *tmp = new Node(val);
            tmp->next = head;
            tmp->prev = NULL;
            
            head->prev = tmp;
            head = tmp;
        }
        
        lsize++;
    }
    
    void addAtTail(int val) {
        if(lsize == 0){
            head = new Node(val);
        }else{
            Node* tmp = head;
            int iter = 0;
            while(tmp->next != NULL){
                iter++;
                tmp = tmp->next;
            }
            
            printf("Adding the value %d at the index %d\n", val, iter+1);
            Node *newTmp = new Node(val);
            newTmp->next = NULL;
            newTmp->prev = tmp;
            
            tmp->next = newTmp;
        }
        
        lsize++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > lsize){
            return;
        }
        if(lsize == 0){
            printf("The list is empty and adding a node with val %d\n", val);
            head = new Node(val);
        }else if(index == 0){
            addAtHead(val);
        }else{
            if(index > lsize){
                printf("Index %d out of range as the list size is %d\n", index, lsize);
                return;
            }else{
                int iter = 0;
                Node *indexTmp = head;
                
                if(index != lsize){
                    while(iter != index){
                        iter++;
                        indexTmp = indexTmp->next;
                    }
                    
                    printf("Added the val %d at index %d\n", val, index);
                    Node *newTmp = new Node(val);
                    Node *prev_indexTmp = indexTmp->prev;
                    if(prev_indexTmp != NULL){
                        prev_indexTmp->next = newTmp;
                    }
                    newTmp->next = indexTmp;
                    newTmp->prev = indexTmp->prev;
                    indexTmp->prev = newTmp;
                }else if(index == lsize){
                    while(iter != (index - 1)){
                        iter++;
                        indexTmp = indexTmp->next;
                    }
                    printf("Added the val %d at index %d\n", val, index);
                    
                    Node *newTmp = new Node(val);
                    indexTmp->next = newTmp;
                    newTmp->prev = indexTmp;
                }
            }
        }
        
        lsize++;
    }
    
    void deleteAtIndex(int index) {
        if(lsize == 0){
            printf("The list is empty");
            return;
        }else{
            if(index >= lsize){
                printf("Index out of range\n");
                return;
            }else{
                int iter = 0;
                Node *indexTmp = head;
                while(iter != index){
                    iter++;
                    indexTmp = indexTmp->next;
                }
                
                printf("Deleting the val %d at index %d\n", indexTmp->val, iter);
                Node *prevTmp = indexTmp->prev;
                Node *nextTmp = indexTmp->next;
                if(nextTmp != NULL)
                    nextTmp->prev = prevTmp;
                if(prevTmp != NULL){
                    prevTmp->next = indexTmp->next;
                    delete(indexTmp);
                }else{
                    head = head->next;
                    delete(indexTmp);
                }
                lsize--;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */