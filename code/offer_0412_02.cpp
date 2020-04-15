/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹ
ջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> temp;
        for (int i = 0,j=0; i < pushV.size(); i++)
        {
            temp.push(pushV[i]);
            while (j < popV.size())
            {
                if (temp.top() == popV[j])
                {
                    temp.pop();
                    j++;
                }
            }
        }
        if (temp.empty())
            return true;
        else
            return false;
    }
};