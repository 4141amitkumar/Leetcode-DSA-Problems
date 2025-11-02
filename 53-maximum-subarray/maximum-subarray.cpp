class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0], maxsum=nums[0];
        if (nums.size()==0) return 0;
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i], curr+nums[i]);
            maxsum=max(maxsum, curr);
        }
        return maxsum;
    }
};