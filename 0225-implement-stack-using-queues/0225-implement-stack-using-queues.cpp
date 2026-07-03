class MyStack {
public:
    queue<int> q1, q2;
    public:
        MyStack() {
            q1 = queue<int>();
            q2 = queue<int>();
        }

        void push(int x) {
            while(!q1.empty()) {        // Move all elements from q1 to q2
                q2.push(q1.front());    
                q1.pop();
            }
            q1.push(x);                  // Push the new element to q1
            while(!q2.empty()) {        // Move all elements back from q2 to q1 after adding the new element
                q1.push(q2.front());
                q2.pop();
            }
        }

        int pop() {
            if(q1.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            int top = q1.front();   // Store the top element before popping
            q1.pop();       // Pop the top element from the stack
            return top;     // Return the popped element
        }

        int top() {
            if(q1.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return q1.front();
        }

        bool empty() {
            return q1.empty();
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