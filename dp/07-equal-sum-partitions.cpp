/**
 * https://leetcode.com/problems/partition-equal-subset-sum/
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
public:
    bool equalPartitions(vector<int>& nums) {
        // Code here
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += nums[i];
        if((totalSum & 1) == 1) return false;  // if totalSum is odd

        vector<vector<int>> dp(n + 1, vector<int>(totalSum / 2 + 1, -1));

        return _targetSumSubsets(nums, n, totalSum / 2, dp);
    }

    bool _targetSumSubsets(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if(sum == 0) return true;
        if(n == 1) return nums[0] == sum;

        if(dp[n][sum] != -1) return dp[n][sum];

        bool excl = _targetSumSubsets(nums, n - 1, sum, dp);
        if(excl) return dp[n][sum] = true;

        if(sum >= nums[n - 1]) {
            bool incl = _targetSumSubsets(nums, n - 1, sum - nums[n - 1], dp);
            if(incl) return dp[n][sum] = true;
        }

        return dp[n][sum] = false;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 *
 */

class SolutionTab {
public:
    bool equalPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;

        return _targetSumSubsets(nums, sum / 2);
    }

    bool _targetSumSubsets(vector<int>& nums, int sum) {
        int n = nums.size();

        bool dp[n + 1][sum + 1];

        for(int i = 0; i <= n; i++) {
            for(int s = 0; s <= sum; s++) {
                if(s == 0)
                    dp[i][s] = true;
                else if(i == 0)
                    dp[i][s] = false;
                else {
                    dp[i][s] = dp[i - 1][s];
                    if(s >= nums[i - 1])
                        dp[i][s] = dp[i][s] || dp[i - 1][s - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};

int main() {
    vector<int> nums = {2, 3, 3, 3, 5};

    SolutionMemo solMemo;
    cout << solMemo.equalPartitions(nums) << endl;

    SolutionTab solTab;
    cout << solTab.equalPartitions(nums) << endl;

    return 0;
}

/**
 * Input:
 * nums = [2,3,3,3,5]
 *
 * Output:
 * true     (It can be partitioned as [2,3,3] and [3,5])
 *
 */
