#include "Tets_Repo.h"
#include <cassert>
#include <iostream>
using namespace std;
Test_Repo_Products::Test_Repo_Products()
{
	
}

void Test_Repo_Products::test_add()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");

	Products p1(1, code1, name1, 4.0);
	Products p2(2, code2, name2, 5.0);
	Products p3(3, code3, name3, 11.0);

	this->repo_products1.add_element(p1);
	this->repo_products1.add_element(p2);
	this->repo_products1.add_element(p3);

	assert(this->repo_products1.get_size() == 3);
	assert(this->repo_products1.get_element(1) == p2);
	assert(this->repo_products1.get_element(0) == p1);
	assert(this->repo_products1.get_element(2) == p3);
}

void Test_Repo_Products::test_delete()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");

	Products p1(1, code1, name1, 4.0);
	Products p2(2, code2, name2, 5.0);
	Products p3(3, code3, name3, 11.0);

	this->repo_products1.add_element(p1);
	this->repo_products1.add_element(p2);
	this->repo_products1.add_element(p3);
	this->repo_products1.del_element(p2);

	assert(this->repo_products1.get_size() == 2);
	assert(this->repo_products1.get_element(0) == p1);
	assert(this->repo_products1.get_element(1) == p3);
}

void Test_Repo_Products::test_update()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");
	
	char* name_update = new char[strlen("Kinder") + 1];
	strcpy_s(name_update, strlen("Kinder") + 1, "Kinder");
	char* code_update = new char[strlen("PP99") + 1];
	strcpy_s(code_update, strlen("PP99") + 1, "PP99");

	Products p1(1, code1, name1, 4.0);
	Products p2(2, code2, name2, 5.0);
	Products p3(3, code3, name3, 11.0);
	Products p4_update(4, code_update, name_update, 20.0);

	this->repo_products1.add_element(p1);
	this->repo_products1.add_element(p2);
	this->repo_products1.add_element(p3);
	this->repo_products1.update_element(p2, p4_update);

	assert(this->repo_products1.get_size() == 3);
	assert(this->repo_products1.get_element(1) == p4_update);
}

void Test_Repo_Products::test_show()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");

	Products p1(1, code1, name1, 4.0);
	Products p2(2, code2, name2, 5.0);
	Products p3(3, code3, name3, 11.0);

	this->repo_products1.add_element(p1);
	this->repo_products1.add_element(p2);
	this->repo_products1.add_element(p3);

	assert(this->repo_products1.get_size() == 3);
	assert(this->repo_products1.show_elements()[0] == p1);
	assert(this->repo_products1.show_elements()[1] == p2);
	assert(this->repo_products1.show_elements()[2] == p3);
}

void Test_Repo_Products::test_main1()
{
	this->test_add();
	this->repo_products1.clear();
	this->test_delete();
	this->repo_products1.clear();
	this->test_show();
	this->repo_products1.clear();
	this->test_update();
	this->repo_products1.clear();
}
