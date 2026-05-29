class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int rcount = t.length();

        if(rcount > n) {
            return "";
        }

        unordered_map<char, int> mp;

        for(char &ch : t) {
            mp[ch]++;
        }

        int i = 0;
        int j = 0;
        int start_i = 0;

        int minWindowsize = INT_MAX;

        while(j < n) {
            char ch = s[j];

            if(mp[ch] > 0) {
                rcount--;
            }

            mp[ch]--;

            while(rcount == 0) {
                int currWindowsize = j - i + 1;

                if(currWindowsize < minWindowsize) {
                    minWindowsize = currWindowsize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0) {
                    rcount++;
                }

                i++;
            }
            j++;
        }

        return minWindowsize == INT_MAX ? "" : s.substr(start_i, minWindowsize);
    }
};
