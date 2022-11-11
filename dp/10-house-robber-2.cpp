/*
 https://leetcode.com/problems/house-robber-ii

 Since House[1] and House[n] are adjacent, they cannot be robbed together.
 Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n],depending on which choice offers more money.

 */

class Solution {
public:
    int dp[1001];

    int rob(vector<int>& nums) {
        // Code here
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < n; i++) {
            if(i != 0)
                temp1.push_back(nums[i]);
            if(i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(_rob(temp1), _rob(temp2));
    }

    int _rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));

        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            int excl = dp[i - 1];
            int incl = nums[i];
            if(i >= 2) {
                incl += dp[i - 2];
            }
            dp[i] = max(excl, incl);
        }

        return dp[n - 1];
    }
};
