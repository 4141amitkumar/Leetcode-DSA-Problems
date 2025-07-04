class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            int x = pq.top();
            pq.pop();
            pq.push(x*-1);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};