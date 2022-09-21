/*
https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

*/

class Solution {
public:
    vector<vector<string>> allPalindromicPartition(string s) {
        // Code here
        vector<vector<string>> ans;
        vector<string> partition;

        palindromicPartition(s, partition, ans);

        return ans;
    }

    void palindromicPartition(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if(s.length() == 0) {
            ans.push_back(partition);
            return;
        }

        for(int i = 0; i < s.length(); i++) {
            string prexfix = s.substr(0, i + 1);

            if(isPalindrome(prexfix)) {
                partition.push_back(prefix);
                palindromicPartition(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
