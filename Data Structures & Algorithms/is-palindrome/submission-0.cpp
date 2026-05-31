class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        string s2 = "";
        for(char c : s) {
            if(isalnum(c)) {
                s2 += tolower(c);
            }
        }

        reverse(s2.begin(), s2.end());

        for(char c : s) {
            if(isalnum(c)) {
                s1 += tolower(c);
            }
        }

        return s2 == s1;
    }
};
