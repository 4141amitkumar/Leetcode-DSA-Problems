class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& graph, vector<int>& vis){
        if(src==target) return true;
        vis[src]=1;
        for(int nbr:graph[src]){
            if(!vis[nbr]){
                if(dfs(nbr,target,graph,vis)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1); //1-indexed
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            vector<int> vis(n+1,0);
            if(!graph[u].empty() && !graph[v].empty()){
                if(dfs(u,v,graph,vis)) return edge;
            }
            //add edge in graph
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};