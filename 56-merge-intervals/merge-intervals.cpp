bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
//method 2
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        ans.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int> curr = intervals[i];
            if(curr[1]>=ans[ans.size()-1][0]){
                ans[ans.size()-1][0] = min(ans[ans.size()-1][0],curr[0]);
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],curr[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};