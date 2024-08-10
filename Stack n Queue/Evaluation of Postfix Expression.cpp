//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int chk(char c,int n1,int n2){
        if(c == '-'){
            return n1 - n2;
        }
        else if(c == '+'){
            return  n1 + n2;
        }
        else if(c == '/'){
            return n1 / n2;
        }
        
        return n1 * n2;
    }
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        
        for(int i = 0;i<S.length();i++){
            if('0' <= S[i] && S[i] <= '9'){
                st.push((S[i] - '0'));
            }
            else{
                int num2,num1;
                
                num2 = st.top();st.pop();
                num1 = st.top(); st.pop();
                
                st.push(chk(S[i],num1,num2));
            }
        }
        
        return int(st.top());
        
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends