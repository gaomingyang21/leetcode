/*
* Given a binary tree, find its minimum depth.
* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
* from: https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 递归解法
    int minDepth(TreeNode *root) {
       if (root == NULL)
			return 0;
		//int min = 1;
		int lmin = INT_MAX;
		int rmin = INT_MAX;
		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}
		if (root->left != NULL)
		{
			lmin = minDepth(root->left);
		}
		if (root->right != NULL)
		{
			rmin = minDepth(root->right);
		}
		return min(lmin, rmin) + 1;
    }
    
    // 非递归实现
	int minDepth1(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int level = 1;
		queue<TreeNode*> current;
		queue<int> counts;
		current.push(root);
		counts.push(1);
		while (!current.empty())
		{
			TreeNode* node = current.front();
			current.pop();
			int count = counts.front();
			counts.pop();
			if (node->left == NULL && node->right == NULL)
			{
				return count;
			}
			if (node->left != NULL)
			{ 
				current.push(node->left);
				counts.push(count + 1);
			}
			if (node->right != NULL)
			{
				current.push(node->right);
				counts.push(count + 1);
			}
		}
		return 0;
	}
};
