#include<cstring>
class Solution {
public:
    int n;
    int t[1001][1001];
    int solve(vector<int>& nums, int i, int target) {
        if(target == 0) {
            return 1;
        }

        if(target < 0 || i >= n) {
            return 0;
        }

        if(t[i][target] != -1) {
            return t[i][target];
        }

        int take_i = solve(nums, 0, target - nums[i]);
        int skip_i = solve(nums, i + 1, target);

        return t[i][target] = take_i + skip_i;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, target);
    }
};