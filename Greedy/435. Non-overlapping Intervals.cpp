class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int pre_end = INT_MIN;
        int cnt = 0;
        for(auto interval : intervals){
           if(pre_end > interval[0]){
            cnt++;
              continue;
           }
           else{
              pre_end = interval[1];
           }
        }

        return cnt;
    }
};