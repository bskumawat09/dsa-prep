/*
 * https://leetcode.com/problems/minimum-path-sum/
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return minPathSum(m - 1, n - 1, grid);
    }

    int _minPathSum(int m, int n, vector<vector<int>>& grid) {
        if(m == 0 && n == 0) return grid[0][0];

        if(m < 0 || n < 0) return INT_MAX;

        if(dp[m][n] != -1) return dp[m][n];

        int up = _minPathSum(m - 1, n, grid);
        int right = _minPathSum(m, n - 1, grid);

        return dp[m][n] = grid[m][n] + min(up, right);
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 * @brief dp[i][j] => min path sum from (0,0) to (i,j).
 * direction: dp[0][0] --> dp[m][n]
 *
 */

class SolutionTab {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else {
                    if(i > 0)
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][j]);

                    if(j > 0)
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    }

    SolutionMemo solMemo;
    cout << solMemo.gridUniquePaths(grid) << endl;

    SolutionTab solTab;
    cout << solTab.gridUniquePaths(grid) << endl;

    return 0;
}

/*
 * Input:
 * {{1,3,1},
 *  {1,5,1},
 *  {4,2,1}}
 *
 * Output:
 * 7
 *
 */