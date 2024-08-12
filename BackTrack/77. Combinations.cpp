class Solution {
public:
vector<vector<int>> ans;

    void rec(vector<int>& temp,int num,int k,int n){
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = num;i<=n;i++){
            temp.push_back(i);
            rec(temp,i+1,k-1,n);
             temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
         vector<int> temp;
         rec(temp,1,k,n);
         return ans;
    }
};