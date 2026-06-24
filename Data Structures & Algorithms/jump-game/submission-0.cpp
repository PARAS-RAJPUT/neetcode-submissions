#include<cstring>
class Solution {
public:
    int t[10001];

    bool solve(vector<int>& nums, int idx, int n) {
        if(idx == n - 1) {
            return  true;
        }

        if(t[idx] != -1) {
            return t[idx];
        }

        for(int i = 1; i <= nums[idx]; i++) {
            if(solve(nums, i + idx, n) == true) {
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};
