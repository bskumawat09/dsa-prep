/*
 https://practice.geeksforgeeks.org/problems/coin-change2448/1

 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define N 101

class SolutionMemo {
public:
    int dp[N][N];

    int coinChange(int coins[], int n, int sum) {
        // Code here
        memset(dp, -1, sizeof(dp));

        return helper(0, coins, n, sum);
    }

    int helper(int idx, int coins[], int n, int sum) {
        if(idx == n) return 0;

        if(sum == 0) return 1;

        if(dp[idx][sum] != -1)  // if result is already computed earlier
            return dp[idx][sum];

        int ways = 0;
        if(sum >= coins[idx]) {  // use this coin
            ways += helper(idx, coins, n, sum - coins[idx]);
        }
        ways += helper(idx + 1, coins, n, sum);  // don't use this coin

        return dp[idx][sum] = ways;
    }
};

/*
 --------------------------------------------Tabulation--------------------------------------------
 * 2d DP
 * Storage & Meaning: dp[i][j] => # of ways to make the sum "j" by combining first "i" coins.
 *
 */

class SolutionTab {
public:
    int dp[N][N];

    int coinChange(int coins[], int n, int sum) {
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                } else if(i == 0) {
                    dp[i][j] = 0;
                } else {
                    // in how many ways, the sum "j" can be made using first "i-1" coins and excluding current i.e i'th coin
                    dp[i][j] = dp[i - 1][j];

                    // in how many ways, the sum "j" can be made if current coin can also be used
                    if(j >= coins[i - 1]) {
                        dp[i][j] += dp[i][j - coins[i - 1]];
                    }
                }
            }
        }

        return dp[n][sum];
    }
};

/*
 --------------------------------------------Space Optimized--------------------------------------------
 * 1d DP
 * Storage & Meaning: dp[i] => # of ways to make sum "i".
 *
 */

class SolutionTabOpti {
public:
    int dp[N];

    int coinChange(int coins[], int n, int sum) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < n; i++) {         // loop over coins[]
            for(int j = 1; j <= sum; j++) {  // loop over dp[]
                if(j >= coins[i])
                    dp[j] += dp[j - coins[i]];
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

    SolutionTabOpti solTabOpti;
    int ansTabOpti = solTabOpti.coinChange(coins, n, sum);
    cout << ansTabOpti << endl;

    return 0;
}
