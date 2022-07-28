/*
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = this->right = NULL;
        this->data = data;
    }
};
*/

class Pair {
public:
    Node* node;
    int vl;

    Pair(Node* node, int vl) {
        this->node = node;
        this->vl = vl;
    }
};

class Solution {
private:
    int minVL = INT_MAX;  // min vertical level
    int maxVL = INT_MIN;  // max vertical level

    int widthOfBinaryTree(Node* root) {
        widthHelper(root, 0);
        return maxVL - minVL + 1;
    }

    void widthHelper(Node* node, int vl) {
        if(node == NULL) return;

        if(vl < minVL) minVL = vl;
        if(vl > maxVL) maxVL = vl;

        widthHelper(node->left, vl - 1);
        widthHelper(node->right, vl + 1);
    }

public:
    vector<int> bottomView(Node* root) {
        // code here
        vector<int> ans;

        if(root == NULL) return ans;

        int width = widthOfBinaryTree(root);

        ans.resize(width, -1);

        queue<Pair*> q;
        q.push(new Pair(root, abs(minVL)));

        while(q.size()) {
            Pair* p = q.front();
            q.pop();

            ans[p->vl] = p->node->data;  // override the current values with bottom most values

            if(p->node->left != NULL) q.push(new Pair(p->node->left, p->vl - 1));
            if(p->node->right != NULL) q.push(new Pair(p->node->right, p->vl + 1));
        }

        return ans;
    }
};

/*
Intuition:
Vertically traverse the binary tree and keeps on updating values at corresponding levels.
Let's say we have ans[2] = 5, that means 5 is the "most recent node" (bottom most) encountered at level-2 till now.
Further, if we find Pair(8, 2), it will update {ans[2] = 5} --> {ans[2] = 8}.

Time    = O(N)
Space   = O(N)
*/
