#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDiff = INT_MAX;

    vector<vector<int>> tugOfWar(vector<int>& arr) {
        // Code here
        vector<vector<int>> ans;
        vector<int> s1;
        vector<int> s2;
        helper(0, arr, s1, s2, 0, 0, ans);

        return ans;
    }

    void helper(int i, vector<int>& arr, vector<int>& s1, vector<int>& s2, int sum1, int sum2, vector<vector<int>>& ans) {
        if(i == arr.size()) {
            int delta = abs(sum1 - sum2);

            if(delta < minDiff) {
                minDiff = delta;
                ans.clear();
                ans.push_back(s1);
                ans.push_back(s2);
            }
            return;
        }

        if(s1.size() < (arr.size() + 1) / 2) {  // note this if condition - handles both even & odd size
            s1.push_back(arr[i]);
            helper(i + 1, arr, s1, s2, sum1 + arr[i], sum2, ans);
            s1.pop_back();
        }

        if(s2.size() < (arr.size() + 1) / 2) {
            s2.push_back(arr[i]);
            helper(i + 1, arr, s1, s2, sum1, sum2 + arr[i], ans);
            s2.pop_back();
        }
    }

    void print(vector<vector<int>>& ans) {
        int sum1 = 0;
        for(int it : ans[0]) {
            cout << it << " ";
            sum1 += it;
        }
        cout << "(" << sum1 << ")" << endl;

        int sum2 = 0;
        for(int it : ans[1]) {
            cout << it << " ";
            sum2 += it;
        }
        cout << "(" << sum2 << ")" << endl;
    }
};

int main() {
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};

    Solution sol;
    vector<vector<int>> ans = sol.tugOfWar(arr);
    sol.print(ans);

    return 0;
}

/*
Input:
[23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4]

Output:
23 0 -99 4 189 4 (121)
45 -34 12 98 -1 (120)

*/
