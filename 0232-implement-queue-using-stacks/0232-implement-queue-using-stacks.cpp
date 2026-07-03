class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x) {
            while(!s1.empty()) {        // Move all elements from s1 to s2
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);                  // Push the new element to s1
            while(!s2.empty()) {        // Move all elements back from s2 to s1 after adding the new element
                s1.push(s2.top());
                s2.pop();
            }
        }

        int pop() {     // Remove the front element from the queue
            int front = s1.top();       // Store the front element before popping
            s1.pop();           // Pop the front element from the queue
            return front;       // Return the popped element
        }

        int peek() {
            return s1.top();        // Return the front element of the queue
        }

        bool empty() {
            return s1.empty();      // Check if the queue is empty
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