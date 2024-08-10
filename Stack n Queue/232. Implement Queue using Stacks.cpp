class MyQueue {
public:
     stack<int> f1;
        stack<int> f2;
        int front = -1;
    
    MyQueue() {
       
    }
    
    void push(int x) {
        if(f1.empty()){
            front = x;
        }
        f1.push(x);
    }
    
    int pop() {

        if(f1.empty()) return -1;
      

        while(!f1.empty()){
            f2.push(f1.top());
            f1.pop();
        }
        int x = f2.top();
        f2.pop();
        if(f2.empty()){front = -1;}
        else{
            front= f2.top();
        }
         
        while(!f2.empty()){
            f1.push(f2.top());
            f2.pop();
        }
        
        return x;

    }
    
    int peek() {
        if(empty()) return -1;
        return front;
    }
    
    bool empty() {
        return f1.empty();
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