/*
 * https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief fun(n, sum) => whether elements till "n" can make target "sum"
 *
 */
class SolutionMemo {
public:
    bool targetSumSubset(vector<int>& nums, int sum) {
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return _targetSumSubset(nums, n, sum, dp);
    }

    int _targetSumSubset(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if(sum == 0) return 1;
        if(n == 1) return nums[0] == sum;

        if(dp[n][sum] != -1) return dp[n][sum];

        bool excl = _targetSumSubset(nums, n - 1, sum, dp);  // exclude
        if(excl) return dp[n][sum] = 1;

        if(sum >= nums[n - 1]) {  // include
            bool incl = _targetSumSubset(nums, n - 1, sum - nums[n - 1], dp);
            if(incl) return dp[n][sum] = 1;
        }

        return dp[n][sum] = 0;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 * @brief dp[n][sum] => whether elements till "n" can make target "sum"
 *
 */

class SolutionTab {
public:
    bool targetSumSubset(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(j == 0)  // if target sum to make is "0"
                    dp[i][j] = true;
                else if(i == 0)  // if there is no element
                    dp[i][j] = false;
                else {
                    dp[i][j] = dp[i - 1][j];
                    if(j >= nums[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
        }

        return dp[n][sum];
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 4};
    int sum = 4;

    SolutionMemo solMemo;
    cout << solMemo.targetSumSubset(nums, sum) << endl;

    SolutionTab solTab;
    cout << solTab.targetSumSubset(nums, sum) << endl;

    return 0;
}

/*
 * Input:
 * nums = [1, 3, 2, 4]
 * sum = 4
 *
 * Output:
 * true
 *
 */
