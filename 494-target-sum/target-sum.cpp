class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(abs(target)>sum || (sum+target)%2!=0) return 0;
        int s1=(sum+target)/2;
        vector<int> dp(s1+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int t=s1;t>=nums[i];t--){
                dp[t]+=dp[t-nums[i]];
            }
        }
        return dp[s1];
    }
};