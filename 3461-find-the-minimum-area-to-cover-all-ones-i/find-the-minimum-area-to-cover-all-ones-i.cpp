class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int minr=m, minc=n, maxr=-1, maxc=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minr=min(minr,i);
                    minc=min(minc,j);
                    maxr=max(maxr,i);
                    maxc=max(maxc,j);
                }
            }
        }
        if(maxr==-1) return 0;
        return (maxr-minr+1)*(maxc-minc+1);
    }
};