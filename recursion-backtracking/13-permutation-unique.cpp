#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    void permute(string s, int r) {
        // Code here
        map<char, int> fmap;
        for(char c : s) {
            fmap[c]++;
        }

        helper("", r, fmap);
    }

    void helper(string asf, int r, map<char, int>& fmap) {
        if(asf.length() == r) {
            cout << asf << endl;
            return;
        }

        for(pair<const char, int>& it : fmap) {
            char c = it.first;

            if(it.second > 0) {
                it.second--;
                helper(asf + c, r, fmap);
                it.second++;
            }
        }
    }
};

int main() {
    string s = "ababb";
    int r = 3;

    Solution sol;
    sol.permute(s, r);

    return 0;
}

/*
 Input:
 s = "ababb", r = 3

 Output:
 ["aab","aba","abb","baa","bab","bba", "bbb"]

 */