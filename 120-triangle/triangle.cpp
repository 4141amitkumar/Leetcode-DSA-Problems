class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp=triangle[n-1];
        for(int i=1;i<n;i++){
            vector<int> newdp(n-i,0);
            for(int j=0;j<n-i;j++){
                newdp[j]=triangle[n-i-1][j]+min(dp[j],dp[j+1]);
            }
            dp=newdp;
        }
        return dp[0];
    }
};