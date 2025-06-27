class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxVal = INT_MIN;
        int rangeStart = 0, rangeEnd = INT_MAX;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            maxVal = max(maxVal, nums[i][0]);
        }
        while(true){
            pi x = pq.top();
            pq.pop();
            int minVal = x.first;
            int row = x.second.first;
            int col = x.second.second;

            if(maxVal-minVal<rangeEnd-rangeStart || (maxVal-minVal == rangeEnd-rangeStart  &&  minVal<rangeStart)){
                rangeStart = minVal;
                rangeEnd = maxVal;
            }
            if(col+1<nums[row].size()){
                int y = nums[row][col+1];
                pq.push({y,{row,col+1}});
                maxVal = max(maxVal,y);
            }
            else break;
        }
        return {rangeStart,rangeEnd};
    }
};