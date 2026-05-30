class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid[0].size();
        int n = grid.size();

        if(i >= n || i < 0 || j < 0 || j >= m || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = 1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};
