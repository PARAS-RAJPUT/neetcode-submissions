class Solution {
public:
    bool dfs(int u, unordered_map<int, vector<int>>&adj, vector<bool>&visited, vector<bool>&inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for(auto &v : adj[u]) {
            if(!visited[v] && dfs(v, adj, visited, inRecursion)) {
                return true;
            }
            else if(inRecursion[v] == true) {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<bool>visited(numCourses, false);
        vector<bool>inRecursion(numCourses, false);

        for(auto &vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && dfs(i, adj, visited, inRecursion)) {
                return false;
            }
        }

        return true;

    }
};
