#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
bool opp(vector<int> a,vector<int> b);//����������ָ���ǲ�����Yes����true��No����false��
int main() 
{
    int t,n;
    vector<int> a;//����a
    vector<int> b;//����b
    int k = 0;
    string dd[100];//string����洢���
    int temp_in;

    cin >> t;//��������t
   for(int k=0;k<t;k++)
   {
        cin >> n;//����a�ĳ���
        for (int i = 0; i < n; i++)
        {
            cin >> temp_in;
            a.push_back(temp_in);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp_in;
            b.push_back(temp_in);
        }
        if (opp(a, b)==true)
            dd[k] = "YES";
        else
            dd[k] = "NO";
        a.erase(a.begin(),a.end());//ʸ��ɾ��Ԫ���Լ��ڴ�
        b.erase(b.begin(),b.end());
   }
    for (int i = 0; i < t; i++)
        cout << dd[i]<<endl;
    return 0;
}

bool opp(vector<int> a, vector<int> b) {
    stack<int> ss;//����ջ
    if (a.size() == 0 || b.size() == 0)
        return false;
    int tt;//���ֵ�ı���
    bool tag = true;//�ڱ���ǣ�ֻ��¼��һ�β�ͬԪ�صĲ�ֵ
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])//Ԫ�����
        {
            ss.push(a[i]);
        }
        else//Ԫ�ز����
        {
            if (tag)//��һ�μ�¼��ֵtt
            {
                tt = b[i] - a[i];
                tag = false;
            }
            if (b[i] == a[i] + tt)//�жϺ���Ԫ�صĲ�ֵ�Ƿ����tt
            {
                ss.push(a[i]);
            }
        }
    }
    if (ss.size() == a.size())
        return true;
    else
        return false;
}