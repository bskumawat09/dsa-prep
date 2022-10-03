/*
https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

*/

class Solution {
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        // Code here
        vector<string> ans;
        solve(s, "", ans, dict);

        return ans;
    }

    void solve(string s, string asf, vector<string>& ans, vector<string>& dict) {
        if(s.length() == 0) {
            asf.pop_back();
            ans.push_back(asf);
            return;
        }

        for(int i = 0; i < s.length(); i++) {
            string left = s.substr(0, i + 1);

            if(find(dict.begin(), dict.end(), left) != dict.end()) {
                string right = s.substr(i + 1);
                solve(right, asf + left + " ", ans, dict);
            }
        }
    }
};

/*
Input:
s = "catsanddog"
dict = ["cats", "cat", "and", "sand", "dog"]

Output:
cats and dog
cat sand dog

*/
