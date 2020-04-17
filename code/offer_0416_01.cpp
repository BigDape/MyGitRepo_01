#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty()) return false;

        int root = sequence[sequence.size() - 1]; // �ҵ����ڵ�

        // �ڶ������������������Ľ��С�ڸ��ڵ�
        vector<int> leftSequence;
        int i = 0;
        for (i = 0; i < sequence.size() - 1; i++) {
            if (sequence[i] < root)
                leftSequence.push_back(sequence[i]);
            else
                break;
        }

        // �ڶ������������������Ľ����ڸ��ڵ�
        vector<int> rightSequence;
        for (int j = i; j < sequence.size() - 1; j++) {
            if (sequence[j] > root)
                rightSequence.push_back(sequence[j]);
            else
                return false;
        }

        // �����������Ϊ�գ����ж��������Ƿ�����
        bool left = true;
        if (!leftSequence.empty())
            left = VerifySquenceOfBST(leftSequence);
        // �����������Ϊ�գ����ж��������Ƿ�����
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