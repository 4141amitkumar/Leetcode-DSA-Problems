class DSU{
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find( int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x,int y){
        int px = find(x);
        int py = find(y);
        if(px==py) return false;
        if(rank[px]<rank[py]) parent[px]=py;
        else if(rank[px]>rank[py]) parent[py]=px;
        else {
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            if(!dsu.unite(u,v)){
                //cycle detected
                return edge;
            }
        }
        return {};
    }
};