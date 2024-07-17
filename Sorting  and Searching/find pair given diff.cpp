

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        
        // unordered_set<int> s;
        
        // for(int num : arr){
        //     if(s.find(num  - x) != s.end() || s.find(num  + x) != s.end()){
        //         return 1;
        //     }
        //     s.insert(num);
        // }
        // return -1;
        
        sort(arr.begin(),arr.end());
        
        int i = 0,j = 0;
        while(j<n){
            if(i!=j && (arr[j] - arr[i] == x)){
                return 1;
            } 
            else if((arr[j] - arr[i]) < x){
                j++;
            }
            else{
                i++;
            }
        }
        
        
        return -1;
    }
};


/