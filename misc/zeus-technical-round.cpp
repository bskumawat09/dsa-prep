/*
Zeus Learning Technical Interview:

Given array of integers.
If elements are in AP print 'A'
If elements are in GP print 'G'
If elements are in both AP and GP print 'Z'
Otherwise print 'N'
*/

#include <bits/stdc++.h>
using namespace std;

char solve(vector<int> arr) {
    int d = arr[1] - arr[0];
    double r = double(arr[1]) / arr[0];

    bool inAP = true;
    bool inGP = true;

    for(int i = 2; i < arr.size(); i++) {
        if(arr[i] - arr[i - 1] != d) {
            inAP = false;
        }

        if((double(arr[i]) / arr[i - 1]) != r) {
            inGP = false;
        }
    }

    if(inAP && inGP) return 'Z';
    if(inAP) return 'A';
    if(inGP) return 'G';

    return 'N';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        char ans = solve(arr);
        cout << ans << endl;
    }

    return 0;
}
