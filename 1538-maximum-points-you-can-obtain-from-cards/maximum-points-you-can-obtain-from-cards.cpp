class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n = cardPoints.size();
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
        }
        int window=n-k;
        if(window==0) return sum;
        int curr=0;
        for(int i=0;i<window;i++){
            curr+=cardPoints[i];
        }
        int minsum=curr;
        for(int i=window;i<n;i++){
            curr+=cardPoints[i]-cardPoints[i-window];
            minsum=min(minsum,curr);
        }
        return sum-minsum;
    }
};