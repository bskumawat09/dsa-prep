/*
https://practice.geeksforgeeks.org/problems/remove-invalid-parentheses/1

*/

class Solution {
public:
    void removeParentheses(string s) {
        // Code here
        int mptr = getMinBracketsToRemove(s);  // get minimum parantheses to be removed

        set<string> ds;  // store in set to prevent duplicates
        _remove("", s, mbtr, ds);

        vector<string> ans;

        for(auto str : ds) {
            ans.push_back(str);
        }

        return ans;
    }

    void _remove(string asf, string s, int cnt, set<string>& ds) {
        if(cnt < 0) return;

        if(s.length() == 0) {
            if(getMinBracketsToRemove(asf) == 0) {
                ds.insert(asf);
            }
            return;
        }

        string ros = s.substr(1);

        _remove(asf, ros, cnt - 1, ds);
        _remove(asf + s[0], ros, cnt, ds);
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
Time    = O(2^N)
Space   = O(N)
*/
