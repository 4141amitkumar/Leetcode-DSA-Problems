class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_set<int> s;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0) maxi=max(maxi,nums[i]);
            if(nums[i]>0) s.insert(nums[i]);
        }
        int sum=0;
        for(int x:s){
            sum+=x;
        }
        if(sum==0) return maxi;
        else return sum;
    }
};