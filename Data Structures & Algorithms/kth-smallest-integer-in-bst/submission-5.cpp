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
    void k_MaxEle(TreeNode* root, vector<int>& ans, int k, int& count) {

        if (root == NULL) {
            return;
        }

        if(count == k) return;     

        k_MaxEle(root->left, ans, k, count);
        if(count == k) return; 
        ans.push_back(root->val);

        count++;          

        k_MaxEle(root->right, ans, k, count);        
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        int count = 0;

        k_MaxEle(root, ans, k, count);
        
        int n = ans.size();

        return ans[n - 1];        
    }
};
