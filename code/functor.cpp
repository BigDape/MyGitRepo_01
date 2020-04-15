//functor.cpp -- using  a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T> //functor class defines operator()()
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {};
	bool operator()(const T& v) { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }
int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);//limit = 100
	int vals[10] = { 500,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals,vals+10);//range constructor
	list<int> etcetcra(vals,vals+10);
	//C++11 can use the following instead
	//list<int> yadayada = {50,100,90,180,60,210,415,8,188,201};
	//list<int> etcetera {50,100,90,180,60,210,415,88,188,201}
	cout << "Orginal lists:\n";
	for_each(yadayada.begin(),yadayada.end(),outint);
	cout << endl;
	for_each(etcetcra.begin(),etcetcra.end(),outint);
	cout << endl;
	yadayada.remove_if(f100);
	etcetcra.remove_if(TooBig<int>(200));
	cout << "Trimmed list:\n";
	for_each(yadayada.begin(),yadayada.end(),outint);
	cout << endl;
	for_each(etcetcra.begin(),etcetcra.end(),outint);
	cout << endl;
	return 0;
}

