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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode* > stk;
        while(1)
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            if(stk.empty())
                break;
            root = stk.top();
            res.push_back(root->val);
            stk.pop();
            root = root->right;
        }
        return res;
    }
    vector<int> inorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        while(root)
        {
            if(root->left == nullptr)
            {
                res.push_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode* pred = root->left;
                while(pred->right)
                    pred = pred->right;
                pred->right = root;
                TreeNode* curr = root;
                root = root->left;
                // original curr left be null, avoid infinite loops
                curr->left = nullptr;
            }
        }
        return res;
    }
};