class MinStack {
private:
    stack<int> st;
    stack<int> mini;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(mini.empty() || mini.top() >= val) {
            st.push(val);
            mini.push(val);
        } else {
            st.push(val);
        }    
    }
    
    void pop() {
        if(st.top() == mini.top()) {
            st.pop();
            mini.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
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