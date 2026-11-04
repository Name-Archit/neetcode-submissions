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
public:
    void k_MaxEle(TreeNode* root, vector<int>& ans) {

        if (root == NULL) {
            return;
        }

        ans.push_back(root->val);

        k_MaxEle(root->left, ans);
        k_MaxEle(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;        
        k_MaxEle(root, ans);        

        sort(ans.begin(), ans.end());        
        return ans[k - 1];        
    }
};
