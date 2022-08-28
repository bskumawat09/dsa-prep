/*

TCS NQT Advanced Coding Question-2 (23 Aug 2022)

Mahesh and Suresh are playing a new game "Checkers". Below are ruls:
The game is played by 2 players.
The game consists of N*M matrix. Each of the cell is background lit by lights. And these cells are either Green or Black.
The Green and Black cells are randomly lit and will be represented by 1's and 0's respectively.
Green cells are the cells that needs to be captured. Black cells cannot be captured.
Everyone is in the race to capture the maximum number of cells possible.
In a single chance, a player can capture all those adjacent cells which share an edge. Once there is no adjacent edge,
the chance breaks and next player will play.
Mahesh always start the game and Suresh is the second.
Both play optimally. Find out how many cells Suresh captures.

*/

#include <bits/stdc++.h>
using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

class Solution {
public:
    int getScore(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        vector<vector<bool>> visited(N, vector<bool>(M, 0));

        vector<int> scores;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    int cnt = 0;
                    dfs(i, j, grid, visited, cnt);
                    if(cnt) scores.push_back(cnt);
                    cnt = 0;
                }
            }
        }

        int ans = 0;

        sort(scores.begin(), scores.end(), greater<int>());

        for(int i = 0; i < scores.size(); i++) {
            if(i % 2)
                ans += scores[i];
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& cnt) {
        cnt++;
        visited[r][c] = true;

        for(int i = 0; i < 4; i++) {
            int r1 = r + dr[i];
            int c1 = c + dc[i];

            if(isSafe(r1, c1, grid, visited)) {
                dfs(r1, c1, grid, visited, cnt);
            }
        }
    }

    bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int N = grid.size();
        int M = grid[0].size();

        if(r < 0 || c < 0 || r >= N || c >= M) return false;

        if(grid[r][c] == 0 || visited[r][c]) return false;

        return true;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 1},
    };

    Solution sol;
    int player_b_core = sol.getScore(grid);
    cout << player_b_core << endl;

    return 0;
}
