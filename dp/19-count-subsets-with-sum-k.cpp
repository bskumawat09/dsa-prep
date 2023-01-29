/**
 * https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
public:
    int countSubsets(vector<int>& nums, int sum) {
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return _countSubsets(nums, n, sum, dp);
    }

    int _countSubsets(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if(n == 0) {  // imp step
            if(sum == 0) return 1;
            return 0;
        }

        if(dp[n][sum] != -1) return dp[n][sum];

        int excl = _countSubsets(nums, n - 1, sum, dp);

        int incl = 0;
        if(sum >= nums[n - 1])
            incl = _countSubsets(nums, n - 1, sum - nums[n - 1], dp);

        return dp[n][sum] = excl + incl;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 *
 */

class SolutionTab {
public:
    int countSubsets(vector<int>& nums, int sum) {
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for(int i = 0; i <= n; i++) {
            for(int s = 0; s <= sum; s++) {
                if(i == 0) {
                    if(s == 0)
                        dp[i][s] = 1;  // imp step
                    else
                        dp[i][s] = 0;
                } else {
                    dp[i][s] = dp[i - 1][s];
                    if(s >= nums[i - 1])
                        dp[i][s] += dp[i - 1][s - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};

int main() {
    vector<int> nums = {1, 3, 0, 4};
    int sum = 4;

    SolutionMemo solMemo;
    cout << solMemo.countSubsets(nums, sum) << endl;

    SolutionTab solTab;
    cout << solTab.countSubsets(nums, sum) << endl;

    return 0;
}

/**
 * Input:
 * nums = [1, 3, 0, 4]
 * sum = 4
 *
 * Output:
 * 4
 *
 */
