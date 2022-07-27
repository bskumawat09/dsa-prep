/*
https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

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
    int vl;  // vertical level

    Pair(Node* node, int vl) {
        this->node = node;
        this->vl = vl;
    }
};

class Solution {
public:
    vector<int> verticalOrder(Node* root) {
        // code here
        vector<int> ans;

        map<int, vector<int>> mp;
        queue<Pair*> q;
        q.push(new Pair(root, 0));

        while(q.size()) {
            Pair* t = q.front();
            q.pop();

            // if "vl" key not present in map
            if(mp.find(t->vl) == mp.end()) {
                vector<int> arr;
                arr.push_back(t->node->data);
                mp[t->vl] = arr;
            } else {
                mp[t->vl].push_back(t->node->data);
            }

            if(t->node->left != nullptr) q.push(new Pair(t->node->left, t->vl - 1));
            if(t->node->right != nullptr) q.push(new Pair(t->node->right, t->vl + 1));
        }

        for(auto it : mp) {
            ans.push_back(it);
        }
        return ans;
    }

    /* ----------Method-2:---------- */
};

/*
Time    = O(N * logN)
Space   = O(2^H) -> O(N)
*/
