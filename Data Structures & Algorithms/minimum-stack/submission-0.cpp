class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() or minst.top() >= val) minst.push(val);
    }
    
    void pop() {
        if(minst.top()==st.top()) minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {  
        return minst.top();
    }
};
