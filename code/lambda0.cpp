//lambda.cpp -- lambda expressions
//功能：随机生成一个随机整数列表，并判断其中多少个整数可以被3整除，多少个整数可被13整除。
#include <iostream>
#include <vector>
#include <algorithm>//使用count_if
#include <cmath>
#include <ctime>
const long Size1 = 39L;//加L是进行预处理，告诉编译器这个数是long型的。
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;
bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main()
{
	using std::cout;
	std::vector<int> numbers(Size1);

	std::srand(std::time(0));
	std::generate(numbers.begin(), numbers.end(), std::rand);

	//using function pointers
	cout << "Sample size" << Size1 << "\n";

	int count3 = std::count_if(numbers.begin(),numbers.end(),f3);
	cout << "Count of numbers divisible by 3:" << count3 << '\n';
	int count13 = std::count_if(numbers.begin(),numbers.end(),f13);
	cout << "Count of numbers divisible by 13:" << count13 << "\n\n";

	//increase number of numbers
	numbers.resize(Size2);
	std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "Sample size = " << Size2 << "\n";
	//using a functor
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d=1):dv(d){}
		bool operator()(int x) { return x % dv == 0; }
	};

	count3 = std::count_if(numbers.begin(),numbers.end(),f_mod(3));
	cout << "Cout of numbers divisible by 3:" << count3 << "\n";
	count13 = std::count_if(numbers.begin(),numbers.end(),f_mod(13));
	cout << "Count of numbers divisible by 13:" << count13 << "\n\n";

	//increase number of numbers again
	numbers.resize(Size3);
	std::generate(numbers.begin(),numbers.end(),std::rand);
	cout << "Sample size=" << Size3 << '\n';
	//using lambds
	count3 = std::count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << "Count of numbers divisible by 3:" << count3 << "\n";
	count13 = std::count_if(numbers.begin(), numbers.end(), [](int x) {return x % 13 == 0; });
	cout << "Count of numbers divisible by 13:" << count13 << "\n";
	return 0;
}