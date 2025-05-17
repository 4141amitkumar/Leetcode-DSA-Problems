class Solution {
public:
    void sortColors(vector<int>& nums) {
        int noz=0,noo=0,nott=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) noz++;
            if(nums[i]==1) noo++;
            if(nums[i]==2) nott++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<noz) nums[i]=0;
            else if(i>=noz && i<noz+noo) nums[i]=1;
            else nums[i]=2;
        }
        return;
    }
};