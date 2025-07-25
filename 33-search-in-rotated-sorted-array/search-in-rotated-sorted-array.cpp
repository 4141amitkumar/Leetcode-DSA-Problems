class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0, hi=n-1,mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if(nums[lo]<=nums[mid]){  //means left part is sorted
                if(nums[lo]<=target && nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
            else{   //right part is sorted
                if(nums[mid]<target && nums[hi]>=target) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};