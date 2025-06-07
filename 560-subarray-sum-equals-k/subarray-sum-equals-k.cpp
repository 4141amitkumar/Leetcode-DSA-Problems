class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,start=0;
        int count=0;
        for(int i=start;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) count++;
            }
            start++;
            sum=0;
        }
        return count;
    }
};