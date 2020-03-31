#include "Products.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

Products::Products()
{
	this->code = NULL;
	this->name = NULL;
	this->price = 0.0;
}

Products::Products(int id, const char* code, const char* name, float price)
{
	this->id = id;
	this->code = new char[strlen(code) + 1];
	strcpy_s(this->code, strlen(code) + 1, code);
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name); 
	this->price = price;
}

Products::Products(const Products& p)
{
	this->id = p.id;
	this->code = new char[strlen(p.code) + 1];
	strcpy_s(this->code, strlen(p.code) + 1, p.code);
	this->name = new char[strlen(p.name) + 1];
	strcpy_s(this->name, strlen(p.name) + 1, p.name);
	this->price = p.price;
}

Products::~Products()
{
	this->id = 0;
	if (this->code != NULL)
	{
		delete[] this->code;
		this->code = NULL;
	}
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
	this->price = 0.0;
}

int Products::get_id()
{
	return this->id;
}

char* Products::get_code()
{
	return this->code;
}

char* Products::get_name()
{
	return this->name;
}

float Products::get_price()
{
	return this->price;
}

void Products::set_code(const char* code)
{
	if (this->code != NULL)
	{
		delete[] this->code;
		this->code = NULL;
	}
	this->code = new char[strlen(code) + 1];
	strcpy_s(this->code, strlen(code) + 1, code);
}

void Products::set_name(const char* name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Products::set_price(float price)
{
	this->price = price;
}

Products& Products::operator=(const Products& p)
{
	this->set_code(p.code);
	this->set_name(p.name);
	this->set_price(p.price);
	return *this;
}

bool Products::operator==(const Products& p)
{
	return ((strcmp(this->code, p.code) == 0) && (strcmp(this->name, p.name) == 0) && (this->price == p.price));
}

ostream& operator<<(ostream& os, const Products& p)
{
	os <<"( "<<p.id<< " ) The product: "<< p.name << "(" << p.code << ") cost " << p.price << " RON\n";
	return os;
}
