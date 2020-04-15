#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
bool opp(vector<int> a,vector<int> b);//函数声明，指的是操作，Yes返回true，No返回false。
int main() 
{
    int t,n;
    vector<int> a;//数列a
    vector<int> b;//数列b
    int k = 0;
    string dd[100];//string对象存储结果
    int temp_in;

    cin >> t;//输入组数t
   for(int k=0;k<t;k++)
   {
        cin >> n;//数列a的长度
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
        a.erase(a.begin(),a.end());//矢量删除元素以及内存
        b.erase(b.begin(),b.end());
   }
    for (int i = 0; i < t; i++)
        cout << dd[i]<<endl;
    return 0;
}

bool opp(vector<int> a, vector<int> b) {
    stack<int> ss;//声明栈
    if (a.size() == 0 || b.size() == 0)
        return false;
    int tt;//存差值的变量
    bool tag = true;//哨兵标记，只记录第一次不同元素的差值
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])//元素相等
        {
            ss.push(a[i]);
        }
        else//元素不相等
        {
            if (tag)//第一次记录差值tt
            {
                tt = b[i] - a[i];
                tag = false;
            }
            if (b[i] == a[i] + tt)//判断后面元素的差值是否等于tt
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