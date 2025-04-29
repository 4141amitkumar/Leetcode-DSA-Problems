class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, nums[i]);
        }
        int start=0,end=0,count=0;
        long long ans=0;
        while(end<n){
            if(nums[end]==maxi) count++;
            if(k>count) end++;
            while(count>=k){
                ans+=(n-end);
                if(nums[start]==maxi) {
                    count--;
                    end++;
                }
                start++;
            }
        }
        return ans;
    }
};