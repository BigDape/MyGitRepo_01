#include <iostream>
#include <stack>
using namespace std;
class Solution
{	
private:
	stack<int> s;
	stack<int> sMin;
public:
	void push(int value)
	{
		s.push(value);
		if (sMin.empty())
			sMin.push(value);
		else if (sMin.top() >= value)
			sMin.push(value);
	}
	void pop() {
		if (s.top() == sMin.top())
			sMin.pop();
		s.pop();
	}
	int top()
	{
		return s.top();
	}
	int min()
	{
		return sMin.top();
	}

};