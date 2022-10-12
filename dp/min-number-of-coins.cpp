/*
 https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9
#define N 101

class SolutionMemo {
public:
    int dp[N][N];

    int minCoins(int coins[], int n, int sum) {
        memset(dp, -1, sizeof(dp));
        return _minCoins(0, coins, n, sum);
    }

    int _minCoins(int idx, int coins[], int n, int sum) {
        if(sum == 0) return 0;
        if(idx == n) return INF;

        // if(idx == n - 1) {
        //     if(sum % coins[idx] == 0)
        //         return sum / coins[idx];
        //     return INF;
        // }

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int excl = _minCoins(idx + 1, coins, n, sum);
        int incl = INF;

        if(sum >= coins[idx]) {
            incl = 1 + _minCoins(idx, coins, n, sum - coins[idx]);
        }

        return dp[idx][sum] = min(excl, incl);
    }
};

/*
 --------------------------------------------Tabulation--------------------------------------------
 * 2d DP
 * Storage & Meaning: dp[i][j] => min # of coins to make the sum "j" by combining first "i" coins.
 *
 */

class SolutionTab {
public:
    int dp[N][N];

    int minCoins(int coins[], int n, int sum) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(j == 0) {  // min '0' coins are required to make sum of '0'
                    dp[i][j] = 0;
                } else if(i == 0) {  // if we have no coins, we can't make any sum
                    dp[i][j] = INF;
                } else {
                    dp[i][j] = dp[i - 1][j];  // exclude current coin
                    if(j >= coins[i - 1]) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);  // include current coin
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
 * Storage & Meaning: dp[i] => min # of coins to make sum "i".
 *
 */

class SolutionTabOpti {
public:
    vector<int> dp;

    int coinChange(int coins[], int n, int sum) {
        dp = vector<int>(sum + 1, INF);  // Note: memset() can be used only to intialize with 0 or -1
        dp[0] = 0;

        for(int i = 0; i < n; i++) {         // loop over coins[]
            for(int j = 1; j <= sum; j++) {  // loop over dp[]
                if(j >= coins[i])
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }

        return dp[sum];
    }
};

int main() {
    int coins[] = {25, 10, 6};
    int sum = 30;
    int n = sizeof(coins) / sizeof(coins[0]);

    SolutionMemo solMemo;
    cout << solMemo.minCoins(coins, n, sum) << endl;

    SolutionTab solTab;
    cout << solTab.minCoins(coins, n, sum) << endl;

    SolutionTabOpti solTabOpti;
    cout << solTabOpti.coinChange(coins, n, sum) << endl;

    return 0;
}

/*
 Input:
 coins[] = [25, 10, 6]
 n = 3
 sum = 30

 Output:
 2

 */