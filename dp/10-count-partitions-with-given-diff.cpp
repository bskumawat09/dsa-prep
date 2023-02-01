/**
 * https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int mod = (int)1e9 + 7;

class Solution {
public:
    int countPartitions(vector<int>& nums, int d) {
        // Code here
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += nums[i];

        if(totalSum < d || (totalSum - d) % 2) return 0;  // edge cases

        int sum = (totalSum - d) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return countSubsetsWithGivenSum(nums, n, sum, dp);
    }

    int countSubsetsWithGivenSum(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if(n == 0) {
            if(sum == 0) return 1;
            return 0;
        }

        if(dp[n][sum] != -1) return dp[n][sum];

        int excl = countSubsetsWithGivenSum(nums, n - 1, sum, dp);

        int incl = 0;
        if(sum >= nums[n - 1])
            incl = countSubsetsWithGivenSum(nums, n - 1, sum - nums[n - 1], dp);

        return dp[n][sum] = (excl + incl) % mod;
    }
};

int main() {
    vector<int> nums = {1, 5, 1, 2};
    int d = 3;

    Solution sol;
    cout << sol.countPartitions(nums, d);

    return 0;
}

/**
 * Input:
 * nums[] = {1,5,1,2}
 * d = 3
 *
 * Output:
 * 2
 *
 */