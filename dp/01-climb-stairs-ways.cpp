class SolutionMemo {
    vector<int> dp;

public:
    int climbStairs(int n) {
        // Code here
        dp = vector<int>(n, -1);
        return _climb(n);
    }

    int _climb(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        dp[n] = _climb(n - 1) + _climb(n - 2) + _climb(n - 3);
        return dp[n];
    }
};

class SolutionTab {
public:
    int climbStair(int n) {
        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};
