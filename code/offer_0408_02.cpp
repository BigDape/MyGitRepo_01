#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//1、判断A、B是否为空
		if ((pRoot1 == NULL && pRoot2 != NULL) || (pRoot1 != NULL && pRoot2 == NULL))
			return false;
		else if (pRoot1 == NULL && pRoot2 == NULL)
			return false;
		else
		{
			//2、判断B的根节点是不是A的根节点
			bool flag = isSubtree(pRoot1,pRoot2);
			if (!flag)//递归A的左子树，看看做子树中有没有B子结构
				flag = HasSubtree(pRoot1->left, pRoot2);
			if (!flag)//同上，递归A的右子树
				flag = HasSubtree(pRoot1->right, pRoot2);
			return flag;
		}
	}
	bool isSubtree(TreeNode * p1, TreeNode * p2) 
	{
		if (!p2)
			return true;
		if (!p1)
			return false;
		if (p1->val != p2->val)
			return false;
		return isSubtree(p1->left, p2->left) && isSubtree(p1->right, p2->right);
	}
};