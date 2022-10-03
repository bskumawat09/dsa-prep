/*
https://practice.geeksforgeeks.org/problems/remove-invalid-parentheses/1

*/

class Solution {
public:
    void removeParentheses(string s) {
        // Code here
        int mptr = getMinBracketsToRemove(s);  // get minimum parantheses to be removed

        set<string> ds;  // store in set to prevent duplicates
        _remove("", 0, s, mptr, ds);

        vector<string> ans;

        for(auto str : ds) {
            ans.push_back(str);
        }

        return ans;
    }

    void _remove(string asf, int i, string s, int removeCnt, set<string>& ds) {
        if(removeCnt < 0) return;

        if(i == s.length()) {
            if(getMinBracketsToRemove(asf) == 0) {
                ds.insert(asf);
            }
            return;
        }

        char c = s[i];

        _remove(asf, i + 1, s, removeCnt - 1, ds);
        _remove(asf + c, i + 1, s, removeCnt, ds);
    }

    int getMinBracketsToRemove(string s) {
        stack<char> stk;

        for(char c : s) {
            if(c == '(') {
                stk.push(c);
            } else if(c == ')') {
                if(stk.size() == 0 || stk.top() == ')') {
                    stk.push(c);
                } else if(stk.top() == '(') {
                    stk.pop();
                }
            }
        }

        return stk.size();
    }
};

/*
Input:
s = "()())()"

Output:
["(())()","()()()"]

Time    = O(2^N)
Space   = O(N)
*/
