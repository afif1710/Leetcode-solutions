class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        shift();
        int tmp = st2.top();
        st2.pop();
        return tmp;
    }
    
    int peek() {
        shift();              // in case we have inputs which pushes values and then peeks instead of pop
        return st2.top();
        
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }

private:
    void shift(){                        //Shifts all values from st1 and pushes into st2 and pops from st1 as well
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */