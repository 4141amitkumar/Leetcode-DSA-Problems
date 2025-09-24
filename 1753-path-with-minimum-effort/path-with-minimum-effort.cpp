class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        effort[0][0]=0;
        vector<vector<int>> direction={{-1,0},{1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int d=curr[0], x=curr[1], y=curr[2];
            if(x==m-1 && y==n-1) return d;
            for(auto dir: direction){
                int nx=x+dir[0], ny=y+dir[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int newEffort=max(d,abs(heights[x][y]-heights[nx][ny]));
                    if(newEffort<effort[nx][ny]){
                        effort[nx][ny]=newEffort;
                        pq.push({newEffort,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
};