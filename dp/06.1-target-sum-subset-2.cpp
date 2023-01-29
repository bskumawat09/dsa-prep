/**
 * "Target Sum Subset" problem with negative numbers allowed
 *
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int targetSumSubset(vector<int>& nums, int target) {
        // Code here
        int n = nums.size();

        int negiSum = 0;
        int posiSum = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0)
                negiSum += nums[i];
            else
                posiSum += nums[i];
        }

        vector<map<int, bool>> dp(n + 1);

        for(int i = 0; i <= n; i++) {
            for(int s = negiSum; s <= posiSum; s++) {
                if(s == 0)
                    dp[i][s] = true;
                else if(i == 0)
                    dp[i][s] = false;
                else {
                    dp[i][s] = dp[i - 1][s];                            // don't pick
                    dp[i][s] = dp[i][s] || dp[i - 1][s - nums[i - 1]];  // pick
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    vector<int> nums = {2, -1, 0, 4, -2};
    int target = 5;

    Solution sol;
    cout << sol.targetSumSubset(nums, target) << endl;

    return 0;
}

/**
 * Input:
 * nums = [2,-1,0,4,-2]
 * target = 5
 *
 * Output:
 * 1     [2,-1,4]
 *
 */
