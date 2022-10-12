/*
 https://practice.geeksforgeeks.org/problems/coin-change2448/1

 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define N 1001

class SolutionMemo {
public:
    long long int dp[N];

    long long int coinChange(int coins[], int n, int sum) {
        // Code here
        memset(dp, 0, sizeof(dp));

        return helper(coins, n, sum);
    }

    long long int helper(int coins[], int n, int sum) {
        if(sum == 0) return 1;

        if(dp[sum] != 0) return dp[sum];

        long long int ways = 0;

        for(int i = 0; i < n; i++) {
            if(sum >= coins[i]) {
                ways += helper(coins, n, sum - coins[i]);
            }
        }

        return dp[sum] = ways;
    }
};

/*
 --------------------------------------------Tabulation--------------------------------------------
 * 1d DP
 * Storage & Meaning: dp[i] => # of ways to make the sum "j" permuting all coins.
 *
 */

class SolutionTab {
public:
    long long int dp[N];
    long long int coinChange(int coins[], int n, int sum) {
        // Code here
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i = 1; i <= sum; i++) {   // loop over dp[]
            for(int j = 0; j < n; j++) {  // loop over coins[]
                if(i >= coins[j])
                    dp[i] += dp[i - coins[j]];
            }
        }

        return dp[sum];
    }
};

int main() {
    int coins[] = {2, 3, 5};
    int sum = 8;
    int n = sizeof(coins) / sizeof(coins[0]);

    SolutionMemo solMemo;
    int ansMemo = solMemo.coinChange(coins, n, sum);
    cout << ansMemo << endl;

    SolutionTab solTab;
    int ansTab = solTab.coinChange(coins, n, sum);
    cout << ansTab << endl;

    return 0;
}
