/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int idx = 0;
    unordered_map<int, int> freq;

    TreeNode* dfs(vector<int>& pre, int l, int r){
        if(l > r) return NULL;
        int root = pre[idx++];

        TreeNode* temp = new TreeNode(root);
        int mid = freq[root];

        temp->left = dfs(pre, l, mid - 1);
        temp->right = dfs(pre, mid + 1, r);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0; i<in.size(); i++) freq[in[i]] = i;

        return dfs(pre, 0, in.size() - 1);
    }
};
