#include <bits/stdc++.h>
using namespace std;

/*
Given 'N' numbers, partition them into 'K' subarrays.
Print all possible partitons of size 'K' such that no partion should be empty.
*/

class Solution {
public:
    void kPartitions(int n, int k) {
        // Code here
        vector<vector<int>> partition(k);
        _kPartitions(1, n, k, partition, 0);
    }

private:
    void _kPartitions(int i, int n, int k, vector<vector<int>>& partition, int numOfSetsFilled) {
        if(i > n) {
            if(numOfSetsFilled == k) {
                printPartition(partition);
            }
            return;
        }

        for(int j = 0; j < partition.size(); j++) {  // iterate over k-sets of partition
            if(partition[j].size()) {                // if set has some element
                partition[j].push_back(i);
                _kPartitions(i + 1, n, k, partition, numOfSetsFilled);
                partition[j].pop_back();
            } else {  // if set is empty, then fill it and break to ensure that only first empty set is filled
                partition[j].push_back(i);
                _kPartitions(i + 1, n, k, partition, numOfSetsFilled + 1);
                partition[j].pop_back();
                break;
            }
        }
    }

    // print valid partition
    void printPartition(vector<vector<int>>& partition) {
        for(vector<int> set : partition) {
            cout << "[";
            for(int i = 0; i < set.size(); i++) {
                cout << set[i] << (i == set.size() - 1 ? "" : ",");
            }
            cout << "]";
        }
        cout << endl;
    }
};

/*
class Solution2 {
public:
    vector<vector<string>> kPartitions(int n, int k) {
        vector<vector<string>> ans;

        if(k == 1) {
            vector<string> part;
            string str = "";
            for(int i = 1; i <= n; i++) {
                str += to_string(i);
            }
            part.push_back(str);
            ans.push_back(part);
            return ans;
        }

        if(n == k) {
            for(int i = 1; i <= n; i++) {
                vector<string> part;
                part.push_back(to_string(i));
                ans.push_back(part);
            }
            return ans;
        }

        vector<vector<string>> a = kPartitions(n - 1, k - 1);  // [[1-23], [12-3], [13-2]]
        vector<vector<string>> b = kPartitions(n - 1, k);      // [[1-2-3]]

        for(int i = 0; i < a.size(); i++) {
            a[i].push_back(to_string(n));
            ans.push_back(a[i]);
        }

        for(int i = 0; i < b.size(); i++) {
            for(int j = 0; j < k; j++) {
                vector<string> part = b[i];
                part[j] += to_string(n);
                ans.push_back(part);
            }
        }

        return ans;
    }

    void printResult(vector<vector<string>>& ans) {
        for(int i = 0; i < ans.size(); i++) {
            cout << "#" << i << ":\n";
            for(int j = 0; j < ans[i].size(); j++) {
                cout << "( " << ans[i][j] << " )";
            }
            cout << endl;
        }
    }
};
*/

int main() {
    int n = 4, k = 3;

    Solution sol;
    sol.kPartitions(n, k);

    return 0;
}

/*
Input:
n = 4, k = 3

Output:
[1,2][3][4]
[1,3][2][4]
[1][2,3][4]
[1,4][2][3]
[1][2,4][3]
[1][2][3,4]

*/
