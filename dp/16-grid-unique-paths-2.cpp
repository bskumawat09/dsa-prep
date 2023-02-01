/*
 * https://leetcode.com/problems/unique-paths-ii/
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
public:
    int gridUniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return _gridUniquePaths(m - 1, n - 1, grid);
    }

    int _gridUniquePaths(int r, int c, vector<vector<int>>& grid) {
        if(r < 0 || c < 0) return 0;
        if(grid[r][c] == 1) return 0;
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
    int gridUniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) continue;

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
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    }

    SolutionMemo solMemo;
    cout << solMemo.gridUniquePaths(grid) << endl;

    SolutionTab solTab;
    cout << solTab.gridUniquePaths(grid) << endl;

    return 0;
}

/*
 * Input:
 * {{0,0,0},
 *  {0,1,0},
 *  {0,0,0}}
 *
 * Output:
 * 2
 *
 */