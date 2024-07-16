class Solution {
public:
    char revsym(char c){
        if(c == ')'){
            return '(';
        }
        else if (c == '}'){
            return '{';
        }
        return '[';
    }

    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
           if(c == '(' || c == '{' || c == '['){
             st.push(c);
           }
           else{
             if(st.empty()) return false;

             if(st.top() == revsym(c)){
                st.pop();
             }
             else{
                return false;
             }
           }
        }

        if(st.empty()) return true;
        return false;
    }
};