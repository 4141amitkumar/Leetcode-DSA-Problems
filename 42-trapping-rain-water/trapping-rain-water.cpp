class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> next_greater(n,-1);
        vector<int> prev_greater(n,-1);
        int prev_max = height[0];
        int next_max = height[n-1];
        for(int i=1;i<n;i++){
            prev_greater[i]=prev_max;
            prev_max = max(prev_max, height[i]);
        }
        for(int i=n-2;i>=0;i--){
            next_greater[i]=next_max;
            next_max = max(next_max, height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int k = min(prev_greater[i],next_greater[i]);
            if(k>height[i]) ans+=(k-height[i]);
        }
        return ans;
    }
};