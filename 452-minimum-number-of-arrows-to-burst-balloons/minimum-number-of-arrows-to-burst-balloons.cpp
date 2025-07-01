bool cmp(vector<int>& a, vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int i=0,j=1;
        int count=0;
        while(i<points.size()){
            int a = points[i][1];
            while(j<points.size() && points[j][0]<=a){
                a=min(a,points[j][1]);
                count++;
                j++;
            }
            i=j;
            j++;
        }
        return points.size()-count;
    }
};