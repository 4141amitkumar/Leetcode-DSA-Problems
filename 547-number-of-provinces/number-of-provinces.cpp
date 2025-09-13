class DSU{
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        if(rank[px]<rank[py]) parent[px]=py;
        else if(rank[px]>rank[py]) parent[py]=px;
        else{
            parent[py]=px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //using DSU
        int n = isConnected.size();
        DSU dsu(n);
        //step 1: union all directly connected cities
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    dsu.unite(i,j);
                }
            }
        }
        // step 2: count unique parents = number of provinces
        unordered_set<int> uniqueParents;
        for(int i=0;i<n;i++){
            uniqueParents.insert(dsu.find(i));
        }
        return uniqueParents.size();
    }
};