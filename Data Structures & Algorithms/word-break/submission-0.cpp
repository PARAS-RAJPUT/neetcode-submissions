#include<bits/stdc++.h>
class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[1001];

    bool solve(string s, int i) {
        if(i >= n) {
            return true;
        }

        if(st.find(s) != st.end()) {
            return true;
        }

        if(t[i] != -1) {
            return t[i];
        }

        for(int j = 1; j <= n; j++) {
            string temp = s.substr(i, j);
            if((st.find(temp) != st.end()) && solve(s, i+j)) {
                return t[i] = true;
            }
        }

        return t[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for(string &word : wordDict) {
            st.insert(word);
        }

        memset(t, -1, sizeof(t));
        return solve(s, 0);
    }
};
