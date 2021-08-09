#include <bits/stdc++.h>
using namespace std;

class binaryNode
{
    int data;
    binaryNode *left, *right;
    public:
        binaryNode(int data): data(data), left(nullptr), right(nullptr) {}
        void setData(int data) { this->data = data; }
        int getData() { return data; }
        void setLeftNode(binaryNode *left) { this->left = left; }
        binaryNode* getLeftNode() { return left; }
        void setRightNode(binaryNode *right) { this->right = right; }
        binaryNode* getRightNode() { return right; }
};

struct Pair
{
    int incl, excl;
};

class binaryTree
{
    map<binaryNode*, int> hash;
    int m_getDepth(binaryNode* root)
    {
        if(root == nullptr)
            return 0;
        return 1 + max(m_getDepth(root->getLeftNode()), m_getDepth(root->getRightNode()));
    }

    int m_sumOfGrandChildren(binaryNode* node)
    {
        int sum = 0;
        if(node->getLeftNode())
            sum += maxSubsetSum(node->getLeftNode()->getLeftNode()) +
                    maxSubsetSum(node->getLeftNode()->getRightNode());
        if(node->getRightNode())
            sum += maxSubsetSum(node->getRightNode()->getLeftNode()) +
                    maxSubsetSum(node->getRightNode()->getRightNode());
        return sum;
    }

    public:
        void levelOrderPrint(binaryNode* root)
        {
            queue<binaryNode*> que;
            que.push(root);
            que.push(nullptr);
            while(!que.empty())
            {
                binaryNode* curr = que.front();
                if(curr == nullptr)
                {
                    cout << endl;
                    que.pop();
                    if(!que.empty())  // insert a new null for next level
                        que.push(nullptr);
                }
                else
                {
                    que.pop();
                    cout << curr->getData() << " ";
                    if(curr->getLeftNode())
                        que.push(curr->getLeftNode());
                    if(curr->getRightNode())
                        que.push(curr->getRightNode());
                }
            }
            return;
        }
        binaryNode* buildTreeFromLevelOrder(vector<int> arr)
        {
            queue<binaryNode*> que;
            binaryNode* root = new binaryNode(arr[0]);
            que.push(root);
            int idx = 1;
            while(!que.empty() && idx < arr.size())
            {
                binaryNode* curr = que.front();
                que.pop();
                if(arr[idx] != -1)
                {
                    binaryNode* left = new binaryNode(arr[idx]);
                    curr->setLeftNode(left);
                    que.push(left);
                }
                idx++;
                if(arr[idx] != -1)
                {
                    binaryNode* right = new binaryNode(arr[idx]);
                    curr->setRightNode(right);
                    que.push(right);
                }
                idx++;
            }
            return root;
        }

        int getDiameter(binaryNode* root)
        {
            if(root == nullptr)
                return 0;
            int lengthOfDiameterPassedWithRootNode = m_getDepth(root->getLeftNode()) + m_getDepth(root->getRightNode());
            int lengthofLeftDiameter = getDiameter(root->getLeftNode());
            int lengthOfRightDiameter = getDiameter(root->getRightNode());
            return max(lengthOfDiameterPassedWithRootNode, max(lengthofLeftDiameter, lengthOfRightDiameter));
        }

        pair<int, int> getDiameterEfficient(binaryNode* root)
        {
            if(root == nullptr)
                return {0, 0};
            if(root->getLeftNode() == nullptr and root->getRightNode() == nullptr)
                return {1, 0};
            pair<int, int> rightHtDia = getDiameterEfficient(root->getRightNode());
            pair<int, int> leftHtDia = getDiameterEfficient(root->getLeftNode());
            int currDiameter = max(rightHtDia.first + leftHtDia.first, max(rightHtDia.second, leftHtDia.second));
            int currHeight = 1 + max(rightHtDia.first, leftHtDia.first);
            return {currHeight, currDiameter};
        }

        int replaceWithDescendentSum(binaryNode* root)
        {
            if(root == nullptr)
                return 0;
            if(root->getLeftNode() == nullptr and root->getRightNode() == nullptr)
                return root->getData();
            int leftTreeSum = replaceWithDescendentSum(root->getLeftNode());
            int rightTreeSum = replaceWithDescendentSum(root->getRightNode());
            int currNodeData = root->getData();
            root->setData(leftTreeSum + rightTreeSum);
            return leftTreeSum + rightTreeSum + currNodeData;
        }

        pair<bool, int> checkHeightBalancedTree(binaryNode* root)
        {
            if(root == nullptr)
                return {true, 0};
            pair<bool, int> rightSubTree = checkHeightBalancedTree(root->getRightNode());
            pair<bool, int> leftSubTree = checkHeightBalancedTree(root->getLeftNode());
            int currHeightBalanced = leftSubTree.first and rightSubTree.first and abs(leftSubTree.second - rightSubTree.second) <= 1;
            int currHeight = 1 + max(leftSubTree.second, rightSubTree.second);
            return {currHeightBalanced, currHeight};
        }
        
        int maxSubsetSum(binaryNode* root)
        {
            if(root == nullptr)
                return 0;
            if(hash.find(root) != hash.end())
                return hash[root];
            int incl = root->getData() + m_sumOfGrandChildren(root);
            int excl = maxSubsetSum(root->getLeftNode()) + maxSubsetSum(root->getRightNode());
            hash[root] = max(incl, excl);
            return hash[root];
        }

        Pair maxSubsetSum2(binaryNode* root)
        {
            if(root == nullptr)
                return {0, 0};
            Pair left = maxSubsetSum2(root->getLeftNode());
            Pair right = maxSubsetSum2(root->getRightNode());
            return {(root->getData() + left.excl + right.excl),
                    (max(left.excl, left.incl) + max(right.excl, right.incl))};
        }
};

int main(void)
{
    vector<int > levelOrder{1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1};
    binaryTree binTree;
    binaryNode* root = binTree.buildTreeFromLevelOrder(levelOrder);
    cout << binTree.getDiameter(root) << endl;
    pair<int, int> res = binTree.getDiameterEfficient(root);
    cout << "height = " << res.first << "  diameter = " << res.second << endl;
    // binTree.replaceWithDescendentSum(root);
    // binTree.levelOrderPrint(root);
    pair<bool, int> heightBalanced = binTree.checkHeightBalancedTree(root);
    cout << "isHeightBalanced = " << heightBalanced.first << "  height = " << heightBalanced.second << endl;
    cout << "getMaxSubsetSum  = " << binTree.maxSubsetSum(root) << endl;
    Pair maxSum = binTree.maxSubsetSum2(root);
    cout << "getMaxSubsetSum  = " << max(maxSum.incl, maxSum.excl) << endl;
    return 0;
}