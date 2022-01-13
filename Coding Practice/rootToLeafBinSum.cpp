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
    int binaryToInt(string str)
    {
        cout << str << endl;
        int res = 0, pow2 = 1;
        for(char ch: str)
        {
            res += (pow2*(ch-'0'));
            pow2 *= 2;
        }
        return res;
    }
public:
    int sumRootToLeaf(TreeNode* root, string binStr = "")
    {
        if(root == nullptr)
            return 0;
        int left = 0, right = 0;
        binStr += root->val ? "1" : "0";
        if(root->left == nullptr and root->right == nullptr)
            return binaryToInt(binStr);
        if(root->left)
            left = sumRootToLeaf(root->left, binStr);
        if(root->right)
            right = sumRootToLeaf(root->right, binStr);
        return left+right;
    }
};
class Solution2
{
    int rootToLeaf = 0;
public:
    void preOrder(TreeNode* root, int currNum)
    {
        if(root)
        {
            currNum = (currNum << 1) | root->val;
            if(!root->left and !root->right)
                rootToLeaf += currNum;
            if(root->left)
                preOrder(root->left, currNum);
            if(root->right)
                preOrder(root->right, currNum);
        }
    }
    int sumRootToLeaf(TreeNode* root)
    {
        preOrder(root, 0);
        return rootToLeaf;
    }
};