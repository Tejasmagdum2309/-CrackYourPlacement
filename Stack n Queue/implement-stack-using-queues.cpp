class MyStack {
public:
    queue<int> q;
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
          if(empty()) return -1;
          int ret = 0;
          while(!q.empty()){
              int x = q.front();
              q.pop();
              if(q.empty()){
                  ret = x;
                  break;
              }
              q1.push(x);
          }

          while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
          }


          return ret;
    }
    
    int top() {
        if(empty()) return -1;
        return q.back();
    }
    
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