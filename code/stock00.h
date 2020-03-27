
//stock00.h -- Stock class interface
//version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock//class declaration
{
private:
	std::string company;//公司名称
	long shares;//所持股票数量
	double share_val;//每股价格
	double total_val;//股票总值
	void set_tot() { total_val = shares * share_val; }//更新股票价值
public:
	Stock();
	Stock(const std::string & co,long n = 0,double pr = 0.0);
	~Stock();
	void acquire(const std::string & co,long n,double pr);
	void buy(long num,double price);
	void sell(long num,double price);
	void update(double price);
	void show();
	
};//note semocolon at the end
#endif // !STOCK00_H_
