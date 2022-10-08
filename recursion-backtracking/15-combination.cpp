#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void permute(string s, int r) {
        // Code here
        helper(0, "", s, r);
    }

    void helper(int idx, string asf, string s, int r) {
        if(idx == s.length()) {
            if(asf.length() == r)
                cout << asf << endl;
            return;
        }

        char c = s[idx];

        helper(idx + 1, asf, s, r);
        helper(idx + 1, asf + c, s, r);
    }
};

int main() {
    string s = "abc";
    int r = 2;

    Solution sol;
    sol.permute(s, r);

    return 0;
}

/*
 Input:
 s = "abc", r = 2

 Output:
 ["bc","ac","ab"]

 */