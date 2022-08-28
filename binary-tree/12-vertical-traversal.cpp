/*
 * https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
 *
 * struct Node {
 *     int data;
 *     struct Node* left;
 *     struct Node* right;
 *
 *     Node(int x) {
 *         data = x;
 *         left = right = NULL;
 *     }
 * };
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
    vector<vector<int>> verticalOrder(Node* root) {
        // Code here
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        map<int, vector<int>> mp;
        queue<Pair*> q;
        q.push(new Pair(root, 0));

        while(q.size()) {
            Pair* t = q.front();
            q.pop();

            mp[t->vl].push_back(t->node->data);

            if(t->node->left != NULL)
                q.push(new Pair(t->node->left, t->vl - 1));

            if(t->node->right != NULL)
                q.push(new Pair(t->node->right, t->vl + 1));
        }

        for(auto it : mp) {
            ans.push_back(it);
        }
        return ans;
    }
};

/* -----------Method-2: Using unordered_map (Preffered)----------- */

class Solution2 {
public:
    vector<vector<int>> verticalOrder(Node* root) {
        // Code here
        vector<vector<int>> ans;
        // To print nodes in the desired order, we can have 2 variables denoting min and max vertical levels
        int minVL = 0;
        int maxVL = 0;

        if(root == NULL) return ans;

        unordered_map<int, vector<int>> mp;
        queue<Pair*> q;
        q.push(new Pair(root, 0));

        while(q.size()) {
            Pair* t = q.front();
            q.pop();

            mp[t->vl].push_back(t->node->data);

            if(t->vl < minVL) minVL = t->vl;
            if(t->vl > maxVL) maxVL = t->vl;

            if(t->node->left != NULL)
                q.push(new Pair(t->node->left, t->vl - 1));

            if(t->node->right != NULL)
                q.push(new Pair(t->node->right, t->vl + 1));
        }

        for(int i = minVL; i <= maxVL; i++) {
            for(int x : mp[i])
                ans.push_back(x);
        }
        return ans;
    }
};

/* -----------Method-3: Using width of binary tree & array----------- */

class Solution3 {
private:
    int minVL = INT_MAX;
    int maxVL = INT_MIN;

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
    vector<vector<int>> verticalOrder(Node* root) {
        // Code here
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        int width = widthOfBinaryTree(root);
        ans.resize(width);

        queue<Pair*> q;
        q.push(new Pair(root, abs(minVL)));

        while(q.size()) {
            Pair* p = q.front();
            q.pop();

            ans[p->vl].push_back(p->node->data);

            if(p->node->left != NULL)
                q.push(new Pair(p->node->left, p->vl - 1));

            if(p->node->right != NULL)
                q.push(new Pair(p->node->right, p->vl + 1));
        }

        return ans;
    }
};

/*
Solution-1: Using map
Time    = O(N * logN)
Space   = O(N)

Solution-2: Using unordered_map (Preferred)
Time    = O(N)
Space   = O(N)

Solution-3: Using width & array
Time    = O(N) + O(N) => O(N)
Space   = O(H) + O(2^H) => O(N)
*/
