class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int width = n-1;
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            ans=max(ans,min(height[i],height[j])*width);
            if(height[i]<=height[j])i++;
            else j--;
            width--;
        }
        return ans;
    }
};