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
		//1���ж�A��B�Ƿ�Ϊ��
		if ((pRoot1 == NULL && pRoot2 != NULL) || (pRoot1 != NULL && pRoot2 == NULL))
			return false;
		else if (pRoot1 == NULL && pRoot2 == NULL)
			return false;
		else
		{
			//2���ж�B�ĸ��ڵ��ǲ���A�ĸ��ڵ�
			bool flag = isSubtree(pRoot1,pRoot2);
			if (!flag)//�ݹ�A������������������������û��B�ӽṹ
				flag = HasSubtree(pRoot1->left, pRoot2);
			if (!flag)//ͬ�ϣ��ݹ�A��������
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