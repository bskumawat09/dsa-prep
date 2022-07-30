/*
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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
    int minVL = 0;  // min vertical level
    int maxVL = 0;  // max vertical level

    void widthHelper(Node* node, int vl) {
        if(node == NULL) return;

        if(vl < minVL) minVL = vl;
        if(vl > maxVL) maxVL = vl;

        widthHelper(node->left, vl - 1);
        widthHelper(node->right, vl + 1);
    }

public:
    vector<int> topView(Node* root) {
        // Code here
        vector<int> ans;

        if(root == NULL) return ans;

        widthHelper(root, 0);
        int width = maxVL - minVL + 1;

        ans.resize(width, -1);

        queue<Pair*> q;
        q.push(new Pair(root, abs(minVL)));

        while(q.size()) {
            Pair* p = q.front();
            q.pop();

            if(ans[p->vl] == -1)
                ans[p->vl] = p->node->data;

            if(p->node->left != NULL)
                q.push(new Pair(p->node->left, p->vl - 1));

            if(p->node->right != NULL)
                q.push(new Pair(p->node->right, p->vl + 1));
        }

        return ans;
    }
};

/*
Intuition:
Vertically traverse the binary tree and store the first value occuring at every level.

Time    = O(N)
Space   = O(N)
*/
