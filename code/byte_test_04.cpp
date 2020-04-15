#include<bits/stdc++.h>
#define LL long long
#define maxn 100010
#define INF 0x3f3f3f3f
using namespace std;

int opp(vector<int> a, int k, int n);

int main() {
    int t;
    vector<int> a, ans;
    stack<int> st;
    scanf_s("%d", &t);
    while (t--) 
    {
        int n=0;
        scanf_s("%d",&n);
        int temp_a;
        for (int i = 0; i < n; ++i) {
            scanf_s("%d", &temp_a);
            a.push_back(temp_a);
        }
        for (int i = 0; i < n; ++i)
        {
            ans.push_back( opp(a, i,n));
        }
        for (int i = 0; i < n; ++i)
            printf_s("%d ", ans[i]);
        printf("\n");
        a.erase(a.begin(),a.end());
        ans.erase(ans.begin(),ans.end());
    }
    return 0;
}

int opp(vector<int> a, int k,int n) {
    int count = 0;
    vector<int>::iterator p1 =a.begin();
    vector<int>::iterator p2 = a.begin();
    for (int i = 0; i < k; i++)
    {
        p1++; p2++;
    }
    for (int i = 0; i < k;i++)
    {
        if (*(--p1) <= a[k]) {
            count++;
        }
        else {
            break;
        }
    }
    for (int i = 0;i<n-k-1;i++)
    {
        if (*(++p2) <= a[k]&&p2!=a.end()) {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}