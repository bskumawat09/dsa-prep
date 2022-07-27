/*
https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Pair {
public:
    Node* node;
    int state;

    Pair(Node* node, int state) {
        this->node = node;
        this->state = state;
    }
};

class Solution {
public:
    vector<int> postOrderIterative(Node* root) {
        // code here
        vector<int> ans;

        stack<Pair*> stk;
        stk.push(new Pair(root, 1));

        while(stk.size()) {
            Pair* t = stk.top();

            if(t->state == 1) {      // Preorder
                stk.top()->state++;  // Note: t->state++ will not work
                if(t->node->left != NULL) {
                    stk.push(new Pair(t->node->left, 1));
                }
            } else if(t->state == 2) {  // Inorder
                stk.top()->state++;     // Note: t->state++ will not work
                if(t->node->right != NULL) {
                    stk.push(new Pair(t->node->right, 1));
                }
            } else {  // Postorder
                ans.push_back(t->node->data);
                stk.pop();
            }
        }
        return ans;
    }
}