class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];

        int ans = INT_MAX;
        for(int coin: coins){
            if(amount-coin>=0){
                int res = helper(coins, amount-coin, dp);
                if(res!=INT_MAX){
                ans=min(ans,res+1);
            }
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = helper(coins, amount, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};