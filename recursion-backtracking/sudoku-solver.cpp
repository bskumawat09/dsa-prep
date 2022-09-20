#include <iostream>
#include <vector>
using namespace std;

/*
https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

*/

class Solution {
public:
    void solveSudoku(vector<vector<int>>& board) {
        // Code here
        _solve(0, 0, board);
    }

private:
    void _solve(int r, int c, vector<vector<int>>& board) {
        int n = board.size();
        if(r == n) {
            printBoard(board);
            return;
        }

        int nr, nc;  // calculate next row & next column
        if(c == n - 1) {
            nr = r + 1;
            nc = 0;
        } else {
            nr = r;
            nc = c + 1;
        }

        if(board[r][c] != 0) {
            _solve(nr, nc, board);
        } else {
            for(int num = 1; num <= 9; num++) {
                if(isSafe(r, c, num, board)) {
                    board[r][c] = num;
                    _solve(nr, nc, board);
                    board[r][c] = 0;
                }
            }
        }
    }

    bool isSafe(int r, int c, int num, vector<vector<int>>& board) {
        int n = board.size();

        // check in corresponding row & column
        for(int i = 0; i < n; i++) {
            if(board[r][i] == num) return false;
            if(board[i][c] == num) return false;
        }

        // find sub-matrix base-row & base-column
        int br = r / 3 * 3;
        int bc = c / 3 * 3;

        // check in the corresponding 3*3 sub-matrix
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[br + i][bc + j] == num)
                    return false;
            }
        }

        return true;
    }

    void printBoard(vector<vector<int>>& board) {
        for(vector<int> row : board) {
            for(int c : row) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };

    Solution sol;
    sol.solveSudoku(board);

    return 0;
}

/*
Time    = O(9^(N*N))
Space   = O(N*N)

Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

*/
