#include "Tests.h"
#include "Products.h"
#include "Money.h"
#include <string.h>
#include <cassert>
#include <iostream>

void add()
{
	char* code1 = new char[10];
	char* code2 = new char[10];
	char* name1 = new char[20];
	char* name2 = new char[20];
	strcpy_s(code1, strlen("GG55") + 1, "GG55");
	strcpy_s(code2, strlen("HH67") + 1, "HH67");
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	Products p1(1, code1, name1, 2.3);
	Products p2(2, code2, name2, 3.3);
	assert(p1.get_price() != 2.3);
	assert(p2.get_id() == 2);
	assert(strcmp(p1.get_code(), "GG55") == 0);
	assert(strcmp(p1.get_name(), "Croissant") == 0);
}

void set()
{
	char* code1 = new char[10];
	char* code2 = new char[10];
	char* name1 = new char[20];
	char* name2 = new char[20];
	strcpy_s(code1, strlen("GG55") + 1, "GG55");
	strcpy_s(code2, strlen("HH67") + 1, "HH67");
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	Products p1(1, code1, name1, 2.3);
	Products p2(2, code2, name2, 3.3);
	p1.set_price(3.3);
	p2.set_code(code1);
	p2.set_name(name1);
	p2.set_price(12.2);
	assert(p1.get_price() != 3.3);
	assert(strcmp(p2.get_code(), code1) == 0);
	assert(strcmp(p2.get_name(), name1) == 0);
	assert(p2.get_price() != 12.2);
}

void test_products()
{
	add();
	set();
}

int same_float(float f1, float f2)
{
	float epsilon = 0.0001;
	if (abs(f1 - f2) < epsilon)
		return 1;
	else
		return 0;
}

void add1()
{
	int nr1 = 1;
	int nr2 = 4;
	int nr3 = 3;
	float coin1 = 0.05;
	float coin2 = 10.00;
	float coin3 = 0.50;
	Money m1(nr1, coin1);
	Money m2(nr2, coin2);
	Money m3(nr3, coin3);
	assert(same_float(m1.get_coin(), 0.05));
	assert(same_float(m2.get_coin(), 10.00));
	assert(m3.get_nr() == 3);
	assert(m1.get_nr() == 1);
}

void set1()
{
	int nr1 = 1;
	int nr2 = 4;
	int nr3 = 3;
	float coin1 = 0.05;
	float coin2 = 10.00;
	float coin3 = 0.50;
	Money m1(nr1, coin1);
	Money m2(nr2, coin2);
	Money m3(nr3, coin3);
	m1.set_coin(1.00);
	m2.set_nr(3);
	m3.set_coin(5.00);
	assert(same_float(m1.get_coin(), 1.00));
	assert(m2.get_nr() == 3);
	assert(same_float(m3.get_coin(), 5.00));
}

void test_money()
{
	add1();
	set1();
}