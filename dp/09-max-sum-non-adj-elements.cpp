/*
 * https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
 * https://leetcode.com/problems/house-robber/
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define N 10001

class SolutionMemo {
public:
    int dp[N];

    int maxSumNonAdjacent(int nums[], int n) {
        // Code here
        memset(dp, -1, sizeof(dp));
        return helper(nums, n);
    }

    int helper(int nums[], int n) {
        if(n == 1) return nums[0];  // if there is only 1 element

        if(n == 0) return 0;  // if there is no element

        if(dp[n] != -1) return dp[n];

        int excl = 0 + helper(nums, n - 1);
        int incl = nums[n - 1] + helper(nums, n - 2);

        return dp[n] = max(excl, incl);
    }
};

/*
 --------------------------------------------Tabulation--------------------------------------------
 * 1d DP
 * Storage & Meaning: dp[i] => max. sum non-adjacent elements in the range (0 to i)
 *
 */

class SolutionTab {
public:
    int dp[N];

    int maxSumNonAdjacent(int nums[], int n) {
        // Code here
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

/*
 --------------------------------------------Space Optimized--------------------------------------------
 * DP using 2 variables
 * Only dp[i-1] and dp[i-2] is required
 *
 */

class SolutionTabOpti {
public:
    int maxSumNonAdjacent(int nums[], int n) {
        // Code here
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int excl = 0 + prev;
            int incl = nums[i] + prev2;
            int curr = max(excl, incl);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main() {
    int nums[] = {5, 20, 15, -2, 18};
    int n = sizeof(nums) / sizeof(nums[0]);

    SolutionMemo solMemo;
    cout << solMemo.maxSumNonAdjacent(nums, n) << endl;

    SolutionTab solTab;
    cout << solTab.maxSumNonAdjacent(nums, n) << endl;

    SolutionTabOpti solTabOpti;
    cout << solTabOpti.maxSumNonAdjacent(nums, n) << endl;

    return 0;
}

/*
 Input:
 nums[] = [5, 20, 15, -2, 186]
 n = 3

 Output:
 38

 */