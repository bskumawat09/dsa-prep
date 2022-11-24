/*
 * https://practice.geeksforgeeks.org/problems/word-search/1
 * https://leetcode.com/problems/word-search/
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// four adjacent directions "URLD"
const int dr[] = {-1, 0, 0, 1};
const int dc[] = {0, 1, -1, 0};

class Solution {
public:
    bool exist(vector<vector<bool>>& board, string word) {
        // Code here
        int R = board.size();
        int C = board[0].size();

        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(board[r][c] == word[0]) {
                    if(dfs(r, c, board, word, 1))
                        return true;
                }
            }
        }

        return false;
    }

private:
    /**
     * @brief simple dfs to seach "word" in a 2d "borad" of characters
     *
     * @param r row of current cell
     * @param c column of current cell
     * @param board 2d character board
     * @param word word to be searched
     * @param idx word[idx] to be searched in four adjacent cells of current cells
     * @return true if whole word is found
     * @return false otherwise
     */
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int idx) {
        if(idx == word.length()) return true;

        char ch = board[r][c];
        board[r][c] = '$';  // mark it as visited

        for(int i = 0; i < 4; i++) {  // explore all 4 direction against word[idx]
            int nr = r + dr[i];       // next row
            int nc = c + dc[i];       // next col

            if(isSafe(nr, nc, board) && board[nr][nc] == word[idx]) {
                bool isExist = dfs(nr, nc, board, word, idx + 1);
                if(isExist) return true;
            }
        }

        board[r][c] = ch;  // undo mark, so that it can be used again
        return false;
    }

    bool isSafe(int r, int c, vector<vector<char>>& board) {
        int R = board.size();
        int C = board[0].size();

        if(r < 0 || c < 0 || r >= R || c >= C) return false;  // if out of board
        if(board[r][c] == '$') return false;                  // if cell is already visited

        return true;
    }
};

/*
 * Input:
 * board = [
 *              ["A","B","C","E"],
 *              ["S","F","C","S"],
 *              ["A","D","E","E"],
 *         ]
 * word = "SEE"
 *
 * Output:
 * true
 *
 */
