class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<long long>& dp){
        if(amount==0) return 0;
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0) dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1, INT_MAX);
        int ans = helper(coins, amount, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};