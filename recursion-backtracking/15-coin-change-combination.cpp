/*
 Given denominations of currency and amount to pay. Print all different combinations to pay the amount.
 You have infinite supply of each coin.

 Choices: For each coin, either we don't use it or we use it (once, twice, thrice ...) for making the change.
 The order in which a payment is made, doen't matter here.
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

        helper(0, coins, n, amount, asf, ans);

        return ans;
    }

    void helper(int idx, int coins[], int n, int amount, vector<int>& asf, vector<vector<int>>& ans) {
        if(idx == n) {
            if(amount == 0) {
                ans.push_back(asf);
            }
            return;
        }

        // take this coin
        if(amount >= coins[idx]) {
            asf.push_back(coins[idx]);
            helper(idx, coins, n, amount - coins[idx], asf, ans);
            asf.pop_back();
        }

        // don't take this coin
        helper(idx + 1, coins, n, amount, asf, ans);
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
    3 5

 */
