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

// 十进制转二进制
// 参考https://www.cnblogs.com/zwjjj/p/9953718.html
string intToA(int n, int radix)    //n是待转数字，radix是指定的进制
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
    } while (n != 0);    //使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void)
{

    //cout << (2 | 5) << endl;
    /**************************  一.接受数据  **************************/
    int n; // 输入的长度与
    int x; // 输入的正整数
    // 接收第一行输入
    cin >> n;
    cin >> x;
    // 第二行输入用动态数组接收
    int* array = new int[n];
    // 循坏接收序列
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    // 测试输入
    /*for (int i = 0; i < n; i++)
    {
     cout << array[i] << " ";
    }
    cout << endl;*/
    long start = clock();  //开始时间
    /**************************  二.找到众数  **************************/
    // 1. 排序接受的数组
    sort(array, array + n);

    // 2. 在从小到大排序的数组中找出出现次数最多的数字
    int num[100000] = { 0 }; // 记录出现的次数，最大的数是100000
    for (int i = 0; i < n; i++)
    {
        num[array[i]]++;
    }
    // 3. 找到数字最大元素的下标
    int maxPosition = max_element(num, num + 100000) - num;
    // maxPosition 放置的最大数的下标，num[maxPosition]放的是出现最多的数字的次数
    int mode = maxPosition; // 众数就是出现次数最多的
    int cnt = 0; // 统计出现众数的个数 
    //cout << mode << " mode" << endl;
    for (int i = 0; i < n; i++)
    {
        if ((x | array[i]) == mode)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    // 释放动态数组
    delete[]array;
    long finish = clock();  //结束时间
    cout << "时间：" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
    system("pause");
    return 0;
}