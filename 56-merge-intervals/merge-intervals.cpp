bool cmp(vector<int>& a, vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int i=0;
        while(i<intervals.size()){
            int a=intervals[i][0],b=intervals[i][1];
            int j=i+1;
            while(j<intervals.size() && intervals[j][0]<=b){
                b=max(b,intervals[j][1]);
                j++;
            }
            i=j;
            ans.push_back({a,b});
        }
        return ans;
    }
};