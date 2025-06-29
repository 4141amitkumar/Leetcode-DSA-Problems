class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0,j=n-1;
        long long sum=0;
        sort(nums.begin(), nums.end());
        vector<int> pow2(n+1,1);
        for (int i=1; i<=n; i++) {
            pow2[i] = (2LL*pow2[i-1])%1000000007;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target) {
                sum=(sum+pow2[j-i])%1000000007;
                i++;
            }
            else j--;
        }
        return (int)sum;
    }
};