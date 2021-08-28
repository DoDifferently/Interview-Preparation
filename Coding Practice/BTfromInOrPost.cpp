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
    int findIdx(int st, int end, int val, vector<int>& inOrder)
    {
        for(int idx = st; idx <= end; ++idx)
            if(inOrder[idx] == val)
                return idx;
        return 0;
    }

    TreeNode* buildBinaryTree(int& idx, int st, int end, vector<int>& postorder, vector<int>& inorder)
    {
        if(st > end)
            return nullptr;
        int curr = postorder[idx--];
        int inIdx = findIdx(st, end, curr, inorder);
        TreeNode* root = new TreeNode(curr);
        root->right = buildBinaryTree(idx, inIdx+1, end, postorder, inorder);
        root->left = buildBinaryTree(idx, st, inIdx-1, postorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int idx = inorder.size()-1;
        return buildBinaryTree(idx, 0, idx, postorder, inorder);
    }
};