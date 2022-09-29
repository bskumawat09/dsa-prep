/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

*/

const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};
const string dir = "DLRU";

class Solution {
public:
    vector<string> findPath(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        if(maze[0][0] == 1) {
            string psf = "";
            dfs(0, 0, psf, maze, ans, visited);
        }

        return ans;
    }

    void dfs(int r, int c, string psf, vector<vector<int>>& maze, vector<string>& ans, vector<vector<bool>>& visited) {
        int n = maze.size();

        if(r == n - 1 && c == n - 1) {  // if destination cell is reached
            ans.push_back(psf);
            return;
        }

        visited[r][c] = true;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];  // next row
            int nc = c + dc[i];  // next column

            if(isSafe(nr, nc, n, maze, visited)) {
                dfs(nr, nc, psf + dir[i], maze, ans, visited);
            }
        }

        visited[r][c] = false;
    }

    bool isSafe(int r, int c, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
        if(r < 0 || c < 0 || r >= n || c >= n)
            return false;
        if(maze[r][c] == 0 || visited[r][c] == true)
            return false;
        return true;
    }
};

/*
Input:
maze[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}}

Output:
DDRDRR DRDDRR

Time    = O(4^(N^2))
Space   = O(N*N)
*/
