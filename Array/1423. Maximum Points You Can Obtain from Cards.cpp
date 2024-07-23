class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int  n = cardPoints.size();
        int sum = 0;

        for(int i = 0;i<k;i++){
            sum+=cardPoints[i];
        }

        int curr = sum;
        int j = n-1;
        while(k != 0){
            
            curr -= cardPoints[k-1];
            curr += cardPoints[j--];

            sum = max(sum,curr);

            k--;
        }

        return sum;
    }
};