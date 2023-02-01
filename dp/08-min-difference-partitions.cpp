/**
 * Partition the given array into two subsets such that the difference of subset sums are as minimum as possible.
 * Return the minimum absolute difference.
 * Note: 1 <= nums[i]
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionWithMinDifference(vector<int>& nums) {
        // Code here
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];

        // Get the dp[][] filled up using "Target Sum Subset" code
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

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

        // Iterate over last row of dp[][] to get minimum absolute difference
        int diff = INT_MAX;
        for(int s = 0; s <= sum / 2; s++) {
            if(dp[n][s] == true) {
                diff = min(diff, abs((sum - s) - s));
            }
        }

        return diff;
    }
};

int main() {
    vector<int> nums = {2, 1, 3, 4, 5};

    Solution sol;
    cout << sol.partitionWithMinDifference(nums) << endl;

    return 0;
}

/*
 * Input:
 * nums = [2,1,3,4,5]
 *
 * Output:
 * 1     (It can be partitioned as [1,3,4] and [2,5])
 *
 */
