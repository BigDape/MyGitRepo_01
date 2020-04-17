#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty()) return false;

        int root = sequence[sequence.size() - 1]; // 找到根节点

        // 在二叉搜索树中左子树的结点小于根节点
        vector<int> leftSequence;
        int i = 0;
        for (i = 0; i < sequence.size() - 1; i++) {
            if (sequence[i] < root)
                leftSequence.push_back(sequence[i]);
            else
                break;
        }

        // 在二叉搜索树中右子树的结点大于根节点
        vector<int> rightSequence;
        for (int j = i; j < sequence.size() - 1; j++) {
            if (sequence[j] > root)
                rightSequence.push_back(sequence[j]);
            else
                return false;
        }

        // 如果左子树不为空，则判断左子树是否满足
        bool left = true;
        if (!leftSequence.empty())
            left = VerifySquenceOfBST(leftSequence);
        // 如果右子树不为空，则判断右子树是否满足
        bool right = true;
        if (!rightSequence.empty())
            right = VerifySquenceOfBST(rightSequence);

        return (left && right);
    }
};
int main()
{
    Solution s;
    vector<int> sequence;
    int b;
    while (cin>>b) {
        sequence.push_back(b);
        if (cin.get() == '\n') break;
    }
    if (s.VerifySquenceOfBST(sequence)) {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}