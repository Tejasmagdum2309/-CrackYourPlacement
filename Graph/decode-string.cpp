class Solution {
public:
    string decodeString(string A) {
        stack<int> no;
        stack<string> s;

        string ans = "";

        for(int i = 0;i<A.length();i++){
            if(isdigit(A[i])){
                string n = "";
                while(isdigit(A[i])){
                    n += A[i]; i++;
                }
                i--;
                no.push(stoi(n));
            }
            else if(A[i] == '['){
                s.push(ans);
                ans = "";
            }
            else if(A[i] == ']'){
                string temp = s.top();
                s.pop();

                int number = no.top();
                no.pop();

                for(int j =0;j<number;j++){
                      temp+=ans;
                }
                ans = temp;
            }
            else{
                ans+=A[i];
            }
        }

        return ans;
    }
};