/*
 * https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
    int dp[501][501];

public:
    int goldmine(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        memset(dp, -1, sizeof(dp));

        int maxGold = 0;
        for(int r = 0; r < N; r++) {
            maxGold = max(maxGold, _goldmine(r, 0, matrix));
        }

        return maxGold;
    }

    int _goldmine(int r, int c, vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        if(r < 0 || r >= N) return 0;
        if(c == M - 1) return matrix[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int maxGold = 0;
        maxGold = max(maxGold, _goldmine(r - 1, c + 1, matrix));
        maxGold = max(maxGold, _goldmine(r, c + 1, matrix));
        maxGold = max(maxGold, _goldmine(r + 1, c + 1, matrix));

        return dp[r][c] = matrix[r][c] + maxGold;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 * @brief dp[r][c] => max gold can get if we start from (r,c).
 * direction: dp[r][M] --> dp[r][0]
 *
 */

class SolutionTab {
public:
    int goldmine(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

        for(int c = M - 1; c >= 0; c--) {
            for(int r = N - 1; r >= 0; r--) {
                if(c == M - 1) {
                    dp[r][c] = matrix[r][c];
                } else {
                    dp[r][c] = dp[r][c + 1];
                    if(r < N - 1) dp[r][c] = max(dp[r][c], dp[r + 1][c + 1]);
                    if(r > 0) dp[r][c] = max(dp[r][c], dp[r - 1][c + 1]);

                    dp[r][c] += matrix[r][c];
                }
            }
        }

        int maxPathSum = 0;
        for(int r = 0; r < N; r++) {
            maxPathSum = max(maxPathSum, dp[r][0]);
        }
        return maxPathSum;
    }
};

/**
 --------------------------------------------Space Optimized--------------------------------------------
 *
 *
 *
 */

class SolutionTabOpti {
public:
    int goldmine(vector<vector<int>>& matrix) {
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2},
    };

    SolutionMemo solMemo;
    cout << solMemo.goldmine(matrix) << endl;

    SolutionTab solTab;
    cout << solTab.goldmine(matrix) << endl;

    SolutionTabOpti solTabOpti;
    cout << solTabOpti.goldmine(matrix) << endl;

    return 0;
}

/*
 * Input:
 * matrix = {{1, 3, 1, 5},
 *           {2, 2, 4, 1},
 *           {5, 0, 2, 3},
 *           {0, 6, 1, 2}}
 *
 * Output:
 * 16
 *
 */