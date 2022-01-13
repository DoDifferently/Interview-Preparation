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
class Solution
{
    map<TreeNode*, int> hash;
    int maxSumGrandChildrens(TreeNode* root)
    {
        int sum = 0;
        if(root->left)
            sum += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            sum += rob(root->right->left) + rob(root->right->right);
        return sum;
    }
public:
    int rob(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        if(hash.find(root) != hash.end())
            return hash[root];
        int res = max(root->val + maxSumGrandChildrens(root), rob(root->left) + rob(root->right));
        return hash[root] = res;
    }
};

class Solution2
{
    struct Pair
    {
        int incl, excl;
    };
    
    Pair maxSum(TreeNode* root)
    {
        if(root == nullptr)
            return {0, 0};
        Pair left = maxSum(root->left);
        Pair right = maxSum(root->right);
        return {root->val + left.excl + right.excl, max(left.incl, left.excl) + max(right.incl, right.excl)};
    }
public:
    int rob(TreeNode* root)
    {
        Pair res = maxSum(root);
        return max(res.incl, res.excl);
    }
};