class MyStack {
public:
   queue<int>q,q1;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q.empty())
            return -1;
        while(q.size()>1)
        {
            q1.push(q.front());
            q.pop();
        }
        int v=q.front();
        q.pop();
        while(!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }
        return v;
    }
    
    /** Get the top element. */
    int top() {
        if(q.empty())
            return -1;
        while(q.size()>1)
        {
            q1.push(q.front());
            q.pop();
        }
        int v=q.front();
        q.pop();
        q1.push(v);
        while(!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }
        return v;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */