class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = nums.size();
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(pq.top()>nums[i]) continue;
            pq.pop();
            pq.push(nums[i]);
        }
        return pq.top();
    }
};