#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void permute(string s, int r) {
        // Code here
        unordered_map<char, bool> hash;
        helper("", s, r, hash);
    }

    void helper(string asf, string s, int r, unordered_map<char, bool>& hash) {
        if(asf.length() == r) {
            cout << asf << endl;
            return;
        }

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];

            if(hash[c] == false) {
                hash[c] = true;
                helper(asf + c, s, r, hash);
                hash[c] = false;
            }
        }
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
 ["ab","ac","ba","bc","ca","cb"]

 */