class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        if(nums[0]<=target)dp[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=target;t>=0;t--){
                if(nums[i]<=t)dp[t]=dp[t]||dp[t-nums[i]];
            }
        }
        return dp[target];
    }
};