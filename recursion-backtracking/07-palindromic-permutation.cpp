#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    void allPalindromicPermutation(string str) {
        // Code here
        map<char, int> fmp;
        for(char c : str) {
            fmp[c]++;
        }

        int oddCnt = 0;     // no. of chars with odd frequency
        string oddCh = "";  // character having odd frequency
        int len = 0;        // length of half string (a2b2 => a1b1)

        for(auto& it : fmp) {  // note "auto& it"
            if(it.second % 2 == 1) {
                oddCh = it.first;
                oddCnt++;
            }
            it.second /= 2;
            len += it.second;
        }

        if(oddCnt > 1) {  // if there are more than one chars with odd frequency
            cout << "No palindromic partition possible" << endl;
            return;
        }

        helper(0, len, fmp, oddCh, "");
    }

    void helper(int i, int len, map<char, int>& fmp, string oddCh, string asf) {
        if(i == len) {
            string pref = asf;
            reverse(asf.begin(), asf.end());
            string ans = pref + oddCh + asf;
            cout << ans << endl;
            return;
        }

        for(auto& it : fmp) {
            if(it.second > 0) {
                it.second--;
                helper(i + 1, len, fmp, oddCh, asf + it.first);
                it.second++;
            }
        }
    }
};

int main() {
    Solution sol;
    string s = "ababccc";
    sol.allPalindromicPermutation(s);

    return 0;
}

/*
Input:
    "ababccc"

Output:
    abcccba
    acbcbca
    bacccab
    bcacacb
    cabcbac
    cbacabc
*/
