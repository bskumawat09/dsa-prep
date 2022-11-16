/*
 * https://leetcode.com/problems/minimum-falling-path-sum-ii/
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
    int dp[201][201];

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Code here
        memset(dp, -1, sizeof(dp));

        int N = grid.size();
        int minPathSum = INT_MAX;

        for(int c = 0; c < N; c++) {
            minPathSum = min(minPathSum, _minFallingPathSum(0, c, grid));
        }

        return minPathSum;
    }

    int _minFallingPathSum(int r, int c, vector<vector<int>>& grid) {
        int N = grid.size();

        if(c < 0 || c >= N) return INT_MAX;
        if(r == N - 1) return grid[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int minPathSum = INT_MAX;

        for(int j = 0; j < N; j++) {
            if(j != c)
                minPathSum = min(minPathSum, _minFallingPathSum(r + 1, j, grid));
        }

        return dp[r][c] = grid[r][c] + minPathSum;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 *
 *
 */

class SolutionTab {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    SolutionMemo solMemo;
    cout << solMemo.minFallingPathSum(grid) << endl;

    SolutionTab solTab;
    cout << solTab.minFallingPathSum(grid) << endl;

    return 0;
}

/*
 * Input:
 * matrix = {{1, 2, 3},
 *           {4, 5, 6},
 *           {7, 8, 9}}
 *
 * Output:
 * 13
 *
 */