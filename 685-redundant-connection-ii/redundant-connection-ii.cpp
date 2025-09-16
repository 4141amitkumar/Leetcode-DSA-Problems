class Solution {
public:
    bool hasCycleBFS(int n, vector<vector<int>>& edges, vector<int>& banned) {
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1, 0);

        for (auto &e : edges) {
            if (e == banned) continue; 
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);

        int cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cnt++;
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return cnt != n; // agar sab node visit nahi hue -> cycle hai
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> cand1, cand2;

        // Step 1: detect node with two parents
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) parent[v] = u;
            else {
                cand1 = {parent[v], v};
                cand2 = e;
                break;
            }
        }

        // Step 2: check cycle using BFS
        if (!cand1.empty()) {
            if (!hasCycleBFS(n, edges, cand2)) return cand2;
            return cand1;
        }

        for (int i = n-1; i >= 0; i--) {
            if (!hasCycleBFS(n, edges, edges[i])) return edges[i];
        }
        return {};
    }
};
