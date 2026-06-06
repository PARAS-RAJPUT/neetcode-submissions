class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int i, int j, string &word1, string &word2, int n, int m) {
        if(i == n) {
            return m - j;
        }
        if(j == m) {
            return n - i;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(word1[i] == word2[j]) {
            dp[i][j] = dfs(i + 1, j + 1, word1, word2, n, m);
        }

        else{
            int ans = min(dfs(i+1, j, word1, word2, n, m), dfs(i, j+1, word1, word2, n, m));
            ans = min(ans, dfs(i+1, j+1, word1, word2, n, m));
            dp[i][j] = ans + 1;
        }

        return dp[i][j];

    } 
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return dfs(0, 0, word1, word2, n, m);

    }
};
