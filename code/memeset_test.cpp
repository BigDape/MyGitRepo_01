#include<iostream>
//#include"string.h"
using namespace std;
int main()
{
    char str[10];
    str[9] = 'w';
    memset(str, 97, 9);
    for (int i = 0; i < 10; i++) {
        cout << str[i] << " ";
    }
    return 0;
}