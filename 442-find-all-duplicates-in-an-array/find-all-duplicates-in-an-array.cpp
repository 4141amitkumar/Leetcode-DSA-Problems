class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(index[nums[i]-1]==nums[i]) ans.push_back(nums[i]);
            index[nums[i]-1] = nums[i];
        }
        return ans;
    }
};