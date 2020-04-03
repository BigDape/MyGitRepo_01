#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

template<class T>
void QuickSort(ListNode<T>)

// ʮ����ת������
// �ο�https://www.cnblogs.com/zwjjj/p/9953718.html
string intToA(int n, int radix)    //n�Ǵ�ת���֣�radix��ָ���Ľ���
{
    string ans = "";
    do {
        int t = n % radix;

        if (t >= 0 && t <= 9)
        {
            ans += t + '0';
        }
        else
        {
            ans += t - 10 + 'a';
        }

        n /= radix;
    } while (n != 0);    //ʹ��do{}while�����Է�ֹ����Ϊ0�����
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void)
{

    //cout << (2 | 5) << endl;
    /**************************  һ.��������  **************************/
    int n; // ����ĳ�����
    int x; // �����������
    // ���յ�һ������
    cin >> n;
    cin >> x;
    // �ڶ��������ö�̬�������
    int* array = new int[n];
    // ѭ����������
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    // ��������
    /*for (int i = 0; i < n; i++)
    {
     cout << array[i] << " ";
    }
    cout << endl;*/
    long start = clock();  //��ʼʱ��
    /**************************  ��.�ҵ�����  **************************/
    // 1. ������ܵ�����
    sort(array, array + n);

    // 2. �ڴ�С����������������ҳ����ִ�����������
    int num[100000] = { 0 }; // ��¼���ֵĴ�������������100000
    for (int i = 0; i < n; i++)
    {
        num[array[i]]++;
    }
    // 3. �ҵ��������Ԫ�ص��±�
    int maxPosition = max_element(num, num + 100000) - num;
    // maxPosition ���õ���������±꣬num[maxPosition]�ŵ��ǳ����������ֵĴ���
    int mode = maxPosition; // �������ǳ��ִ�������
    int cnt = 0; // ͳ�Ƴ��������ĸ��� 
    //cout << mode << " mode" << endl;
    for (int i = 0; i < n; i++)
    {
        if ((x | array[i]) == mode)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    // �ͷŶ�̬����
    delete[]array;
    long finish = clock();  //����ʱ��
    cout << "ʱ�䣺" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
    system("pause");
    return 0;
}