class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a0=0, a1=0, a2=n-1;
        while(a1<=a2){
            if(nums[a1]==2) {
                swap(nums[a1],nums[a2]);
                a2--;
            }
            else if(nums[a1]==1) a1++;
            else {
                swap(nums[a1],nums[a0]);
                a1++;
                a0++;
            }
        }
        return;
    }
};