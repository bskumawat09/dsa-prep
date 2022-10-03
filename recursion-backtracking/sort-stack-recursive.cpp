#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void sort(stack<int>& stk) {
        int len = stk.size();
        if(len == 1) return;

        int num = stk.top();
        stk.pop();

        sort(stk);
        insert(stk, num);
    }

    void insert(stack<int>& stk, int k) {
        int len = stk.size();
        if(len == 0 || stk.top() <= k) {
            stk.push(k);
            return;
        }

        int top = stk.top();
        stk.pop();
        insert(stk, k);
        stk.push(top);
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
    vector<int> arr = {4, 1, 0, 2, 5};

    stack<int> stk;
    for(int it : arr) {
        stk.push(it);
    }

    Solution sol;
    sol.sort(stk);

    sol.print(stk);

    return 0;
}

/*

 Induction-Base-Hypothesis (Faith-Expectation)
 Choices & Decision (Euler-tree)

 */
