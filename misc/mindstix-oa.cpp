/*
Mindstix OA Round:

There are N type of candies 1,2,3,...,n
Next line contains N integers C1, C2, C3,....,Cn
Ci signifies no. of candies of type 'i'

Alice is allowed eat exactly one candy in a day. And he cannot eat candies of the same type on two consecutive days.
Find out the maximum no. of days, Alice can continue to eat candies.

Input:
N
C1, C2, C3, ..., CN

Testcase-1
Input   : 7, 2, 3
Output  : 11

Testcase-2
Input   : 2,2,2,2
Output  : 8
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    int max = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    sum -= max;

    if(sum >= max) {
        return sum + max;
    } else {
        return 2 * sum + 1;
    }
}

int main() {
    vector<int> arr = {2, 2, 2, 2};

    int ans = solve(arr);
    cout << ans << endl;

    return 0;
}
