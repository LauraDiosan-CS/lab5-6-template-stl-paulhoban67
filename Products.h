#pragma once
#include <ostream>
using namespace std;

class Products
{
private:
	int id;
	char* code;
	char* name;
	float price;
public:
	Products();
	Products(int id, const char* code, const char* name, float price);
	Products(const Products& p);
	~Products();
	int get_id();
	char* get_code();
	char* get_name();
	float get_price();
	void set_code(const char* code);
	void set_name(const char* name);
	void set_price(float price);
	Products& operator=(const Products& p);
	bool operator==(const Products& p);
	friend ostream& operator<<(ostream& os, const Products& p);
};