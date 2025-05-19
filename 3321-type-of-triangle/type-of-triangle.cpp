class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]>nums[2] && nums[1]+nums[2]>nums[0] && nums[0]+nums[2]>nums[1]){
            unordered_set<int> unique;
            for(int i=0;i<3;i++){
                unique.insert(nums[i]);
            }
            if(unique.size()==1) return "equilateral";
            else if(unique.size()==2) return "isosceles";
            else return "scalene";
        }
        else return "none";
    }
};