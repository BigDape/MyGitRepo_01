//hexoct.cpp -- shows hex anf octal literals
#include <iostream>
int main()
{
	using namespace std;
	int chest = 42;
	int waist = 0x42;
	int instream = 042;

	cout << "Monsieur cuts a striking figures!\n";
	cout << "chest = " << chest << " (42 in decimal)\n";
	cout << "waist = " << waist << "(0x42 in hex)\n";
	cout << "inseam = " << instream << " (042 in octal)\n";

	return 0;
}