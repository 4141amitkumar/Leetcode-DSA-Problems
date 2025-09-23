class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i] && isConnected[node][i]==1) dfs(i,isConnected, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};