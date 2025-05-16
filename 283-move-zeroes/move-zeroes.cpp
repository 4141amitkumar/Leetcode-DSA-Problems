class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1) return;
        int x = 0;
        int y = 1;
        while(y<nums.size() && y<nums.size()){
            while(x<nums.size() && nums[x]!=0){
                x++;
                y=max(y,x+1);
            }
            while(y < nums.size() && nums[y]!=0){
                nums[x]=nums[y];
                nums[y]=0;
                x++;
                y++;
            }
            while(y<nums.size() && nums[y]==0)y++;
        }
        return;
    }
};