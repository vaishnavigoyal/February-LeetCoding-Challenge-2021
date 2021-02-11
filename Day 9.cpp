// Day 9
// Question : Convert BST to Greater Tree

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
public:
	TreeNode *convertBST(TreeNode *root)
	{

		if (root == NULL)
		{
			return NULL;
		}
		TreeNode *temp = root;
		stack<TreeNode *> st;
		int sum = 0;
		while (!st.empty() || root != NULL)
		{
			if (root != NULL)
			{
				st.push(root);
				root = root->right;
			}
			else
			{
				root = st.top();
				st.pop();
				sum += root->val;
				root->val = sum;
				root = root->left;
			}
		}
		return temp;
	}
};