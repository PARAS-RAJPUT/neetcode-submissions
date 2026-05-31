class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>&adj, vector<bool>&visited) {
        visited[u] = true;

        for(auto &v : adj[u]) {
            if(!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj(n);
        vector<bool>visited(n, 0);

        for(auto &e : edges) {
            int a = e[0];
            int b = e[1];

            adj[b].push_back(a);
            adj[a].push_back(b);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adj,visited);
                ans++;
            }
        }
        return ans;
    }
};
