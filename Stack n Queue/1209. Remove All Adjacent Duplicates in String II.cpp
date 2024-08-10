class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st1;
        stack<int> st2;

        for(char c : s){
            if(st2.empty()){
                st1.push(c);
                st2.push(1);continue;
            }

            if(st1.top() == c){
                st1.push(c);
                st2.push((st2.top())+1);
            }
            else{
                st1.push(c);
                st2.push(1);
            }
            
            if(st2.top() == k){
                int n = k;
                while(n){
                       st1.pop();
                       st2.pop();
                       n--;
                }
            }
            
        }

        string s1 = "";

        while(!st1.empty()){
            s1.push_back(st1.top());
            st1.pop();
        }

        reverse(s1.begin(),s1.end());
        return s1;


    }
};