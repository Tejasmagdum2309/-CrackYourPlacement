class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<char> st1;
        stack<int> st2;
        int n = colors.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(st1.empty() || st1.top() != colors[i]){
                st1.push(colors[i]);
                st2.push(i);
            }
            else if(!st1.empty() && st1.top() == colors[i]){
                int inst1 = neededTime[st2.top()];

                if(inst1 <= neededTime[i]){
                      cnt+=inst1;
                      st2.pop();
                      st2.push(i);
                }
                else{
                        cnt+=neededTime[i];
                }
            }

           

            }
        return cnt;
        
    }
};