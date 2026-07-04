class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>temp;

        int min1 = st.top();
        while(!st.empty()) {
            min1 = min(min1, st.top());
            temp.push(st.top());
            st.pop();
        }

        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return min1;
    }
};
