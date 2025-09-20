class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int c, int color){
        int n=image.size(), m=image[0].size();
        if(sr<0 || sc<0 || sr>=n || sc>=m || image[sr][sc]!=c) return;
        image[sr][sc]=color;
        dfs(image, sr-1, sc, c, color);
        dfs(image, sr+1, sc, c, color);
        dfs(image, sr, sc-1, c, color);
        dfs(image, sr, sc+1, c, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c=image[sr][sc];
        if(c==color) return image;
        dfs(image, sr, sc, c, color);
        return image;
    }
};