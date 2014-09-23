// 代码来源：http://www.cnblogs.com/TenosDoIt/p/3440542.html
// 比我自己实现的效率高
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> >res;
        if(root == NULL)return res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);//NULL是层与层之间间隔标志
        vector<int> level;
        while(myqueue.empty() == false)
        {
            TreeNode *p = myqueue.front();
            myqueue.pop();
            if(p != NULL)
            {
                level.push_back(p->val);
                if(p->left)myqueue.push(p->left);
                if(p->right)myqueue.push(p->right);
            }
            else
            {
                res.push_back(level);
                if(myqueue.empty() == false)
                {
                    level.clear();
                    myqueue.push(NULL);
                }
            }
        }
        return res;
    }
    // 我的实现
    vector<vector<int> > levelOrder_myself(TreeNode *root) 
	{
		vector<vector<int> > result;
		
		if (root == NULL)
			return result;
		vector<TreeNode*> current;
		vector<TreeNode*> next;
		current.push_back(root);
		while (!current.empty())
		{
			vector<int> tmp;
			for (int i = 0; i < current.size(); i++)
			{
				TreeNode *node = current[i];
				tmp.push_back(node->val);
				if (node->left != NULL)
					next.push_back(node->left);
				if (node->right != NULL)
					next.push_back(node->right);
			}
			result.push_back(tmp);

			// 将next复制给current，清除next
			current.swap(next);
			next.clear();
		}
		return result;
	}
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> >res;
        if(root == NULL)return res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);//NULL是层与层之间间隔标志
        vector<int> level;
        while(myqueue.empty() == false)
        {
            TreeNode *p = myqueue.front();
            myqueue.pop();
            if(p != NULL)
            {
                level.push_back(p->val);
                if(p->left)myqueue.push(p->left);
                if(p->right)myqueue.push(p->right);
            }
            else
            {
                res.push_back(level);
                if(myqueue.empty() == false)
                {
                    level.clear();
                    myqueue.push(NULL);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
