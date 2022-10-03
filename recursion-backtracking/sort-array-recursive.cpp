#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort(vector<int>& arr) {
        int len = arr.size();

        if(len == 1) return;  // base condition

        int num = arr[len - 1];
        arr.pop_back();

        sort(arr);

        insert(arr, num);
    }

    void insert(vector<int>& arr, int k) {
        int len = arr.size();

        if(len == 0 || arr[len - 1] <= k) {  // all the elements now onwards are <= "k", it is right place to insert
            arr.push_back(k);
            return;
        }

        int lastNum = arr[len - 1];
        arr.pop_back();

        insert(arr, k);

        arr.push_back(lastNum);
    }

    void print(vector<int> arr) {
        for(int it : arr) {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {4, 1, 0, 2, 5};

    Solution sol;
    sol.sort(arr);

    sol.print(arr);

    return 0;
}

/*

 Induction-Base-Hypothesis (Faith-Expectation)
 Choices & Decision (Euler-tree)

 */
