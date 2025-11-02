class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long largest=LONG_MIN, second=LONG_MIN, third=LONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                third=second;
                second=largest;
                largest=nums[i];
            }
            else if(nums[i]<largest && nums[i]>second){
                third=second;
                second=nums[i];
            }
            else if(nums[i]<largest && nums[i]<second && nums[i]>third){
                third=nums[i];
            }
        }
        if(third==LONG_MIN) return (int)largest;
        return (int)third;
    }
};