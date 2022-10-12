/*
 Given denominations of currency and amount to pay. Print all different permutations to pay the amount.
 You have infinite supply of each coin.

 Choices: Either we can first pay coins[0] or coins[1] ... or coins[n-1].
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> coinChange(int coins[], int n, int amount) {
        // Code here
        sort(coins, coins + n);

        vector<vector<int>> ans;
        vector<int> asf;

        helper(coins, n, amount, asf, ans);

        return ans;
    }

    void helper(int coins[], int n, int amount, vector<int>& asf, vector<vector<int>>& ans) {
        if(amount == 0) {
            ans.push_back(asf);
            return;
        }

        for(int i = 0; i < n; i++) {
            int c = coins[i];

            if(amount >= c) {
                asf.push_back(c);
                helper(coins, n, amount - c, asf, ans);
                asf.pop_back();
            }
        }
    }
};

int main() {
    int coins[] = {2, 3, 5};
    int amount = 8;
    int n = sizeof(coins) / sizeof(coins[0]);

    Solution sol;
    vector<vector<int>> ans = sol.coinChange(coins, n, amount);

    for(vector<int> v : ans) {
        for(int it : v)
            cout << it << " ";
        cout << endl;
    }
}

/*
 Input:
    coins[] = [2, 3, 5]
    amount = 8

 Output:
    2 2 2 2
    2 3 3
    3 2 3
    3 3 2
    3 5
    5 3

 */
