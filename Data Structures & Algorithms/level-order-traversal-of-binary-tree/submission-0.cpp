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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       if(root == NULL) return ans;

       queue<TreeNode*> prior;
       prior.push(root);

       while(!prior.empty()){
        int size = prior.size();
        vector<int> temp;

        for(int i=0; i<size; i++){
            TreeNode* dummyTree = prior.front();
            prior.pop();

            if(dummyTree->left != NULL) prior.push(dummyTree->left);
            if(dummyTree->right != NULL) prior.push(dummyTree->right);

            temp.push_back(dummyTree->val);
        }

        ans.push_back(temp);

       }


       return ans;


    }
};
