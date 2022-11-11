#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {  // Top-down
    vector<int> dp;

public:
    int fibonacci(int n) {
        // Code here
        dp = vector<int>(n + 1, -1);
        return _fib(n);
    }

    int _fib(int n) {
        if(n == 0 || n == 1) return n;

        if(dp[n] != -1) return dp[n];

        dp[n] = _fib(n - 1) + _fib(n - 2);
        return dp[n];
    }
};

class SolutionTab {  // Bottom-up
public:
    int fibonacci(int n) {
        // Code here
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class Solution {  // Space optimized
public:
    int fibonacci(int n) {
        // Code here
        int prev1 = 1;
        int prev2 = 0;
        int cur;

        if(n == 0 || n == 1) return n;

        for(int i = 2; i <= n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};

int main() {
    SolutionMemo solMemo;
    cout << solMemo.fibonacci(7) << endl;

    SolutionTab solTab;
    cout << solTab.fibonacci(7) << endl;

    Solution sol;
    cout << sol.fibonacci(7) << endl;

    return 0;
}
