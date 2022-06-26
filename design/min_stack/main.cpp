class MinStack {
    vector<int> mStack;
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        mStack.push_back(val);    
    }
    
    void pop() {
        mStack.pop_back();
    }
    
    int top() {
        return mStack.back();
    }
    
    int getMin() {
        return *min_element(mStack.begin(), mStack.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */