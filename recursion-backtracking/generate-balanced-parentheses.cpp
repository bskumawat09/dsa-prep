/*
https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

*/

class Solution {
public:
    vector<string> generate(int n) {
        // Code here
        vector<string> ans;
        helper(n, n, "", ans);

        return ans;
    }

    void helper(int openRemain, int closeRemain, string s, vector<string>& ans) {
        if(openRemain < 0) return;
        if(openRemain > closeRemain) return;

        if(openRemain == 0 && closeRemain == 0) {
            ans.push_back(s);
            return;
        }

        helper(openRemain - 1, closeRemain, s + '(', ans);
        helper(openRemain, closeRemain - 1, s + ')', ans);
    }
};

/*
Time    = O(2^N)

Input   : n=3
Output  : ["((()))","(()()"),"(())()","()(())","()()()"]

*/
