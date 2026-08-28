class MinStack {
public:
    stack<int> myStack;
    stack<int> minStack;

    MinStack() {
    }
    
    void push(int val) {
        myStack.push(val);
        if(minStack.empty()){
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
        
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
