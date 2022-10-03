#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int removeMiddle(stack<int>& stk) {
        // Code here
        int len = stk.size();
        int n = len / 2;
        int m = helper(stk, n);

        return m;
    }

    int helper(stack<int>& stk, int n) {
        if(n == 0) {
            int middle = stk.top();
            stk.pop();
            return middle;
        }

        int top = stk.top();
        stk.pop();
        int middle = helper(stk, n - 1);
        stk.push(top);

        return middle;
    }

    void print(stack<int> stk) {
        while(stk.size()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {4, 1, 0, 2, 5, 3};

    stack<int> stk;
    for(int it : arr) {
        stk.push(it);
    }

    Solution sol;
    cout << sol.removeMiddle(stk) << endl;

    sol.print(stk);

    return 0;
}
