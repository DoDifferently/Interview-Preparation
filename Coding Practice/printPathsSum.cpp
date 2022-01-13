/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
    vector<vector<int>> res;

    void findPath(TreeNode* curr, int sum, int sum_so_far, vector<int>& path)
    {
        if (curr == nullptr)
            return;
        sum_so_far += curr->val;
        path.push_back(curr->val);
        if (sum_so_far == sum and !curr->left and !curr->right)
            res.push_back(path);
        if (curr->left)
            findPath(curr->left, sum, sum_so_far, path);
        if (curr->right)
            findPath(curr->right, sum, sum_so_far, path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path;
        findPath(root, targetSum, 0, path);
        return res;
    }
};