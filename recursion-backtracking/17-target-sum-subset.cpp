/*
 Given an array and target sum. Print all distinct subsets with sum equal to target sum.
 Each element in array can be used only once.

 Choices: For each element either we pick it or we don't pick it.
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> targetSubsetSum(int arr[], int n, int sum) {
        // Code here
        sort(arr, arr + n);

        vector<vector<int>> ans;
        vector<int> asf;

        helper(0, arr, n, sum, asf, ans);

        return ans;
    }

    void helper(int idx, int arr[], int n, int sum, vector<int>& asf, vector<vector<int>>& ans) {
        if(idx == n) {
            if(sum == 0) {
                ans.push_back(asf);
            }
            return;
        }

        // pick this element
        if(sum >= arr[idx]) {
            asf.push_back(arr[idx]);
            helper(idx + 1, arr, n, sum - arr[idx], asf, ans);
            asf.pop_back();
        }

        // ignore duplicates and jump to next distinct element
        while(idx < n - 1 && arr[idx + 1] == arr[idx])
            idx++;

        // don't pick this element
        helper(idx + 1, arr, n, sum, asf, ans);
    }
};

int main() {
    int arr[] = {2, 3, 5, 1, 3};
    int sum = 8;
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    vector<vector<int>> ans = sol.targetSubsetSum(arr, n, sum);

    for(vector<int> v : ans) {
        for(int it : v)
            cout << it << " ";
        cout << endl;
    }
}

/*

 Input:
    coins[] = [2, 3, 5, 1, 3]
    amount = 8

 Output:
    1 2 5
    2 3 3
    3 5

 */
