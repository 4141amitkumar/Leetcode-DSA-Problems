bool cmp(vector<int>& a, vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        int count=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int i=0,j=1;
        while(j<intervals.size()){
            int a = intervals[i][1];
            while(j<intervals.size() && intervals[j][0]<a){
                a=min(a,intervals[j][1]);
                j++;
                count++;
            }
            i=j;
            j++;
        }
        return count;
    }
};