class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int node = q.front(); q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j]==1 && !vis[j]){
                            vis[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};