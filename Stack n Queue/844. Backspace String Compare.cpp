class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        int l1 = s.length(); int l2 = t.size();
        int i = 0;
        while(i < l1 || i < l2){
             if(i < l1){
                if(s[i] == '#' && !st1.empty()){
                    st1.pop();
                }

                if(s[i] != '#'){
                      st1.push(s[i]);
                }
              
             }

             if(i < l2){
                 if(t[i] == '#' && !st2.empty()){
                    st2.pop();
                }

                if(t[i] != '#'){
                      st2.push(t[i]);
                }
              
             }
             i++;
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop(); st2.pop();
        }

        if(!st1.empty() || !st2.empty()){
           return false;
        }
        return true;
    }
};