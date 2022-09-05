/*
https://practice.geeksforgeeks.org/problems/cd61add036272faa69c6814e34aa7007d5a25aa6/1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralTraversal(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        int dir = 0;

        vector<int> ans;

        while(top <= bottom && left <= right) {
            if(dir == 0) {  // left to right
                for(int i = left; i <= right; i++) {
                    ans.push_back(mat[top][i]);
                }
                top += 1;
            } else if(dir == 1) {  // top to bottom
                for(int i = top; i <= bottom; i++) {
                    ans.push_back(mat[i][right]);
                }
                right -= 1;
            } else if(dir == 2) {  // right to left
                for(int i = right; i >= left; i--) {
                    ans.push_back(mat[bottom][i]);
                }
                bottom -= 1;
            } else if(dir == 3) {  // bottom to top
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(mat[i][left]);
                }
                left += 1;
            }
            dir = (dir + 1) % 4;
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {7, 4, 1, 9},
        {6, 0, 4, 3},
        {5, 7, 0, 1},
        {2, 6, 3, 5},
    };

    Solution sol;
    vector<int> ans = sol.spiralTraversal(mat);

    for(int it : ans) {
        cout << it << " ";
    }
    return 0;
}

/*
[
    [1,2,3,4],
    [7,4,1,9],
    [6,0,4,3],
    [5,7,0,1],
    [2,6,3,5],
]

1 2 3 4 9 3 1 5 3 6 2 5 6 7 4 1 4 0 7 0

Time    = O(N*N)
Space   = O(1)
*/
