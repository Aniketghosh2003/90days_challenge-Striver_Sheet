class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    public:
Queue() {
        
    }

    void enQueue(int val) {
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if(isEmpty()) return -1;

        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() {
        if(isEmpty()) return -1;

        int ans = s1.top();
        return ans;
    }

    bool isEmpty() {
        if(s1.empty()) return true;
        else
         return false;

    }

};