/*
 * https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class SolutionMemo {
    vector<vector<int>> dp;

public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        // Code here
        dp = vector<vector<int>>(n, vector<int>(4, -1));
        return _ninjaTraining(0, points, 3);
    }

    /**
     * @brief fn(i, t) => max points ninja can earn in days "i" to "n" such that on i'th day he do not perform activity "t".
     * direction of calls: fn(0,t) --> fn(n,t)
     * direction of fills: fn(n,t) --> fn(0,t)
     *
     */
    int _ninjaTraining(int day, vector<vector<int>>& points, int lastTask) {
        if(day == points.size() - 1) {
            int maxPoints = 0;

            for(int t = 0; t < 3; t++) {
                if(t != lastTask)
                    maxPoints = max(maxPoints, points[day][t]);
            }
            return maxPoints;
        }

        if(dp[day][lastTask] != -1) return dp[day][lastTask];

        int maxPoints = 0;

        for(int t = 0; t < 3; t++) {
            if(t != lastTask) {
                int pts = points[day][t] + _ninjaTraining(day + 1, points, t);
                maxPoints = max(maxPoints, pts);
            }
        }
        return dp[day][lastTask] = maxPoints;
    }
};

/**
 --------------------------------------------Tabulation--------------------------------------------
 * @brief dp[i][j] => max points ninja can earn in days "d0" to "di" such that on i'th day it perform j'th task (i.e last performed task is "j").
 * direction: dp[0][t] --> dp[n][t]
 *
 */

class SolutionTab {
public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(4));

        for(int i = 0; i < 4; i++) {
            dp[0][i] = points[0][i];
        }

        for(int d = 1; d < n; d++) {
            for(int lt = 0; lt < 4; lt++) {
                int maxPoints = 0;
                for(int t = 0; t < 4; t++) {
                    if(t != lt)
                        maxPoints = max(maxPoints, dp[d - 1][t]);
                }
                dp[d][lt] = maxPoints + points[d][lt];
            }
        }

        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};

/**
 * Tabulation method 2
 *
 */

class SolutionTab2 {
public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(4));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);

        for(int d = 1; d < n; d++) {
            for(int lt = 0; lt < 4; lt++) {
                int maxPoints = 0;

                for(int t = 0; t < 4; t++) {
                    if(t != lt) {
                        int p = points[d][t] + dp[d - 1][t];
                        maxPoints = max(maxPoints, p);
                    }
                }
                dp[d][lt] = maxPoints;
            }
        }

        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};

/*
 --------------------------------------------Space Optimized--------------------------------------------
 *
 */

class SolutionTabOpti {
public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<int> dp(4);
        vector<int> temp(4);

        for(int i = 0; i < 4; i++) {
            dp[i] = points[0][i];
        }

        for(int d = 1; d < n; d++) {
            for(int lt = 0; lt < 4; lt++) {
                int maxPoints = 0;

                for(int t = 0; t < 4; t++) {
                    if(t != lt)
                        maxPoints = max(maxPoints, dp[t]);
                }

                temp[lt] = points[d][lt] + maxPoints;
            }
            dp = temp;
            temp = vector<int>(4);
        }

        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    // vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    vector<vector<int>> points = {{94, 85, 49}, {14, 63, 1}, {35, 6, 80}, {2, 65, 11}, {94, 92, 47}, {99, 97, 51}};

    int n = points.size();

    SolutionMemo solMemo;
    cout << solMemo.ninjaTraining(n, points) << endl;

    SolutionTab solTab;
    cout << solTab.ninjaTraining(n, points) << endl;

    SolutionTab2 solTab2;
    cout << solTab2.ninjaTraining(n, points) << endl;

    SolutionTabOpti solTabOpti;
    cout << solTabOpti.ninjaTraining(n, points) << endl;

    return 0;
}

/*
 * Input:
 * n = 3
 * points[][] = {{1, 2, 5},
 *               {3, 1, 1},
 *               {3, 3, 3}}
 *
 * Output:
 * 11
 *
 */
