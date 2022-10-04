/*
https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

*/

class Solution {
public:
    string findMaximumNum(string str, int k) {
        // Code here
        string ans = "0";
        solve(str, k, ans);

        return ans;
    }

    void solve(string s, int k, string& ans) {
        if(isGreater(s, ans)) {
            ans = s;
        }

        if(k == 0) return;

        for(int i = 0; i < s.length() - 1; i++) {
            for(int j = i + 1; j < s.length(); j++) {
                if(s[i] < s[j]) {
                    swap(s[i], s[j]);
                    solve(s, k - 1, ans);
                    swap(s[i], s[j]);
                }
            }
        }
    }

    bool isGreater(string s1, string s2) {
        int i = 0;

        while(s1[i] == s2[i] && i < s1.length()) {
            i++;
        }

        if(s1[i] > s2[i]) return true;
        return false;
    }
};
