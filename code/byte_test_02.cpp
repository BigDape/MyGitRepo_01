#include<iostream>
#include<vector>
#include <iterator>
#include <algorithm>

using namespace std;

int break_number(vector<int> a);
void show(int n) { cout << n<<" "; };

int main()
{
	int n;
	int temp_in;
	vector<int> a;
	

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp_in;
		a.push_back(temp_in);
	}
	cout << break_number(a) << endl;
	return 0;
}

int break_number(vector<int> a)
{
	vector<int>::iterator p = a.begin();
	vector<int> b;
	int count = 0;
	int p_reduce = 0,p_plus;//��¼��������ǰһ��Ԫ�غͺ�һ��Ԫ��
	while (p != (a.end() - 1))
	{
		int x1 = 0, x2 = 0;
		p_plus = *(p + 1);
		if (*p <= p_plus)
		{
			p_reduce = *p;
			p++;
		}
		else if (*p > p_plus)
		{
			x1 = p_plus<p_reduce?p_plus:p_reduce;
			x2 = *p - x1;
			count++;//�۶�һ��
			cout << "�۶�"<<count<<"��"<<endl;
			b.insert(b.begin(), a.begin(),p);
			b.push_back(x1);
			b.push_back(x2);
			b.insert(b.end(), p + 1, a.end());
			for_each(b.begin(),b.end(),show);
			cout << endl;
			a.assign(b.begin(), b.end());
			b.erase(b.begin(),b.end());
			p = a.begin();
		}
	}
	return count;
}