class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0, j = n-1;
        int level=0;
        int ans=0;

        while (i<j) {
            int k=min(height[i], height[j]);
            level=max(level, k);
            if (height[i]<=height[j]) {
                i++;
                ans+=max(0,level-height[i]);
            } else {
                j--;
                ans +=max(0,level-height[j]);
            }
        }
        return ans;
    }
};
