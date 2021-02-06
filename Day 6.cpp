// Day 6
// Question : Binary Tree Right Side View

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cur=1,nex=0;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(cur==1)
            {
                res.push_back(node->val);
            }
            cur--;
            if(node->left)
            {
                q.push(node->left);
                nex++;
            }
            if(node->right)
            {
                q.push(node->right);
                nex++;
            }
            if(cur==0)
            {
                cur=nex;
                nex=0;
            }
        }
        return res;
    }
};