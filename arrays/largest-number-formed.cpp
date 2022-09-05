/*
https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
*/

class Solution {
public:
    string largestNumber(vector<string>& arr) {
        int n = arr.size();

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                string one = arr[i] + arr[j];
                string two = arr[j] + arr[i];

                if(one < two)  // if there are 10^18 chars in the strings then, it will take 10^18 comparisons
                    swap(arr[i], arr[j]);
            }
        }

        string ans = "";
        for(string s : arr) ans += s;

        return ans;
    }
};

/* -----------Method-2: Using inbuilt sort function----------- */

bool comparator(string s1, string s2) {
    string one = s1 + s2;
    string two = s2 + s1;

    // efficiently compare two numbers represented by string
    int i = 0;
    while(i < one.length()) {
        if(one[i] > two[i])
            return true;
        else if(one[i] < two[i])
            return false;
        i++;
    }

    return false;
}

class Solution2 {
public:
    void largestNumber(vector<string>& arr) {
        sort(arr.begin(), arr.end(), comparator);

        string ans = "";
        for(string s : arr) ans += s;

        return ans;
    }
};

/*
Input   = ["3", "30", "34", "5", "9"]
Output  = 9534330

Solution-1:
Time    = O(N*N)
Space   = O(1)

Solution-2: Using inbuilt sort function (Optimal)
Time    = O(N*logN)
Space   = O(1)
*/
