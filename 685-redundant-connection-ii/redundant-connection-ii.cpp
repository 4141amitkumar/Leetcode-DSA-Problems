class Solution {
public:
    // DFS se cycle check
    bool dfsCycle(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& rec) {
        vis[u] = 1;
        rec[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfsCycle(v, adj, vis, rec)) return true;
            } else if (rec[v]) {
                return true; // back edge -> cycle
            }
        }

        rec[u] = 0;
        return false;
    }

    bool hasCycleDFS(int n, vector<vector<int>>& edges, vector<int>& banned) {
        vector<vector<int>> adj(n+1);
        for (auto &e : edges) {
            if (e == banned) continue; // skip banned edge
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(n+1, 0), rec(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dfsCycle(i, adj, vis, rec)) return true;
        }
        return false;
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

        // Step 2: check cycle by skipping candidate edges
        if (!cand1.empty()) {
            if (!hasCycleDFS(n, edges, cand2)) return cand2;
            return cand1;
        }

        // Normal cycle case
        for (int i = n-1; i >= 0; i--) {
            if (hasCycleDFS(n, edges, edges[i]) == false) return edges[i];
        }
        return {};
    }
};
