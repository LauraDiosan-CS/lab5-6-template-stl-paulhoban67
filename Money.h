#pragma once
#include <ostream>
#include <istream>
using namespace std;

class Money
{
private:
	int nr;
	float coin;
public:
	
	Money();
	Money(int nr, float coin);
	Money(const Money& m);
	~Money();

	int get_nr();
	float get_coin();
	void set_nr(int nr);
	void set_coin(float coin);

	Money& operator=(const Money& m);
	bool operator==(const Money& m);
	friend ostream& operator<<(ostream& os, const Money& m);
	friend istream& operator>>(istream& is, Money& m);
};