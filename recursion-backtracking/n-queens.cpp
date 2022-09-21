/*
https://leetcode.com/problems/n-queens
https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

*/

class Solution {
public:
    vector<vector<string>> nQueens(int n) {
        vector<vector<string>> ans;

        // hashes to mark if there is any queen already present in a particular column, diagonal-1, diagonal-2
        vector<bool> colHash(n, false);
        vector<bool> dg1Hash(2 * n, false);
        vector<bool> dg2Hash(2 * n, false);

        // prepare empty board of n*n size
        vector<string> board(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                board[i].push_back('.');
        }

        placeQueen(0, n, board, ans, colHash, dg1Hash, dg2Hash);

        return ans;
    }

    void placeQueen(int r, int n, vector<string>& board, vector<vector<string>>& ans,
                    vector<bool>& colH, vector<bool>& dg1H, vector<bool>& dg2H) {
        if(r == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(isSafe(r, c, n, colH, dg1H, dg2H)) {
                board[r][c] = 'Q';
                colH[c] = true;
                dg1H[r + c] = true;
                dg2H[r - c + n - 1] = true;

                placeQueen(r + 1, n, board, ans, colH, dg1H, dg2H);

                board[r][c] = '.';
                colH[c] = false;
                dg1H[r + c] = false;
                dg2H[r - c + n - 1] = false;
            }
        }
    }

    bool isSafe(int r, int c, int n, vector<bool>& colHash, vector<bool>& dg1Hash, vector<bool>& dg2Hash) {
        if(colHash[c])
            return false;
        if(dg1Hash[r + c])
            return false;
        if(dg2Hash[r - c + n - 1])
            return false;
        return true;
    }
};

/*
Time    = O(N!)
Space   = O(N*N)
*/
