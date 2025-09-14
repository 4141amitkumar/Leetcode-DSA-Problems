class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py) return false; //cycle
        parent[py]=px;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);
        vector<int> cand1, cand2;
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            if(parent[v]==0) parent[v]=u;
            else{
                // node v already has a parent
                cand1={parent[v],v}; //first edge
                cand2={u,v}; //second edge
                edge[1]=0;  // invalidate second edge temporarily
            }
        }
        //DSU to detect cycle
        DSU dsu(n);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            if(v==0) continue; // skip invalid edge
            if(!dsu.unite(u,v)){
                //cycle found
                if(cand1.empty()) return edge;
                return cand1;
            }
        }
        return cand2;
    }
};