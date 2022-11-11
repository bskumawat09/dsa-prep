#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
    vector<int> dp;

public:
    int climbStairs(int jumps[], int n) {
        // Code here
        dp = vector<int>(n, -1);
        return _climb(0, jumps, n);
    }

    /**
     * @brief fn(i) => min # of moves to reach "n" from "i"
     * direction of calls: fn(0) --> fn(n)
     * direction of fills: fn(n) --> fn(0)
     *
     */
    int _climb(int stp, int jumps[], int n) {
        if(stp == n) return 0;

        if(dp[stp] != -1) return dp[stp];

        int minMoves = INT_MAX;

        for(int j = 1; j <= jumps[stp]; j++) {
            if(stp + j <= n)
                minMoves = min(minMoves, _climb(stp + j, jumps, n));
        }

        if(minMoves == INT_MAX) return minMoves;
        return dp[stp] = 1 + minMoves;
    }
};

class SolutionTab {
public:
    /**
     * @brief dp[i] => min # of moves to reach "n" from "i"
     * direction: dp[n] --> dp[0]
     *
     */
    int climbStairs(int jumps[], int n) {
        // Code here
        vector<int> dp(n + 1);

        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {
            int minMoves = INT_MAX;

            for(int j = 1; j <= jumps[i]; j++) {
                if(i + j <= n)
                    minMoves = min(minMoves, dp[i + j]);
            }

            if(minMoves == INT_MAX)
                dp[i] = minMoves;
            else
                dp[i] = 1 + minMoves;
        }

        return dp[0];
    }
};

int main() {
    int jumps[] = {3, 1, 2, 0, 3, 2};
    int n = sizeof(jumps) / sizeof(jumps[0]);

    SolutionMemo solMemo;
    cout << solMemo.climbStairs(jumps, n) << endl;

    SolutionTab solTab;
    cout << solTab.climbStairs(jumps, n) << endl;

    return 0;
}

/**
 * Input:
 * n = 6, jumps[] = {3, 1, 2, 0, 3, 2}
 *
 * Output:
 * 3
 *
 */
