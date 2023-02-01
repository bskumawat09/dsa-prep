/**
 * https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
 * https://leetcode.com/problems/unique-paths/
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
public:
    int gridUniquePaths(int m, int n) {
        // Code here
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        return _gridUniquePaths(m - 1, n - 1);
    }

    int _gridUniquePaths(int r, int c) {
        if(r < 0 || c < 0) return 0;
        if(r == 0 && c == 0) return 1;

        if(dp[r][c] != -1) return dp[r][c];

        int up = _gridUniquePaths(r - 1, c);
        int right = _gridUniquePaths(r, c - 1);

        return dp[r][c] = up + right;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 * @brief dp[i][j] => # of unique paths from (0,0) to (i,j).
 * direction: dp[0][0] --> dp[m][n]
 *
 */

class SolutionTab {
public:
    int gridUniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    if(i > 0)
                        dp[i][j] += dp[i - 1][j];

                    if(j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 3;
    int n = 3;

    SolutionMemo solMemo;
    cout << solMemo.gridUniquePaths(m, n) << endl;

    SolutionTab solTab;
    cout << solTab.gridUniquePaths(m, n) << endl;

    return 0;
}

/**
 * Input:
 * m = 3, n = 3
 *
 * Output:
 * 6
 *
 */