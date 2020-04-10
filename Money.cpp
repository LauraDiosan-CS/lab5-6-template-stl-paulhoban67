#include "Money.h"
#include <cstddef>
#include <ostream>
#include <iostream>
using namespace std;

Money::Money()
{
	this->nr = 0;
	this->coin = 0.0;
}

Money::Money(int nr, float coin)
{
	this->nr = nr;
	this->coin = coin;
}

Money::Money(const Money& m)
{
	this->nr = m.nr;
	this->coin = m.coin;
}

Money::~Money()
{
	this->nr = 0;
	this->coin = 0.0;
}

int Money::get_nr()
{
	return this->nr;
}

float Money::get_coin()
{
	return this->coin;
}

void Money::set_nr(int nr)
{
	this->nr = nr;
}

void Money::set_coin(float coin)
{
	this->coin = coin;
}

Money& Money::operator=(const Money& m)
{
	this->set_nr(m.nr);
	this->set_coin(m.coin);
	return *this;
}

bool Money::operator==(const Money& m)
{
	return ((this->nr == m.nr) && (this->coin == m.coin));
}

ostream& operator<<(ostream& os, const Money& m)
{
	os << m.nr << " * " << m.coin << " COINS " << "  => " << m.nr * m.coin<< " RON";
	return os;
}

istream& operator>>(istream& is, Money& m)
{
	is >> m.nr >> m.coin;
	return is;
}


