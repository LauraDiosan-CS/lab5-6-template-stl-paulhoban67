#include "Test_Service.h"
#include <cassert> 

Test_Service::Test_Service()
{

}

void Test_Service::add_product()
{
	Service service(Repo <Products> repo_products2, Repo <Money> repo_money2);

	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 4.0);

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");
	Products p2(2, code2, name2, 5.0);

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");
	Products p3(3, code3, name3, 11.0);

	this->service.add_product(code1, name1, 4.0);
	this->service.add_product(code2, name2, 5.0);
	this->service.add_product(code3, name3, 11.0);

	assert(this->service.show_product()[0] == p1);
	assert(this->service.show_product()[1] == p2);
	assert(this->service.show_product()[2] == p3);
}

void Test_Service::update_product()
{
	Service service(Repo <Products> repo_products2, Repo <Money> repo_money2);

	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 4.0);

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");
	Products p2(2, code2, name2, 5.0);

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");
	Products p3(3, code3, name3, 11.0);

	this->service.add_product(code1, name1, 4.0);
	this->service.add_product(code2, name2, 5.0);
	this->service.add_product(code3, name3, 11.0);
	this->service.update_product(2, code3, name3, 11.0);

	assert(this->service.show_product()[0] == p1);
	assert(this->service.show_product()[1] == p3);
}

void Test_Service::delete_product()
{
	Service service(Repo <Products> repo_products2, Repo <Money> repo_money2);

	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 4.0);

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");
	Products p2(2, code2, name2, 5.0);

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");
	Products p3(3, code3, name3, 11.0);

	this->service.add_product(code1, name1, 4.0);
	this->service.add_product(code2, name2, 5.0);
	this->service.add_product(code3, name3, 11.0);
	this->service.delete_product(2);

	assert(this->service.show_product()[0] == p1);
	assert(this->service.show_product()[1] == p3);
}

void Test_Service::get_product()
{
	Service service(Repo <Products> repo_products2, Repo <Money> repo_money2);

	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 4.0);

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");
	Products p2(2, code2, name2, 5.0);

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");
	Products p3(3, code3, name3, 11.0);

	assert(this->service.get_product(2) == p1);//
	assert(this->service.get_product(3) == p2);//
	assert(this->service.get_product(4) == p3);//
}

void Test_Service::get_sum_tonomate()
{
	Money m1(4, 0.50);
	Money m2(10, 0.10);
	Money m3(20, 0.05);
	this->service.add_money(4, 0.50);
	this->service.add_money(10, 0.10);
	this->service.add_money(20, 0.05);

	assert(this->service.sum_tonomate() == 4.00);
}

void Test_Service::rest()
{
	this->service.add_money(6, 0.50);
	this->service.add_money(10, 0.10);
	this->service.add_money(20, 0.05);

	assert(this->service.rest(5, 1) == 1);
}

void Test_Service::delete_rest()
{
	this->service.add_money(6, 0.50);
	this->service.add_money(10, 0.10);
	this->service.add_money(20, 0.05);

	assert(this->service.delete_money_tonomate(4) == 1);
}

void Test_Service::get_sum_coin()
{
	this->service.add_money(6, 0.50);

	assert(this->service.get_sum_coin(6, 0.50) == 3.0);
}

void Test_Service::verify_sum()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 1.0);

	this->service.add_money(6, 0.50);
	this->service.add_money(10, 0.10);
	this->service.add_money(20, 0.05);

	assert(this->service.verify_sum(code1, 1, 5.0) == 0);
}

void Test_Service::how_much()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 1.0);

	this->service.add_money(6, 0.50);
	this->service.add_money(10, 0.10);
	this->service.add_money(20, 0.05);

	assert(this->service.how_much(code1, 1, 5.0) == -1);//
}

void Test_Service::test_main2()
{
	this->add_product();
	this->update_product();
	this->delete_product();
	this->get_product();
	this->get_sum_tonomate();
	this->rest();
	this->delete_rest();
	this->get_sum_coin();
	this->verify_sum();
	this->how_much();
}
