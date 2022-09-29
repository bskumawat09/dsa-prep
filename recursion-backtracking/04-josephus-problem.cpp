/*
https://practice.geeksforgeeks.org/problems/josephus-problem/1

*/

class Solution {
public:
    int josephusProblem(int n, int k) {
        if(n == 1)
            return 0;

        int x = josephusProblem(n - 1, k);
        return (x + k) % n;
    }
};

/*
Input   : n = 7, k = 4
Output  : 1
*/
