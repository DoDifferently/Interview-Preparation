#include <bits/stdc++.h>
using namespace std;

class binaryNode
{
    int data;
    binaryNode *left, *right;
    public:
        binaryNode(int data): data(data), left(nullptr), right(nullptr) {}
        void setData() { this->data = data; }
        int getData() { return data; }
        void setLeftNode(binaryNode *left) { this->left = left; }
        binaryNode* getLeftNode() { return left; }
        void setRightNode(binaryNode *right) { this->right = right; }
        binaryNode* getRightNode() { return right; }
};

class binaryTree
{
    int m_getDepth(binaryNode* root)
    {
        if(root == nullptr)
            return 0;
        return 1 + max(m_getDepth(root->getLeftNode()), m_getDepth(root->getRightNode()));
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
};

int main(void)
{
    vector<int > levelOrder{1,2,3,4,5,-1,-1,9,-1,-1,7,10,-1,-1,8};
    binaryTree binTree;
    binaryNode* root = binTree.buildTreeFromLevelOrder(levelOrder);
    cout << binTree.getDiameter(root) << endl;
    return 0;
}