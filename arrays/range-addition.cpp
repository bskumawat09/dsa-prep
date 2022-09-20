#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rangeSum(int n, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<int> pfSum(n + 1, 0);

        for(int i = 0; i < q; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];

            pfSum[start] += val;  // add impact from 'start' index
            if(end < n - 1)
                pfSum[end + 1] -= val;  // cancel impact from 'end+1' index
        }

        for(int i = 1; i < n; i++) {
            pfSum[i] = pfSum[i] + pfSum[i - 1];
        }

        return pfSum;
    }
};

/*
Input:
6 => length of array
4 => no. of queries
0 2 -3 => (start, end, value)
4 5 2
1 3 4
2 4 3

Output:
-3 1 4 7 5 2

Time    = O(N) + O(Q)
Space   = O(N)
*/
